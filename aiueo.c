#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<time.h>
 
 
#define NROW 20
#define NCOL 15
 
 
typedef struct
{
    char xpiece;
    char ypiece;
}piece;
 
 
void tetris_gameboard(piece p[NROW][NCOL])
{
    int x, y;
  
    for(x = -1; x <= NROW; x++)
    {
        for(y = -1;  y<= NCOL; y++)
        { 
            if(x == -1 || x == NROW || y == -1 || y == NCOL)
            {    
                putchar('*');               
                putchar(' ');
            }
            else
            {
                if (p[x][y].xpiece=='X')
                putchar(p[x][y].xpiece);
                else if (p[x][y].ypiece=='X')
                putchar(p[x][y].ypiece);
                else
                putchar(p[x][y].xpiece);                  
                putchar(' ');
            }
        }
   
        putchar('\n'); 
    }
}
 
 
void instruction()
{
 
 
    printf("\n*Menu:\n");
    printf("*Press 6 to move right\n");
    printf("*Press 4 to move left\n");
    printf("*Press 2 to move down\n");
    printf("*Press 0 to quit\n");
     
}
 
 
void assignboard(piece p[NROW][NCOL])
{
    int i;
    int j;
    srand((unsigned) time (NULL));
     
    for(j=5; j<8; j++)
    {
        p[0][j].xpiece = rand()%2;
        if (p[0][j].xpiece == 1)
        {
            p[0][j].xpiece = 'X';
        }
    }
     
    printf("\n");
     
    for(j=5; j<8; j++)
    {
        p[1][j].xpiece = rand()%2;
        if (p[1][j].xpiece == 1)
        {
            p[1][j].xpiece = 'X';
        }
    }
     
    p[1][6].xpiece = 'X';
    printf("\n");
         
    for(j=5; j<8; j++)
    {
        p[2][j].xpiece = rand()%2;
        if (p[2][j].xpiece == 1)
        {
            p[2][j].xpiece = 'X';
        }
    }
}
 
 
 /* movemnet for left, right, up and down)*/
void movement (piece p[NROW][NCOL])
{
    int row;
    int coloumn;
    char action;
     
    do
    {
         
        printf("\nPlease enter your next action:");
        fflush(stdin);
        scanf("%c" , &action);
        fflush(stdin);
         
        if (action == '2')
        {
            for(row=20; row>-1; row--)
                for(coloumn=15; coloumn>-1; coloumn--)
                 
                if( p[row][coloumn].xpiece == 'X')
                {
                    p[row+1][coloumn].xpiece = 'X';
                    p[row][coloumn].xpiece = ' ';
                } 
        }
         
        if (action == '4')
        {
            for(row=0; row<21;row++)
                for(coloumn=0; coloumn<16; coloumn++)
                 
                if(p[row][coloumn].xpiece == 'X')
                {
                    p[row][coloumn-1].xpiece = 'X';
                    p[row][coloumn].xpiece = ' ';
                }
        }
         
        if (action == '6')
        {
            for(row=20; row>-1;row--)
                for(coloumn=15; coloumn>-1; coloumn--)
                 
                if(p[row][coloumn].xpiece == 'X')
                {
                    p[row][coloumn+1].xpiece = 'X';
                    p[row][coloumn].xpiece = ' ';
                }
        }
          
    }while (action != '2' && action != '4' && action != '6');
}
 
 
void endgame()
{
 
 
    char answer;
     
    do
    {
    printf("\nDo you want to continue this game <case sensitive> (Y/N):");
    scanf("%c" ,&answer);
    fflush(stdin);
     
    if (answer == 'N')
    {
    exit (0);
    }
    }while (answer !='Y' && answer !='N');
 
 
}
 
 
int main(void)
{
    int x;
    int y;
    int c;
    int score;
    char answer;
 
 
    piece box[NROW][NCOL];
    bool end = false;
    char name[30];
 
 
 
 
     
    printf("*********************WELCOME**********************\n");
    printf("\n**************LIST OF PREVIOUS PLAYERS************\n\n");
 
 
 
 
    for(x=0; x<20; x++)
    {
        for(y=0; y<15; y++)
        {
            box[x][y].xpiece = ' ';
            box[x][y].ypiece = ' ';
        }
    }
     
    assignboard(box);    
     
    printf("\nTo exit this game, please press Ctrl + C\n");    
    printf("Please key in the player name: ");
    scanf("%s", name);
    printf("\n***Good Day , are you ready to start a new game....\n");
    printf("\nWish you all the best!\n");
    printf("\nLet's start!!!\n");
    instruction();
    do
    {
    tetris_gameboard(box);
    movement(box);
    endgame();
     
    }while (end == false);
     
 
 
 
 
return 0;
}
