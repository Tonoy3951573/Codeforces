#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int x , n;
    cin>>x>>n;
    vector<long long int> a(n);
    for(long long int& i : a) cin>>i;
    long long int longest;
    long long int L = 0, R = x;
    for(long long int i = 0; i < n; i++){
        if(a[i]>=L and a[i]<= R){
        long long int left_side = a[i] - L;
        long long int Right_side = R - a[i];
        
        if(left_side > Right_side){
            R = a[i];
            longest = left_side;
        }
        else if(left_side < Right_side){
            L = a[i];
            longest = Right_side;
        }
        else{
            if(i != n - 1){
                if(a[i] > a[i+1]){
                    longest = a[i] - L;
                    L = a[i];
                }
                else {
                    longest = a[i] - L;
                    R = a[i];
                } 
            }
            else{
                longest = a[i] - L;
            }
        }
    }
        cout<<longest<<" ";
    }

    return 0;
}
