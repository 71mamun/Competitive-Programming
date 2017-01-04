#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 4005
int arr[SZ][6];
int fa[SZ*SZ];
int sa[SZ*SZ];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
    	for(int j=0;j<4;++j)
    	{
    		scanf("%d",&arr[i][j]);
    	}
    }

    int idx=0;

    for(int i=0;i<n;++i)
    {
    	for(int j=0;j<n;++j)
    	{
    		fa[idx]=arr[i][0]+arr[j][1];
    		sa[idx]=-(arr[i][2]+arr[j][3]);
    		idx++;
    	}
    }

    sort(fa,fa+idx);
    sort(sa,sa+idx);

    int i=0,j=0,ffrq=1,sfrq=1,ans=0;
    while(i<idx and j<idx)
    {
    	while(i<idx-1 and fa[i] == fa[i+1])i++,ffrq++;
    	while(j<idx-1 and sa[j] == sa[j+1])j++,sfrq++;
    	if(fa[i]==sa[j])
    	{
    		ans+=(ffrq*sfrq);
    		i++,j++,ffrq=sfrq=1;
    	}
    	else if(fa[i]>sa[j])
    	{
    		j++,sfrq=1;
    	}
    	else
    	{
    		i++,ffrq=1;
    	}
    }
    printf("%d",ans);
    return 0;
}
