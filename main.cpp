#include <iostream>
#include <time.h>

using namespace std;

const int rozmiar = 50; // 825 max ale i tak moze nie zadzialac; zalezy tez od wypelnienia

int generate_random_number (int limit)
{
    int randomNumber = rand();
    return randomNumber % limit;
}

void clear_array (char status[rozmiar][rozmiar], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            status[i][j] = ' ';
        }
    }
}
//!!
void mark_status (char status[rozmiar][rozmiar], char mapa[rozmiar][rozmiar], int rozmiar, int row, int column)
{

}

void generate_map (char mapa[rozmiar][rozmiar], int pokrycie, int rozmiar)
{
    clear_array(mapa, rozmiar);

    for (int i = 0; i < pokrycie; i++)
    {
        int x = generate_random_number(rozmiar);
        int y = generate_random_number(rozmiar);
        mapa [x][y] = 'X';
    }
}

void display_array (char mapa[rozmiar][rozmiar], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

int has_exit (char mapa[rozmiar][rozmiar], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
       if (mapa[rozmiar - 1][i] == 'X')
        {
            return 1;
        }
    }

    return 0;
}

void fill_map_with_preplanned(char mapa[rozmiar][rozmiar])
{
/*
    X X XXXXXX
     X  X  XXX
    X X X XX
      XXX  X X
         X XXX
    XXX   X XX
    XXX     X
    XXXXXX  X
          XXXX
    XXX      X
*/
    string preplanned = "X X XXXXXX X  X  XXXX X X XX    XXX  X X     X XXXXXX   X XXXXX     X XXXXXX  X       XXXXXXX      X";
    int preplanned_size = 10;

    for (int i = 0; i < preplanned_size; i++)
    {
        for (int j = 0; j < preplanned_size; j++)
        {
            mapa[i][j] = preplanned[i * preplanned_size + j];
        }
    }
}

int main()
{
    srand(time(NULL));
    float wypelnienie = 0.85;
    char mapa[rozmiar][rozmiar];
    char status [rozmiar][rozmiar];

    while (1)
    {
        clear_array(mapa, rozmiar);
        clear_array(status, rozmiar);
        generate_map(mapa, rozmiar * rozmiar * wypelnienie, rozmiar);
        mark_status(status, mapa, rozmiar, -1, -1); //!!
        if (has_exit(status, rozmiar))
        {
            break;
        }
    }

    display_array(mapa, rozmiar);
    cout << "--------------------------------------------------" << endl;
    display_array(status, rozmiar);

    return 0;
}
