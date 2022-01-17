//Problem Code: SUMANDOR

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
            
        int sum,ore;
        cin>>ore>>sum;
        vector<int> sm(32,0);
        vector<int> ores(32,0);
        int pos=0;
        sum-=ore;
        if( sum == 0){
            cout<<"1"<<endl;
            continue;
        }
        while(ore>0){
            if(ore%2) ores[pos]++;
            pos++;
            ore/=2;
        }
        pos=0;
        
        // cout<<"sum = "<<sum<<'\n';
        while(sum>0){
            if(sum%2) sm[pos]++;
            pos++;
            sum/=2;
        }
        int carry=0;
        vector<int> tmp(32,0);
        for(int i=31;i>=0;i--){
            tmp[i]=sm[i];
        }
        
        for(int i=31;i>=0;i--){
            if(ores[i]==1){
                tmp[i]=2*carry+tmp[i];
                carry=0;
            }
            else{
                carry=2*carry+tmp[i];
                tmp[i]=0;
            }
        }
        if(carry) {cout<<-1<<endl;continue;}
        
        int low=0,high=1e9;
        while(low+1<high){
            int carry=0;
            int mid = (low+high)/2;
            vector<int> tmp(32,0);
            for(int i=31;i>=0;i--){
                tmp[i]=sm[i];
            }
            for(int i=31;i>=0;i--){
                if(ores[i]==1){
                    tmp[i]=2*carry+tmp[i];
                    if(tmp[i]>mid){
                        carry=tmp[i]-mid;
                        tmp[i]=mid;
                    }
                    else carry=0;
                }
                else{
                    carry=2*carry+tmp[i];
                    tmp[i]=0;
                }
                // if(mid==2){
                //     if(i<4)
                //     cout<<(1<<i)<<' ' <<tmp[i]<<' '<<carry<<'\n';
                // }
            }
            // cout<<mid<<' '<<carry<<'\n';
            if(carry==0) high=mid;
            else low=mid;
        }
        cout<<high+1<<endl;
        
    }
    

    return 0;
}
