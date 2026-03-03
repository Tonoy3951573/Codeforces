#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n*k);
        for(int& i : a){
            cin>>i;
        }
        long long sum = 0;
    
        for(int i = 0; i < k; i++){
            int ind = (k*(ceil((double(n)/2)) - 1)) + 1 + (n-ceil((double(n)/2)) + 1)*i;
            //cout<<ind<<" ";
            sum += a[ind - 1];
        }
        //cout<<endl;
        cout<<sum<<endl;
    }
}