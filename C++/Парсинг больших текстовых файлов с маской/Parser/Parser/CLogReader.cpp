// StringFile.cpp: implementation of the CStringFile class.

#include "CLogReader.h"
#include "afx.h"

using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// Constructor
CLogReader::CLogReader(int nBufSize)
{
	m_dwRead = nBufSize;
	m_nBufferSize = nBufSize;
	m_pBuffer = new BYTE[nBufSize];
	m_dwMasterIndex = 0;
	m_dwIndex = 0;
	m_dwLine = 0;
	firstFilter = '-';
	secondFilter = '-';
}

// ����������
CLogReader::~CLogReader()
{
	delete m_pBuffer;
}

bool CLogReader::Open(LPCTSTR szFile, CFileException *feError)
{
	CFileStatus		rStatus;
	if(!m_fFile.Open(szFile, CFile::modeRead| CFile::shareDenyWrite))
		return false;
	m_fFile.GetStatus(rStatus);
	m_nMaxSize = rStatus.m_size;
	return true;
}


void CLogReader::Close()
{
	m_fFile.Close();
	m_dwMasterIndex = 0;
	m_dwIndex = 0;
	m_dwLine = 0;
	firstFilter = '-';
	secondFilter = '-';
}


DWORD CLogReader::GetNextLine(CString &szLine)
{
	char	*szBuffer;
	DWORD	dwReturn;
	
	szBuffer = new char[m_nBufferSize];
	dwReturn = this->GetNextLine(szBuffer,m_nBufferSize);
	
	if(dwReturn != 0)
		szLine = szBuffer;
	else 
		szLine = "";	//Empty
	delete szBuffer;

	return dwReturn;
}

DWORD CLogReader::GetNextLine(LPSTR szLine, int iLineSize)
{
	BYTE	*chTemp;
	bool	bStop=false;
	int		nOut;

	chTemp = (LPBYTE) szLine;
	*chTemp = 0;
	nOut = 0;
	while(!bStop)
	{
		if(!m_dwLine || m_dwIndex==m_dwRead)
		{
			m_dwMasterIndex = m_fFile.Seek(0,CFile::current);
			m_dwRead=m_fFile.Read((LPVOID) m_pBuffer,m_nBufferSize);
			m_dwIndex = 0;
			if(m_dwRead == 0)
			{
				bStop = true; //Error during readfile or END-OF-FILE encountered
				if(nOut>0)
				{
					chTemp[nOut++] = (char) 0;
					return m_dwLine;	
				}
				else return m_dwLine = 0; //nix gelezen
			}
			else
			{
				if(m_dwRead != (DWORD) m_nBufferSize)
					bStop = true;	//END-OF-FILE
			}
		}
		for(;m_dwIndex < m_dwRead;m_dwIndex++)
		{
			if((nOut+1) == iLineSize)
			{
				m_dwLine++;
				return m_dwLine;
			}
			switch(m_pBuffer[m_dwIndex])
			{
				case 0x0d://End of Line encountered
				case 0x0a:
					if((m_dwIndex+1) < m_dwRead) // Check we're not on end of m_pBuffer ???
						if(m_pBuffer[m_dwIndex+1] == '\n' || m_pBuffer[m_dwIndex+1] == '\r')
						{
							if(!*chTemp)
								m_dwLine++;
							m_dwIndex++;
						}
					if(*chTemp)
					{
						chTemp[nOut++] = '\0';
						m_dwLine++;
						return m_dwLine;
					}
					break;
				default: chTemp[nOut++] = m_pBuffer[m_dwIndex];
			}
		}
	}
	if(nOut>0)
	{
		chTemp[nOut++] = '\0';
		return m_dwLine;	
	}
	return m_dwLine = 0; //nix gelezen
}

