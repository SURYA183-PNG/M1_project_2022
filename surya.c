#include<stdio.h>
#include<string.h>
char x,o;
char a[9]={'1','2','3','4','5','6','7','8','9'};
char u1[50],u2[50];
void board();
void rules();
int checkforwin();
int main()
{
    FILE *p;
    p=fopen("points.txt","a+");
    fclose(p);
    system("color 09");
    int contestant=1;
    int choice,score=-1;
    char sym,re;
    char start,dec;
    int c;
    rules();
    printf("\n\nType 1 to start the game:-\n");
    scanf("%d",&c);
    if(c==1)
    {
    read:
        p=fopen("points.txt","a+");
    printf("\nEnter name of player1: ");
    scanf("%s",u1);
    fprintf(p,"\n%s",u1);
    printf("Enter name of player2: ");
    scanf("%s",u2);
    fprintf(p,"\t%s",u2);
    fclose(p);
    if(!strcmp(u1,u2))
    {
        printf("Enter names of different players!\n\n");
        goto read;
    }
    else
        decision();


    system("color fc");
    board();

    do
    {

        contestant=((contestant%2)?1:2);
        if(contestant==1)
        printf("%s Type any digit from 1-9 to fill your response:- ",u1);
        else
            printf("%s Type any digit from 1-9 to fill your response:- ",u2);
        scanf("%d",&choice);
        sym=((contestant==1)?x:o);
        if(choice==1 && a[0]=='1')
            a[0]=sym;
        else if(choice==2 && a[1]=='2')
            a[1]=sym;
        else if(choice==3 && a[2]=='3')
            a[2]=sym;
        else if(choice==4 && a[3]=='4')
            a[3]=sym;
        else if(choice==5 && a[4]=='5')
            a[4]=sym;
        else if(choice==6 && a[5]=='6')
            a[5]=sym;
        else if(choice==7 && a[6]=='7')
            a[6]=sym;
        else if(choice==8 && a[7]=='8')
            a[7]=sym;
        else if(choice==9 && a[8]=='9')
            a[8]=sym;
        else
            {printf("Wrong Selection\n");contestant--;}

        score=checkforwin();
        contestant++;
        board();
    }while(score == -1);


    p=fopen("points.txt","a+");
    if(score==1)
    {

        if(contestant==2)
        {printf("\n\nContestant1 %s Wins!\n\n",u1);fprintf(p,"\t%s",u1);
        getch();}
        else
            {printf("\n\nContestant2 %s Wins!\n\n",u2);fprintf(p,"\t%s",u2);
        getch();
            }
        fclose(p);
    }
    else
        printf("\n\nGame Draws!\n\n");fprintf(p,"\t%s","DRAW");
        getch();
    }
}
int checkforwin()
{
    if(a[0]==a[1] && a[1]==a[2])
        return 1;
    else if(a[3]==a[4] && a[4]==a[5])
        return 1;
    else if(a[6]==a[7] && a[7]==a[8])
        return 1;
    else if(a[0]==a[3] && a[3]==a[6])
        return 1;
    else if(a[1]==a[4] && a[4]==a[7])
        return 1;
    else if(a[2]==a[5] && a[5]==a[8])
        return 1;
    else if(a[0]==a[4] && a[4]==a[8])
        return 1;
    else if(a[2]==a[4] && a[4]==a[6])
        return 1;
    else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
        return 0;
    else
        return -1;
}

void board()
{
    int i;

    system("cls");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n\n\n",u1,x,u2,o);

        printf("  %c |  %c | %c\n",a[0],a[1],a[2]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("    |    |    \n");
        printf("  %c |  %c | %c\n",a[3],a[4],a[5]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("  %c |  %c | %c\n",a[6],a[7],a[8]);
        printf("    |    |    \n");
    }
void rules()
{
    char link;
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications Type 'Y' else type any other character:- ");
    scanf("%c",&link);
    if(link=='y' || link=='Y')
    {
        printf("!!! You can Start the Game Now !!!");
    }

}
int decision()
{
    char dec;
        deci:
        printf("\n\nContestant1 %s choose the X or 0:",u1);
        dec=getchar();
        scanf("%c",&dec);
        {
            if(dec=='X' || dec=='x')
            {
                x='X';
                o='0';
            }
            else if(dec=='0')
            {
                x='0';
                o='X';
            }
            else
            {
                printf("Please enter either X or 0 only \n\n");
                goto deci;
            }
        }
}
