#include<stdio.h>
#include<string.h>
#define SIZE 1005
#define mod 1000007
int tbl[SIZE][SIZE];
int str[SIZE][SIZE];
char str1[SIZE],str2[SIZE];

int main()
{
    int n;
    scanf("%d",&n);
    int t=1;
    while(n--)
    {
        scanf("%s %s",str1,str2);

        int C = strlen(str1);
        int R = strlen(str2);
        int i,j;
        for(i=0; i<=C; i++)
        {
            tbl[0][i] = 0;
            str[0][i]= 1;
        }
        for(i=0; i<=R; i++)
        {
            tbl[i][0] = 0;
            str[i][0]= 1;
        }
        for(i=1; i<=R; i++)
        {
            for(j=1; j<=C; j++)
            {
                if(str1[j-1]==str2[i-1])
                {
                    tbl[i][j] = tbl[i-1][j-1]+1;
                    str[i][j] = str[i-1][j-1];
                }
                else
                {
                    if(tbl[i-1][j]==tbl[i][j-1])
                    {
                        tbl[i][j] = tbl[i-1][j];
                        str[i][j] = (str[i-1][j]+str[i][j-1])%mod;
                        if(tbl[i-1][j-1]==tbl[i-1][j])
                        {
                            str[i][j]=(str[i][j]-str[i-1][j-1]);
                        }
                    }
                    else
                    {
                        if(tbl[i-1][j]>tbl[i][j-1])
                        {
                            tbl[i][j] = tbl[i-1][j];
                            str[i][j] = str[i-1][j];
                        }
                        else
                        {
                            tbl[i][j] = tbl[i][j-1];
                            str[i][j] = str[i][j-1];
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",t++,(str[R][C]+mod)%mod);
    }
    return 0;
}
