// Problem Code: RAINDROPS

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &adj , int node , int parent , int height , set<long long int> &st , vector<long long int> &mp){
    if(adj[node].size() == 1 and node != 1){
        st.insert(height);
        mp[height]++;
        return;
    }
    
    for(int u : adj[node]){
        if(u != parent){
            dfs(adj , u , node , height + 1 , st , mp);
        }
    }
}

void testcase(){
    int n , m;
    cin >> n >> m;
    vector<vector<int> > adj(n+1);
    for(int i=0 ;i<n-1 ; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    set<long long int> st;
    vector<long long int> mp(n+1 , 0);
    
    dfs(adj , 1 , -1 , 0 , st , mp);
    
    vector<int> levels;
    for(int i : st) levels.push_back(i);
    
    vector<long long int> ms(m+1);
    ms[0] =0;
    for(int i=1 ; i<=m ; i++){
        cin >> ms[i];
    }
    
    long long int ans = 0;
    
    for(int i=0 ; i<m ; i++){
        long long int s = ms[i+1] - ms[i];
        s--;
        // cout << s << endl;
        long long int tempans = 0;
        
        for(long long int k : levels){
            if(k > s) break;
            // cout << k << ' ' << mp[k] << endl;
            tempans += mp[k] * (s - (k-1));
        }
        
        ans += tempans;
    }
    
    cout << ans << '\n';
}

int main() {
	// your code goes here
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    testcase();
	}
	return 0;
}
