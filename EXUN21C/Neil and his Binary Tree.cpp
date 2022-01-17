// Problem Code: GOODBINTREE

// Author: Richw818
// Created: 01.12.2022 09:30:31

#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1e9 + 7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		int64_t n, m; cin >> n >> m;
		int64_t lvls = 0;
		while(n){
			n >>= 1;
			++lvls;
		}
		vector<vector<int64_t>> dp(lvls + 1, vector<int64_t>(m+1));
		vector<vector<int64_t>> pref(lvls + 1, vector<int64_t>(m+1));
		for(int i = 1; i <= m; ++i){
			dp[lvls][i] = 1;
			pref[lvls][i] = dp[lvls][i] + pref[lvls][i-1];
		}
		for(int i = lvls - 1; i >= 1; --i){
			for(int j = 1; j <= m; ++j){
				if(i & 1){
					int64_t next = pref[i+1][m] - pref[i+1][j];
					next = (next * next) % MOD;
					dp[i][j] = (dp[i][j] + next) % MOD;
				}
				else{
					int64_t next = pref[i+1][j-1];
					next = (next * next) % MOD;
					dp[i][j] = (dp[i][j] + next) % MOD; 
				}
				pref[i][j] = (dp[i][j] + pref[i][j-1]) % MOD;
			}
		}
		int64_t ans = 0;
		for(int i = 1; i <= m; ++i)
			ans = (ans + dp[1][i]) % MOD;
		cout << ans << '\n';
	}
	return 0;
}
