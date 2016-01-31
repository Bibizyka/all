#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>

#include <time.h>

using namespace std;
SDL_Surface* buttons;

enum {Trash = -10,      //������� ���� ����, ����� ����� ���� ������
        WrongTurn = -4,
        NonChecked = -3,
        Mine = -1,
        Closed = 1,
        Opened = 0,
        Marked = 2,
        Defeat = 0,
        RightTurn = 1,
        Victory = 2,
        EasyLevel = 1,
        MediumLevel = 2,
        HardLevel = 3};

class Field //����� ����
{
    SDL_Surface* Texture; //�������� � ��������
    int Number_of_cells; //���������� ������
    int** CellValue; //������� �� ���������� ������ (�����, ������� ���� ������)
    int** CellStatus; //������� ��������� ������ (�������, �������, ��������)
    int Number_of_mines; //���������� ���
    int Length_of_cell; //����� ������ � ��������
    int Number_of_flags; //���������� ������
    int Number_of_closed; //���������� �������� ������
    bool First_turn; //����������, ���������� �� ��, ������� �� �� ��� ������ ���

    int getValue(int x, int y) //������� ��������� �������� CellValue �� ��������� �������� (� ��������� �������� �� �� ������ � ������� CellValue)
    {
        if( x >= 0 && x < Number_of_cells)
        {
            if(y >= 0 && y < Number_of_cells)
            {
                return CellValue[x][y];
            }
        }
        return Trash; //���������� �����, ���� ������� �� �����
    }

    int isMine(int x, int y) //���������� �������, ���� � ������ � ���������� ��������� ����� ���� � 0 - �����
    {
        return getValue(x,y) == -1 ? 1 : 0;
    }

    void create(int x0, int y0) //������� ���������� ������� CellValue (�0,�0 - ���������� ������� �������)
    {
        srand(time(NULL)); //��� ����� ��� ����, ����� rand() ������� ������ ��������

        for(int k = 0; k < Number_of_mines; k++) //����������� ����
        {
            int x = rand()%(Number_of_cells); //�������� ��������� ����������
            int y = rand()%(Number_of_cells);

            if(CellValue[x][y] == Trash && (x != x0 || y != y0)) CellValue[x][y] = Mine; //���� �� ������ � ���� ��� � ��� �������� ������ - ������ ����
            else k--;
        }

        for(int i = 0; i < Number_of_cells; i++) //��������� ��������� ������
        {
            for(int j = 0; j < Number_of_cells; j++)
            {
                if(CellValue[i][j] != Mine) //���� � ������ �� ���� - ������������ ����� ��� ������
                {
                    CellValue[i][j] = 0;

                    for(int k = 0; k < 9; k++)
                        CellValue[i][j] += isMine(i - 1 + k / 3, j - 1 + k % 3);

                    if(CellValue[i][j] == 0)
                        CellValue[i][j] = NonChecked; //���� ��� ������ ��� - ������ NonChecked (����� ����� ��� ������ �������)
                }
            }
        }
    }

public:

    Field(int num_of_cells, int length, int num_of_mines, SDL_Surface* bitmap) //����������� � �����������
    {
        Texture = bitmap;

        Number_of_cells = num_of_cells;

        CellValue = new int*[Number_of_cells]; //������� ������������ ������� CellValue � CellStatus
        for(int i = 0; i < Number_of_cells; i++)
            CellValue[i] = new int[Number_of_cells];

        CellStatus = new int*[Number_of_cells];
        for(int i = 0; i < Number_of_cells; i++)
            CellStatus[i] = new int[Number_of_cells];

        First_turn = false; //��������� ��������� ����
        Number_of_closed = Number_of_cells * Number_of_cells;
        Length_of_cell = length;
        Number_of_mines = num_of_mines;
        Number_of_flags = Number_of_mines;
        for(int i = 0; i < Number_of_cells; i++) //�������� ������ Trash, ����� create() �������� ���������
        {
            for(int j = 0; j < Number_of_cells; j++)
            {
              CellStatus[i][j] = Closed;
              CellValue[i][j] = Trash;
            }
        }
    }

