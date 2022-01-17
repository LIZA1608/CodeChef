// Problem Code: POPCORN

#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
   while(t-->0){
       long long int a1,a2,b1,b2,c1,c2;
       cin>>a1>>a2>>b1>>b2>>c1>>c2;
       int as=0,bs=0,cs=0,ans=0;
       as=a1+a2;
       bs=b1+b2;
       cs=c1+c2;
       if(as>bs && as>cs){
           ans = as;
       }
       else if(bs>as && bs>cs){
           ans = bs;
       }
       else{
           ans = cs;
       }
       cout<<ans<<endl;
       }
       
	return 0;
}
