#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> events;
    while(n--){
        int a,b;
        cin>>a>>b;
        events.push_back({a,1});
        events.push_back({b,-1});
    }
    sort(events.begin(),events.end());
    int current = 0, maximum  = 0;
    for(auto [time, type] : events){
        current += type;
        maximum = max(maximum,current);
    }
    cout<<maximum<<endl;
}