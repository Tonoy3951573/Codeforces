#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        int a[n];
		for(int i=1;i<=n;i++) cin>>a[i];
		int p=0;
		for(int i=2;i<=n-1;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]) p=i;
		}
		if(p) cout<<"YES"<<endl<<p-1<<" "<<p<<" "<<p+1<<endl;
		else cout<<"NO"<<endl;
	}
}