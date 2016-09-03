#include "CLogReader.h"

CLogReader::CLogReader(int nBufSize)
{
	m_dwRead = nBufSize;
	m_nBufferSize = nBufSize;
	m_pBuffer = new char[nBufSize];
	m_dwIndex = 0;
	m_dwLine = 0;

	firstFilter = '-';
	secondFilter = '-';
}

CLogReader::~CLogReader()
{
	delete m_pBuffer;
	delete szLine;
}

bool CLogReader::Open(char* szFile)
{
	m_fFile.open(szFile);

	if (!m_fFile.is_open())
	{
		return false;
	}
		
	return true;
}


void CLogReader::Close()
{
	m_fFile.close();
	m_dwIndex = 0;
	m_dwLine = 0;
	firstFilter = '-';
	secondFilter = '-';
}

int CLogReader::GetNextLine()
{
	int iLineSize = m_nBufferSize;

	szLine = new char[ iLineSize];

	bool	bStop = false;

	nOut = 0;
	
	while(!bStop)
	{
		if(!m_dwLine || m_dwIndex==m_dwRead)
		{
			m_fFile.seekg(0, m_fFile._Seekcur);
			m_fFile.read(m_pBuffer,m_nBufferSize);//read			
			m_dwRead= m_fFile.gcount();
			

			m_dwIndex = 0;
			if(m_dwRead == 0)
			{
				bStop = true; 
				if(nOut>0)
				{
					szLine[nOut++] = (char) 0;
					return m_dwLine;	
				}
				else return m_dwLine = 0; 
			}
			else
			{
				if(m_dwRead != (int) m_nBufferSize)
					bStop = true;	//END-OF-FILE
			}
		}
		for(;m_dwIndex < m_dwRead; m_dwIndex++)
		{
			if((nOut+1) == iLineSize)
			{
				m_dwLine++;
				return m_dwLine;
			}
			switch(m_pBuffer[m_dwIndex])
			{
				case 0x0d://End of Line 
				case 0x0a:
					if((m_dwIndex+1) < m_dwRead) // Check we're not on end of m_pBuffer
						if(m_pBuffer[m_dwIndex+1] == '\n' || m_pBuffer[m_dwIndex+1] == '\r')
						{
							if (nOut == 0)
								m_dwLine++;
							m_dwIndex++;
						}
					if (nOut != 0)
					{
						szLine[nOut++] = '\0';
						m_dwLine++;

						return m_dwLine;
					}
					break;
				default: szLine[nOut++] = m_pBuffer[m_dwIndex];
			}
			//szLine[nOut++] = m_pBuffer[m_dwIndex];
		}
	}
	if(nOut>0)
	{
		szLine[nOut++] = '\0';
		return m_dwLine;	
	}
	return m_dwLine = 0; //nix gelezen
}

// ���������
// ���������� �����: abc, *abc, ?abc, abc*, abc?, *abc*, ?abc?, *abc?, ?abc*. 
// ������ ���������� �������� ����� ���� ��������� �����
// ������ ���� abc???? - ��������, ��� ������ ���� �������� ������, ������������ � abc � ���������������� ����� �������������� ��������(������� �������������)
bool CLogReader::SetFilter(char* filter)
{
	filterBody = "";

	int i = 0;
	
		// Getting of first symbol
		// first part
		if ( filter[ i] && filter[ i] == '*')
		{
			firstFilter = '*';
			// body of filter
			while ( filter[ i] && filter[ i] == '*')
				i++;
		}
		else if ( filter[ i] && filter[ i] == '?')
		{
			firstFilter = '?';
			while ( filter[ i] && filter[ i] == '?')
				i++;
		}
		
		if ( i >= strlen(filter))
			return false;

		// main body
		if ( filter[ i] && filter[ i] != '*' && filter[ i] != '?')
		{
			while ( filter[ i] && filter[ i] != '*' && filter[ i] != '?')
			{
				filterBody += filter[ i];
				i++;
			}
		}
		
		// second part
		if( filter[ i] && filter[ i] == '*')
		{
			secondFilter = '*';

			while ( filter[ i] && filter[ i] == '*')
				i++;
		}
		else if ( filter[ i] && filter[ i] == '?')
		{
			secondFilter = '?';

			while ( filter[ i] && filter[ i] == '?')
				i++;
		}

		if ( i < nOut)
			return false;
		
		return true;
}

// ������, ��� * - ����� ������������������ ��������(������ �� ������ ������������������)
// ������, ��� ? - ���� ���������� ������
// ��� ���� ������������ * === ***..** � ? === ?????..?
bool CLogReader::FilterLine()
{
	int i = 0;

	// ���� ������ ������ ���������� � ��������� �������:
	if ( firstFilter == '-')
	{
		// ���������� �� ������ ������ � ��������� �����?
		while ( szLine[ i] && filterBody[ i] && filterBody[ i]==szLine[ i])
		{
			i++;
		}

		// ���� ��� - ���������� ���
		if ( i < strlen(filterBody))
			return false;
		// �����, ���� ����� ���������, ��������� �� ������ ������(��� ������� � ���� �� ���� - �� ��� ���)
		else
		{
			return SubFilterLineFunction( szLine, i);
		}
	}
	// ���� ������� ���� ������������ ���������� ��������
	else if ( firstFilter=='*')
	{
		// as cicle

		L1:
		// ���� ��������� ������ �����
		int j = 0;
		while ( szLine[ i] && filterBody[j] && szLine[ i] != filterBody[j])
		{
			i++;
		}

		// ���� �� ���-�� ������� ������ ����� ���� ����� - �� ��������� ���
		if ( i < nOut)
		{
			// ���������, ���� ���������
			while (  szLine[ i] && filterBody[j] && szLine[ i] == filterBody[j])
			{
				i++; 
				j++;
			}
			// ���� ��������� ������� ���� �����, �� ���������, ����� - ���� �� �����
			if ( !filterBody[j])
			{
				return SubFilterLineFunction(szLine, i);
			}
			else
			{
				// WARNING!
				// ��-�������� ���� ���� ����� ��������, �� ��� ����� ��� �� ������.
				goto L1;
			}
		}
		else
		{
			return false;
		}
	}
	// ���� ������� ���� ���� ����� ������
	else if(firstFilter='?')
	{
		// �������� ���������� �� ������� �������
		i++;
		
		int j = 0;
		// ��������� �����, ������� ������ ���������� � ������
		// ���� �� ��������� - �� ��������, �� ������ �� ��������
		while (szLine[ i] && filterBody[j] && szLine[ i] == filterBody[j])
		{
			i++;
			j++;
		}

		// ���� �� ����� �� ����� ���� ������� - �� ���
		if (!filterBody[j])
		{
			return SubFilterLineFunction(szLine, i);
		}
		else
		{
			return false;
		}
	}
	
	return true;
}


bool CLogReader::SubFilterLineFunction(char* szLine, int i)
{
	// ���� ��� ������� - ������ ������  ��������� �� �����
	if ( secondFilter == '-')
	{
		// �������� �� "abc", �� ����������
		if ( !szLine[ i])
			return true;
		else
			return false;
	}
	// abc ���� �������� ��� ������� abc****
	else if ( secondFilter == '*')
	{
		return true;
	}
	// �������� �� ��������� ������ ����� ������������ �����
	else if ( secondFilter == '?')
	{
		if ( i + 1 == strlen( szLine))
			return true;
		else
			return false;
	}
	else
	{
		return true;
	}
}