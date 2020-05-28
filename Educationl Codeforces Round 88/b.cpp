#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, x, y;

void solv(){
	cin>>n>>m>>x>>y;

	int ans = 0;
	for(int i = 1; i <= n; i++){
		string s;
		cin>>s;
		vector <int> dp(m, (int)10000000000);
		for(int j = 0; j < m; j++){
			if(j == 0){
				if(s[j] == '.') dp[j] = x;
				else dp[j] = 0;
				continue;
			}
			if(s[j] == '*'){
				dp[j] = dp[j - 1];
				continue;
			}
			if(s[j] == '.'){
				dp[j] = dp[j - 1] + x;
			}
			if(s[j - 1] == '.'){
				dp[j] = min(dp[j], y + ((j >= 2)? dp[j - 2]: 0)); 
			}
		}

		ans += dp[m - 1];
	}
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t = 1;
    cin>>t;

    while(t--) solv();
}