#include <stdio.h>
#include <string.h>
int main()
{
    int HW = 0, HD = 0, HL = 0, AW = 0, AD = 0, AL = 0, GF = 0, GA = 0, GD = 0, PTs = 0;
    char team1[15];
    int score1;
    char team2[15];
    int score2;
    for(int i = 0; i<10; i++)
    {
        scanf("%s %d %s %d",team1 , &score1, team2, &score2);
        printf("%s %d %s %d\n", team1, score1, team2, score2);
        if (strcmp(team1,"QMUL")==0)
        {
            if (score1>score2)
            {
                HW = HW +1;
            }
            else if (score1<score2)
            {
                HL = HL +1;
            }
            else if (score1 == score2)
            {
                HD = HD +1;
            }
            GF = GF + score1;
            GA = GA + score2;
        }
        else if (strcmp(team2,"QMUL")==0)
        {
            if (score1<score2)
            {
                AW = AW + 1;
            }
            else if (score1>score2)
            {
                AL = AL +1;
            }
            else if (score1 == score2)
            {
                AD = AD +1;
            }
            GF = GF + score2;
            GA = GA + score1;
        } 
    }
    GD = GF - GA;
    PTs = 3*(HW + AW) + (HD + AD);
    printf("      Home    Away\n"); 
    printf("      W D L   W D L   GF   GA   GD   PTs\n");  
    printf("QMUL  %d %d %d   %d %d %d   %d   %d   %d   %d",HW,HD,HL,AW,AD,AL,GF,GA,GD,PTs);
    return 0;
}




