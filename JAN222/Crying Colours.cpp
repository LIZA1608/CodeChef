// Problem Code: CRYCOLR

#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll t,n;
int main() {
  // your code goes here
  cin>>t;
  while(t--){
      cin>>n;
      ll ans=0;
      vector<vector<ll>> v(3,vector<ll>(3));
      for(ll i = 0;i<3;i++){
      cin>>v[i][0]>>v[i][1]>>v[i][2];
          
      }
      if(v[0][0]==n && v[1][1]==n && v[2][2]==n){
          cout<<ans<<endl;
          continue;
      }
      ll lsum=v[2][0]+v[2][1]+v[1][0];
      ll rsum=v[0][1]+v[0][2]+v[1][2];
      cout<<max(lsum,rsum)<<endl;

  
  }
  return 0;
}
