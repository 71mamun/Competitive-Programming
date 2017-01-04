#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;

stack<int>Snum;
stack<char>Sop;

int signValue(char op)
{
    if(op=='*')
        return 2;
    else if(op=='+'||op=='-')
        return 1;
    else if(op=='(')
        return 0;
}

int calculate(char op)
{
    int a=Snum.top();
    Snum.pop();
    int b=Snum.top();
    Snum.pop();
    if(op=='+')
        return b+a;
    if(op=='-')
        return b-a;
    if(op=='*')
        return b*a;
}

int simulate(string line)
{
    line+=')';
    Sop.push('(');
    for(int i=0; i<line.size(); i++)
    {
        if(line[i]!=' ')
        {
            if(line[i]>='0'&&line[i]<='9')
            {
                Snum.push(line[i]-'0');
            }
            else if(line[i]>='a'&&line[i]<='z')
            {
                Snum.push(line[i]-'a'+26);
            }
            else if(line[i]>='A'&&line[i]<='Z')
            {
                Snum.push(line[i]-'A'+26);
            }
            else if(line[i]=='+'||line[i]=='*'||line[i]=='-'||line[i]=='(')
            {
                char preop=Sop.top();
                if(signValue(preop)>=signValue(line[i])&&line[i]!='(')
                {
                    int value=calculate(preop);
                    Snum.push(value);
                    Sop.pop();
                    Sop.push(line[i]);
                }
                else Sop.push(line[i]);
            }
            else if(line[i]==')')
            {
                while(Sop.top()!='(')
                {
                    char nop=Sop.top();
                    int num=calculate(nop);
                    Snum.push(num);
                    Sop.pop();
                }
                Sop.pop();
            }
        }
    }
    return Snum.top();
}

int main()
{
    int T;
    string line1,line2;
    scanf("%d\n",&T);
    for(int i=0; i<T; i++)
    {
        getline(cin,line1);
        getline(cin,line2);
        int u=simulate(line1);
        while(!Snum.empty())Snum.pop();
        while(!Sop.empty())Sop.pop();
        int v=simulate(line2);
        while(!Snum.empty())Snum.pop();
        while(!Sop.empty())Sop.pop();
        if(u==v)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
