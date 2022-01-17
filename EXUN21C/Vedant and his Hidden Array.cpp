// Problem Code: SUMPARITY

#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n,a;cin>>n>>a;
        if(n==1){
            if(a%2==0)cout<<"Even\n";
            else cout<<"Odd\n";
            continue;
        }if(a%2==1){
            if(n%2==0)cout<<"Even\n";
            else cout<<"Odd\n";
        }
        else{
                cout<<"Impossible\n";
            }
        
    }
	return 0;
}
