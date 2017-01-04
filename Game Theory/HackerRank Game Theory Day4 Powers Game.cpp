#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n,T;
    cin>>T;
    while(T--){
        cin>>n;
        if(n%8==0)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    return 0;
}
