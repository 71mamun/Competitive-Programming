#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll T,n,m;
    cin>>T;
    while(T--){
        ll ans = 0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>m;
            if(m%2==0)continue;
            else ans^=i;
        }
        if(ans)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}

