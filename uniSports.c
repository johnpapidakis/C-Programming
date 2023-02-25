#include <stdio.h>
#include <string.h>
struct match
{
    char team1[20];
    int score1;
    char team2[20];
    int score2;
};


int main()
{
    
    int HW, HD, HL, AW, AD, AL, GF, GA, GD, PTs=0;
   
    struct match matchArray[10];
    
    
    
    
    for(int i = 0; i<10; i++)
    {
        scanf("%s %d %s %d",matchArray[i].team1, &matchArray[i].score1, matchArray[i].team2, &matchArray[i].score2);

        printf("%s %d %s %d\n", matchArray[i].team1, matchArray[i].score1, matchArray[i].team2, matchArray[i].score2);

        if (strcmp(matchArray[i].team1,"QMUL"))
        {
            if (matchArray[i].score1>matchArray[i].score2)
            {
                HW = HW + 1;
                
            }
            else if (matchArray[i].score1<matchArray[i].score2)
            {
                HL = HL +1;
                
            }
            else if (matchArray[i].score1 == matchArray[i].score2)
            {
                HD = HD +1;
            }
            GF = GF + matchArray[i].score1;
            GA = GA + matchArray[i].score2;
        }
        else if (strcmp(matchArray[i].team2,"QMUL"))
        {
            if (matchArray[i].score1<matchArray[i].score2)
            {
                AW = AW + 1;
            }
            else if (matchArray[i].score1>matchArray[i].score2)
            {
                AL = AL +1;
            }
            else if (matchArray[i].score1 == matchArray[i].score2)
            {
                AD = AD +1;
            }
            GF = GF + matchArray[i].score2;
            GA = GA + matchArray[i].score1;

        }
        
    }
    GD = GF - GA;
    PTs = 4*(HW + AW) + (HW + AW);
    printf("      Home    Away\n"); 
    printf("      W D L   W D L   GF   GA   GD   PTs\n");  
    printf("QMUL  %d %d %d   %d %d %d   %d   %d   %d   %d",HW,HD,HL,AW,AD,AL,GF,GA,GD,PTs);   

    return 0;
}





