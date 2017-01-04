#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define SZ 1005

int T,N,M;
int vessel[SZ];
int Min;

int required(int vol)
{
    int sum = vessel[0];
    int n = 1;
    for(int i=1; i<N;)
    {
        if(sum+vessel[i]>vol)
        {
            n++;
            sum = 0;
        }
        else
        {
            sum+=vessel[i];
            i++;
        }
    }
    return n;
}

void print(int vol,int m,int n)
{
    int sum = 0;
    for(int i=0;i<N;)
    {
        cout<<m<<" "<<n<<endl;
        if(m==n)
        {
            for(int j=i;j<N;j++)
            {
                cout<<vessel[i]<<endl;
            }
            return;
        }
        if(sum+vessel[i]>vol)
        {
            cout<<sum<<endl;
            m--;
            sum=0;
        }
        else
        {
            sum+=vessel[i];
            n--;
            i++;
            if(i==N)cout<<sum<<endl;
        }
    }
    return;
}

int main()
{
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int low = -1;
        int high = 0;
        scanf("%d %d",&N,&M);
        M++;
        N++;
        for(int n=0; n<N; n++)
        {
            scanf("%d",&vessel[n]);
            low = max(low,vessel[n]);
            high+=vessel[n];
        }
        high = high/2+1;
        int mid,req,res = 1e9;
        while(low<=high)
        {
            mid = (low+high)/2;
            req = required(mid);
            if(req<=M)
            {
                res = min(res,mid);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        printf("Case %d: %d\n",t,res);
        print(res,M,N);
    }
    return 0;
}
