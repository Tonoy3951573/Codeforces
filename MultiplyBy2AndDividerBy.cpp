#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int temp = n;
        int m = 0,k = 0;
        while(n%2 == 0){
            m++;
            n = n/2;
        }
        while(n%3 == 0){
            k++;
            n = n/3;
        }
        //cout<<m<<" "<<k<<endl;
        if(n != 1 or k < m) cout<<-1<<endl;
        else {
            cout<<(k-m) + k<<endl;
        }
    }
}