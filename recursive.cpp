#include<bits/stdc++.h>

using namespace std;

void print(int x){
    if(x == 1) return;
    print(x-1);
    cout<<x<<endl;
}

int main(){
    int x = 5;
    print(x);
}