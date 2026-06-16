#include<bits/stdc++.h>\

using namespace std;

void solve1(){
    int n,k = 1;
    cin>>n;
    for(int i = 1; i <=n; i++){
        for(int j = n - i - 1; j >= 0; j--){
            cout<<" ";
        }
        for(int j = 1; j <= k; j++){
            cout<<"*";
        }
        cout<<endl;
        k+=2;
    }
}

void solve2(){
    int n,k = 1;
    cin>>n;
    for(int i = 1; i <=n; i++){
        for(int j = n - i - 1; j >= 0; j--){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        for(int j = 1; j <= i - 1; j++){
            cout<<"*";
        }
        cout<<endl;
        
    }
}

int main(){
    solve2();
}