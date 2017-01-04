#include<bits/stdc++.h>
#define SZ 110
using namespace std;
string str1;
string str2;

int tbl[SZ][SZ];
string str[SZ][SZ];


string smallest(string p,string q)
{
    int l = min(p.size(),q.size());
    for(int i=0; i<l; i++)
    {
        if(p[i]==q[i])continue;
        else
        {
            if(p[i]<q[i])return p;
            else return q;
        }
    }
    return p;
}

string solve(string str1,string str2)
{
    int C = str1.size();
    int R = str2.size();
    for(int i=0; i<=C; i++)
    {
        tbl[0][i] = 0;
        str[0][i]="";
    }
    for(int i=0; i<=R; i++)
    {
        tbl[i][0] = 0;
        str[i][0]="";
    }
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if(str1[j-1]==str2[i-1])
            {
                tbl[i][j] = tbl[i-1][j-1]+1;
                str[i][j] = str[i-1][j-1];
                str[i][j].push_back(str1[j-1]);
            }
            else
            {
                if(tbl[i-1][j]==tbl[i][j-1])
                {
                    tbl[i][j] = tbl[i-1][j];
                    str[i][j] = smallest(str[i-1][j],str[i][j-1]);
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
    return str[R][C];
}


int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>str1>>str2;
        string ans = solve(str1,str2);
        if(ans.size()==0)cout<<"Case "<<t<<": :("<<endl;
        else cout<<"Case "<<t<<": "<<solve(str1,str2)<<endl;
    }
    return 0;
}
