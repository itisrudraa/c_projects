#include<stdio.h>
#include<stdlib.h>

//functions for use
void printboard(char []);
int wincheck(char []);
int main()
{
    char position[]={'0','1','2','3','4','5','6','7','8','9'}; // bord positions 
    char plr,plr1='X',plr2='O'; //players
    int pos, i, draw=0, entry=0, vi=1, plr_select;

    printf("welcome to the game\n The tic tac toe board is divided into 9 parts for user entry as shown below :\n");
    printboard(position);

    // choosing first player
    printf("select the first player\n1> X\t2> O\nEnter 1 or 2:");
    scanf("%d",&plr_select);
    if(plr_select==2)
    {
    plr1='O';
    plr2='X';
    }

    //game loop
    for(i=1;i<=9;i++)
    {
    if(i%2!=0)
    plr=plr1;
    else
    plr=plr2;
    printf("Player %c turn\n",plr);
    printf("Enter the position:");
    
    do{
    scanf("%d",&pos);
    if(pos<10&&pos>0)
    { 
        entry=1; vi=1;
        while(entry!=0){
        if(position[pos]!='X'&&position[pos]!='O') 
        {
        entry=0;
        position[pos]=plr;
        printboard(position);
        if(wincheck(position)){
        draw=1;
        break;
        }
        }
        else
        {
        printf("That position is already taken\nEnter the other position:");
        scanf("%d",&pos);
        }
        }
    }
    else
    {
        printf("Enter a valid position:\n");  
        vi=0;
    } }while(vi!=1);

   if(draw==1)
   break;
    }
    if(draw==0)
    printf("Match is draw"); 
    else 
    printf("\nGame Over\n");
    return 0;
}

// function to print board 
void printboard(char position[])
{
    printf(" %c | %c | %c \n",position[1],position[2],position[3]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",position[4],position[5],position[6]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",position[7],position[8],position[9]);
}

// function to check winner
int wincheck(char position[])
{
    if(position[1]==position[2] && position[2]==position[3]){
    printf("\nplayer %c is winner\n",position[1]);
    return 1;}
    else if(position[4]==position[5] && position[5]==position[6]){
    printf("\nplayer %c is winner\n",position[4]);
    return 1;}
    else if(position[7]==position[8] && position[8]==position[9]){
    printf("\nplayer %c is winner\n",position[7]);
    return 1;}
    else if(position[1]==position[5] && position[5]==position[9]){
    printf("\nplayer %c is winner\n",position[1]);
    return 1;}
    else if(position[3]==position[5] && position[5]==position[7]){
    printf("\nplayer %c is winner\n",position[3]);
    return 1;}
    else if(position[1]==position[4] && position[4]==position[7]){
    printf("\nplayer %c is winner\n",position[1]);
    return 1;}
    else if(position[2]==position[5] && position[5]==position[8]){
    printf("\nplayer %c is winner\n",position[2]);
    return 1;}
    else if(position[3]==position[6] && position[6]==position[9]){
    printf("\nplayer %c is winner\n",position[3]); 
    return 1;}
    else
    return 0;
}