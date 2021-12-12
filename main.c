#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

//Let there be globals

//1 = black, 2 = white.
unsigned int Board[8][8] =
{
    {1,2,1,2,1,2,1,2},
    {2,1,2,1,2,1,2,1},
    {1,2,1,2,1,2,1,2},
    {2,1,2,1,2,1,2,1},
    {1,2,1,2,1,2,1,2},
    {2,1,2,1,2,1,2,1},
    {1,2,1,2,1,2,1,2},
    {2,1,2,1,2,1,2,1}
};

const char* BoardColor[8][8] =
{
    {"black", "white", "black", "white", "black", "white", "black", "white"},
    {"white", "black", "white", "black", "white", "black", "white", "black"},
    {"black", "white", "black", "white", "black", "white", "black", "white"},
    {"white", "black", "white", "black", "white", "black", "white", "black"},
    {"black", "white", "black", "white", "black", "white", "black", "white"},
    {"white", "black", "white", "black", "white", "black", "white", "black"},
    {"black", "white", "black", "white", "black", "white", "black", "white"},
    {"white", "black", "white", "black", "white", "black", "white", "black"}
};

char FileLetter[] = "ABCDEFGH";
char RankNumber[] = "12345678";
char GeneratedSquare[2] = "A1";
int File;
int Rank;
int ColorGuessed;

void Generate_Coordinate(unsigned int level)
{
    //generate number from 0 to level-1
    File = rand() % level;
    Rank = rand() % level;

    GeneratedSquare[0] = FileLetter[File];
    GeneratedSquare[1] = RankNumber[Rank];
}


int main()
{
    unsigned int Level = 1;
    printf("Enter a number (1 to 8) representing the first N files and ranks to memorize: ");
    scanf("%d", &Level);
    getchar();
    if(Level < 1)
        { Level = 1; }
    else if(Level > 8)
    { Level = 8; }

    printf("\nNumber of files and ranks chosen: %d. To choose a color: black = 1, white = 2).\n", Level);

    srand(time(0));
    while(1)
    {
        Generate_Coordinate(Level);

        printf("\nWhat color is square %s?: \n",   GeneratedSquare);
        scanf("%d", &ColorGuessed);
        getchar();
        if(Board[File][Rank] == ColorGuessed)
        {
            printf("Correct.\n");
            Beep(440, 100);
        } else
        {
            printf("Wrong. %s is %s.\n", GeneratedSquare, BoardColor[File][Rank]);
            Beep(880, 100); Beep(880, 100); Sleep(2000);
        }

        system("@cls||clear");
    }

    return 0;
}