// ���������
// ���������� �����: abc, *abc, ?abc, abc*, abc?, *abc*, ?abc?, *abc?, ?abc*. 
// ������ ���������� �������� ����� ���� ��������� �����
// ������ ���� abc???? - ��������, ��� ������ ���� �������� ������, ������������ � abc � ���������������� ����� �������������� ��������(������� �������������)
bool CLogReader::SetFilter(CString filter)
{
	filterBody = "";
	int length = filter.GetLength();

	int i = 0;
	
		// Getting of first symbol
		// first part
		if (filter[i] && filter[i] == '*')
		{
			firstFilter = '*';
			// body of filter
			while (filter[i] && filter[i] == '*')
				i++;
		}
		else if (filter[i] && filter[i] == '?')
		{
			firstFilter = '?';
			while (filter[i] && filter[i] == '?')
				i++;
		}
		
		if (i >= length)
			return false;

		// main body
		if (filter[i] && filter[i] != '*' && filter[i] != '?')
		{
			while (filter[i] && filter[i] != '*' && filter[i] != '?')
			{
				filterBody += filter[i];
				i++;
			}
		}


		// second part
		if(filter[i] && filter[i] == '*')
		{
			secondFilter = '*';
			while (filter[i] && filter[i] == '*')
				i++;
		}
		else if (filter[i] && filter[i] == '?')
		{
			secondFilter = '?';
			while (filter[i] && filter[i] == '?')
				i++;
		}

		if (i < length)
			return false;
		
		return true;
}

// ������, ��� * - ����� ������������������ ��������(������ �� ������ ������������������)
// ������, ��� ? - ���� ���������� ������
// ��� ���� ������������ * === ***..** � ? === ?????..?
bool CLogReader::FilterLine(CString szLine)
{
	int i = 0;
	int length = szLine.GetLength();

	// ���� ������ ������ ���������� � ��������� �������:
	if (firstFilter == '-')
	{
		// ���������� �� ������ ������ � ��������� �����?
		while (szLine[i] && filterBody[i] && filterBody[i]==szLine[i])
		{
			i++;
		}

		// ���� ��� - ���������� ���
		if (i < filterBody.GetLength())
			return false;
		// �����, ���� ����� ���������, ��������� �� ������ ������(��� ������� � ���� �� ���� - �� ��� ���)
		else
		{
			return SubFilterLineFunction(szLine, i);
		}
	}
	// ���� ������� ���� ������������ ���������� ��������
	else if (firstFilter=='*')
	{
		// mark as cicle
		L1:
		// ���� ��������� ������ �����
		int j = 0;
		while (szLine[i] && filterBody[j] && szLine[i] != filterBody[j])
		{
			i++;
		}

		// ���� �� ���-�� ������� ������ ����� ���� ����� - �� ��������� ���
		if (i < szLine.GetLength())
		{
			// ���������, ���� ���������
			while (szLine[i] && filterBody[j] && szLine[i] == filterBody[j])
			{
				i++; 
				j++;
			}
			// ���� ��������� ������� ���� �����, �� ���������, ����� - ���� �� �����
			if (!filterBody[j])
			{
				return SubFilterLineFunction(szLine, i);
			}
			else
			{
				// WARNING!
				// ��-�������� ���� ���� ����� ��������, �� ��� "�����" ��� �� ������.
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
		while (szLine[i] && filterBody[j] && szLine[i] == filterBody[j])
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


bool CLogReader::SubFilterLineFunction(CString szLine, int i)
{
	// ���� ��� ������� - ������ ������  ��������� �� �����
	if (secondFilter == '-')
	{
		// �������� �� "abc", �� ����������
		if (!szLine[i])
			return true;
		else
			return false;
	}
	// abc ���� �������� ��� ������� abc****
	else if (secondFilter == '*')
	{
		return true;
	}
	// �������� �� ��������� ������ ����� ������������ �����
	else if (secondFilter == '?')
	{
		if (i + 1 == szLine.GetLength())
			return true;
		else
			return false;
	}
	else
	{
		return true;
	}
}