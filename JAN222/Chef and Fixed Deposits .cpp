//Problem Code: MINFD

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >>arr[i];
        }
        sort(arr,arr+n,greater<>());
        bool c = false;
        int sum =0,i;
        for(i = 0;i<n;i++){
            sum += arr[i];
            if(sum>=x){
                c= true;
                break;
            }
        }
            if(c) cout<< i+1 <<endl;
            else cout<< "-1\n";
        }
    
	
	return 0;
}