    ~Field() //����������
    {
        for(int i = 0; i < Number_of_cells; i++) //������� ��� �������
        {
            delete[] CellValue[i];
            delete[] CellStatus[i];
        }
        delete[] CellValue;
        delete[] CellStatus;
    }
    void drawCell (int x, int y, SDL_Surface* screen) //��������� �������� ������
    {
        if(CellStatus[x][y] == Marked)  //���� ���� �������� - ������� ����
            Number_of_flags++;

        if(CellStatus[x][y] != Opened) //���� ���� ������� �� ����� - ��������� Number_of_closed
            Number_of_closed--;

        CellStatus[x][y] = Opened; //��������� ������

        if(CellValue[x][y] == NonChecked) //���� ������ NonChecked - ���� � ��������� NonChecked ������ ������
        {

            CellValue[x][y] = 0; //���������� � ������ 0 (����� ������ �� �� ���������)

            for(int i = 0; i < 9; i++) //���� ������ ������ ������
            {
                if(getValue(x - 1 + i / 3,y - 1 + i % 3) != Trash) //���� ����� ���� ������ - �������� ��� ��� drawCell()
                    drawCell(x - 1 + i / 3,y - 1 + i % 3,screen);
            }
        }
        drawFigure(x,y,CellValue[x][y],screen); //������ ������

    }
    void drawFigure(int x, int y, int n, SDL_Surface* screen) //���� ��������� ������ � ������� ������� �� ��������
    {
        SDL_Rect* cell = new SDL_Rect(); //���������� ��� �������� �� ������
                        cell->x = 10 + x * Length_of_cell;
                        cell->y = 10 + y * Length_of_cell;

        SDL_Rect* working_area = new SDL_Rect(); //������������� � �������� �� �������� (���� ������ ������ ����� � ������
                        working_area->w = 10 * (Length_of_cell / 11);
                        working_area->h = 10 * (Length_of_cell / 11);
        if(n > 0) //��������� � ����� ���� � �������� ���� ������ �������
        {
            working_area->x = (n-1)*10 * (Length_of_cell / 11);
            working_area->y = 0;
            SDL_BlitSurface(Texture, working_area, screen, cell); //������ �� ������
        }
        else
        {
            working_area->x = -n * 10 * (Length_of_cell / 11);
            working_area->y = 10 * (Length_of_cell / 11);
            SDL_BlitSurface(Texture, working_area, screen, cell);
        }
    }

    void draw(SDL_Surface* screen) //��������� ����� ����
    {
        for(int i = 0; i < Number_of_cells; i++)
        {
            for(int j = 0; j < Number_of_cells; j++)
            {
                if(CellStatus[i][j] == Opened) //���� ������ �������
                {
                    drawCell(i,j,screen);
                }
                else
                {
                    drawFigure(i,j,-(CellStatus[i][j] + 1),screen);
                }
            }
        }

    }

