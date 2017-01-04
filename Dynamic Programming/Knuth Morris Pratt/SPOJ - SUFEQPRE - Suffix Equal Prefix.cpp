#include<bits/stdc++.h>
using namespace std;
#define LM 1000007
string str;
int lps[LM];
int zfunc[LM];

int kmp()
{
    zfunc[0] = lps[0] = 0;
    for(int i=1; i<str.size(); ++i)
    {
        int j = lps[i-1];
        while(j>0 && str[i]!=str[j])
            j = lps[j-1];
        if(str[i]==str[j]) j++;
        lps[i] = j;
    }
    int cunt = 0, l = lps[str.size()-1];
    while(l>0)
    {
        cunt++;
        l = lps[l-1];
    }

    return cunt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T,t=1;
    cin>>T;
    while(T--)
    {
        cin>>str;
        kmp();
        cout<<"Case "<<t++<<": "<<kmp()<<endl;
    }
    return 0;
}
