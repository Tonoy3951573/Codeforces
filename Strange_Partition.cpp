#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    long long  n,k;cin>>n>>k;
    long long a=0,b=0;
    for(int i=0;i<n;i++){
        long long  x;cin>>x;
        a+=ceil((double)x/k);
        b+=x;
    }    
    cout<<(long long )ceil((double)b/k)<<" "<<a<<"\n";
    }
}