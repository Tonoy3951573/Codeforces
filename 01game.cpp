#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string str;
        cin>>str;
        map<char,int> ff;
        for(char ch : str) ff[ch]++;
        if(min(ff['0'],ff['1'])%2 && (ff['0'] or ff['1'])) cout<<"DA"<<endl;
        else cout<<"NET"<<endl;

    }
}