    int turn(int xCursor, int yCursor, Uint8 button) //��� (��������� - ���������� ������� � �������� ������� ����
    {
        int x = (xCursor - 10) / Length_of_cell; //���������� � ����� ������ �� ������
        int y = (yCursor - 10) / Length_of_cell;

        if(button == SDL_BUTTON_LEFT) //���� ������ ����� ������ ����
        {
            if(CellStatus[x][y] == Opened) return RightTurn; //���� ��� ��� ������� - ������ �� ������

            if(!First_turn) //���� ������ � ������ ���
            {
                First_turn = true;
                create(x,y); //���������� ����
            }

            if(CellStatus[x][y] == Marked) //���� ��� ���� ��������
                Number_of_flags++; //������� ����

            CellStatus[x][y] = Opened; //��������� ������

            if(CellValue[x][y] == Mine) //���� "���������" �� ����
            {
                CellValue[x][y] = WrongTurn; //������ �������������� �������� (����� ���������������� ������ �����������)

                for(int i = 0; i < Number_of_cells; i++) //��������� ��� ����, ����� ���� �����
                    for(int j = 0; j < Number_of_cells; j++)
                        if(CellValue[i][j] == Mine)
                                CellStatus[i][j] = Opened;
                return Defeat; //���������� ��������� � ���������
            }

            Number_of_closed--; //��������� ������� �������� ������

            if(Number_of_closed == Number_of_mines) //���� ������� ����� ����
                for(int i = 0; i < Number_of_cells; i++) //��������� ��� ������
                    for(int j = 0; j < Number_of_cells; j++)
                        CellStatus[i][j] = Opened;
        }
        if(button == SDL_BUTTON_RIGHT) //���� ������ �� ������ ������ ����
        {
            if(CellStatus[x][y] == Opened) return RightTurn; //���� ������ ��� ������� - ������ �� ������
            if(CellStatus[x][y] == Closed && Number_of_flags > 0) //���� ������� � ��� �������� ����� - �������� � ��������� ����� ��������� ������
            {
                CellStatus[x][y] = Marked;
                Number_of_flags--;
            }
            else
                if(CellStatus[x][y] == Marked) //���� ��� ��������
                {
                    CellStatus[x][y] = Closed; //������� �������
                    Number_of_flags++; //����������� ����� ��������� ������
                }
        }
        if(button == SDL_BUTTON_MIDDLE) //���� ������� ������ ����
        {
            if(CellStatus[x][y] != Opened) return RightTurn; //���� ������ ������� - ������ �� ������

            int num_of_flags = 0; //����� ������ ������ ����� ������

            for(int i = 0; i < 9; i++)
            {
                if(getValue(x-1 + i/3,y-1 + i%3) != Trash && CellStatus[x-1 + i/3][y-1 + i%3] == Marked) //���� ����� ���� ������ - � ��� �������� ������ - ����������� �������
                    num_of_flags ++;
            }
            int res = 1; //�������� �� ��, ��� �� ��� ����� ��������� ���������
            if(num_of_flags == getValue(x,y)) //���� ����� ������ ������ ��������� � ������ ���
            {
                for(int i = 0; i < 9; i++)
                {
                    int value = getValue(x-1 + i/3,y-1 + i%3);
                    if(value != Trash && CellStatus[x-1 + i/3][y-1 + i%3] == 1) //��������� ��� ������������ ������ ������
                    {
                        res *= turn((x - 1 + i / 3) * Length_of_cell + 10, (y - 1 + i % 3) * Length_of_cell + 10, SDL_BUTTON_LEFT); //���� "��������" �� ����, �� res ������ ������ 0
                    }
                }
            }
            if(res == 0) //���� "���������" �� ���� - ���������� ��������� �� ������
                return Defeat;
        }
        if(Number_of_closed == Number_of_mines) //���� ������� ��� ������ - �������� ��������� � ������, ����� - � ���, ��� ��� ��� ��������
                return Victory;
            else
                return RightTurn;
    }

};


class lvlButton //����� ��� ������ ������ ������
{
    SDL_Surface* Texture; //�������� ����
    int LVL; //������� ���������
    int Number_of_mines; //���������� ���
    int Number_of_cells; //���������� ������ � ����
    int Length_of_cell; //����� ����� ������ � ��������
    SDL_Rect* working_area; //������������� ��� ��������� ������ ������� �� ��������
public:
    SDL_Rect* Position; //���������� ����� ������
    lvlButton(int lvl, SDL_Rect* pos) //����������� � �����������
    {
        LVL = lvl;
        Position = new SDL_Rect(*pos);
        working_area = new SDL_Rect();
        working_area->y = 0;
        working_area->x = (LVL-1) * 100;
        working_area->h = 100;
        working_area->w = 100;
        switch (LVL) //��������� ����� ������� ��������� � � ����������� �� ����� �������� ��������, ���������� ���, ������ � ������ ������
        {
            case EasyLevel:
                {
                    Texture = SDL_LoadBMP("figuresEasy.bmp");
                    Number_of_cells = 9;
                    Length_of_cell = 55;
                    Number_of_mines = 10;
                }
                break;
            case MediumLevel:
                {
                    Texture = SDL_LoadBMP("figuresMedium.bmp");
                    Number_of_cells = 11;
                    Length_of_cell = 45;
                    Number_of_mines = 25;
                }
                break;
            case HardLevel:
                {
                    Texture = SDL_LoadBMP("figuresHard.bmp");
                    Number_of_cells = 15;
                    Length_of_cell = 33;
                    Number_of_mines = 50;
                }
                break;
        }
    }
    ~lvlButton()
    {
        SDL_FreeSurface(Texture);
    }
    void press(Field* &F) //���������� ������� �� ������
    {
        if(F != NULL) //���� ���� ���� �� ����� - �������
            delete F;
        F = new Field(Number_of_cells, Length_of_cell, Number_of_mines, Texture); //������� ����� ����
    }
    void draw(SDL_Surface* screen) //���������� ������
    {
        SDL_BlitSurface(buttons, working_area, screen, Position);
    }
};



