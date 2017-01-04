#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,n,m,k;
    cin>>T;
    while(T--){
        int ans = 0;
        cin>>n>>k;
        while(n--){
            cin>>m;
            ans^=m;
        }
        if(ans)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}
