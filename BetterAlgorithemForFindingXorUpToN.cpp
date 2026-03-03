#include<bits/stdc++.h>
using namespace std;

int arr[500] ={ 0};

long long  xorGenarator(long long  n){
    if(n%4 == 0) return n;
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    if(n%4 == 3) return 0;
    return -1;

    //Time Complecity --> O(1)
}

int main(){
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= 499; i++){
        arr[i] = arr[i-1]^i;
        //TimeComplexity --> O(n)
    }
    for(int i = 0; i <= 499; i++){
        cout<<i<<" :  "<<arr[i]<<endl;
        cout<<i<<" :* "<<xorGenarator(i)<<endl;
        if(arr[i] != xorGenarator(i)){
            cout<<"FAILED!"<<endl;
            return 0 ;
        }
    }
    cout<<"ALL PASSED"<<endl;
}