int main ( int argc, char** argv )
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        return 1;
    atexit(SDL_Quit);

    SDL_Surface* screen = SDL_SetVideoMode(630, 515, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF); //������� ����
    if ( !screen )
        return 1;

    buttons = SDL_LoadBMP("buttons.bmp"); //��������� �������� � �������� + ����������� � ������/���������

    SDL_Rect dstrect; //������� ���������� ������� ����

    Field* F = NULL; //���� ����
    SDL_Rect* Position = new SDL_Rect; //���������� ������
        Position->x = 515;
        Position->y = 10;
    lvlButton* Easy = new lvlButton(EasyLevel,Position); //������ �������� ������ ���������
        Position->x = 515;
        Position->y = 120;
    lvlButton* Medium = new lvlButton(MediumLevel,Position); //������ �������� ������ ���������
        Position->x = 515;
        Position->y = 230;
    lvlButton* Hard = new lvlButton(HardLevel,Position); //������ �������� ������ ���������

    SDL_Rect* message = new SDL_Rect(); //������������� ��� ��������� ��������� � ������/��������� �� ����� ��������
        message->h = 100;
        message->w = 200;

    Position->x = 150; //���������� ��������� � ������/���������
    Position->y = 200;

    Easy->press(F); //������� ����

    int result = RightTurn; //���������� ��� �������� ���������� ����


    bool done = false; //���������� ��� ������ ����� ���������

    while ( !done )
    {
        dstrect.x = 0; //�������� ���������� �������
        dstrect.y = 0;
        Uint8 btn; //���������� ��� �������� ����, ����� ������ ���� �� ������

        SDL_Event event; //���������� ��� �������

        while (SDL_PollEvent(&event)) //������������ �������
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = true;
                break;

            case SDL_KEYDOWN: //���� ������ �����-�� ������� �� ����������
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE) //���� ������ ESCAPE - ��������� ����������
                        done = true;
                    break;
                }

            case SDL_MOUSEBUTTONDOWN: //���� ������ ������ ����
                {
                    dstrect.x = event.button.x; //�������� ���������� �������
                    dstrect.y = event.button.y;

                    btn = event.button.button;

                    if(dstrect.x > 10 && dstrect.x < 500 && dstrect.y  > 10 && dstrect.y <500 &&  result == RightTurn) //��������� ������ �� �� � ���� � ����� �� ��� ������
                    {
                        result = F->turn(dstrect.x, dstrect.y, btn); //�����
                    }
                    else
                    {
                        if(dstrect.x > 515 && dstrect.x < 615 && dstrect.y  > 10 && dstrect.y <110) //���������, ������ �� � ������ Easy
                        {
                            result = RightTurn; //��������� ������
                            Easy->press(F); //������� ����� ���� � ������ ������� ���������
                        }
                        if(dstrect.x > 515 && dstrect.x < 615 && dstrect.y  > 110 && dstrect.y <230) //���������, ������ �� � ������ Medium
                        {
                            result = RightTurn;
                            Medium->press(F); //������� ����� ���� �� ������� ������� ���������
                        }
                        if(dstrect.x > 515 && dstrect.x < 615 && dstrect.y  > 230 && dstrect.y <340) //���������, ������ �� � ������ Hard
                        {
                            result = RightTurn;
                            Hard->press(F); //������� ����� ���� � ������� ������� ���������
                        }
                    }
                    break;
                }
            }
        }

        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255)); //����������� ����

        Easy->draw(screen); //������ ������
        Medium->draw(screen);
        Hard->draw(screen);
        F->draw(screen); //������ ����

        if(result != RightTurn) //��������� �� �������� �� �� ��� ���������
            if(result == Defeat) //���� ���������
            {
                message->y = 0;
                message->x = 500; //�������� ������� ��� ��������� � ���������
                SDL_BlitSurface(buttons, message, screen, Position); //������ ���������
            }
            else
            {
                message->y = 0;
                message->x = 300; //�������� ������� ��� ��������� � ������
                SDL_BlitSurface(buttons, message, screen, Position);//������ ���������
            }

        SDL_Flip(screen); //��������� �����
    }

    SDL_FreeSurface(buttons);
    SDL_Quit();
    return 0;
}
