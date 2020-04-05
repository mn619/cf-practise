#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define inf 10000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int dp[maxn][3];
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
	FLASH

	cin>>s;
	int l = s.size();
	vector <vector <bool> > in(l, vector<bool>(3));

	dp[0][0] = dp[0][1] = dp[0][2] = inf;

	if((s[0] - '0')%3 == 0){
		dp[0][0] = 0;
		in[0][0] = 1;
	}
	else{
		int d = (s[0] - '0')%3;
		dp[0][d] = 0;
		in[0][d] = 1;
		dp[0][0] = 1;
	}

	for(int i = 1; i < l; i++){
		int d = (s[i] - '0')%3;
		for(int j = 0; j < 3; j++){
			if(s[i] != '0')
				dp[i][j] = min(dp[i - 1][(j + 3 - d)%3], dp[i - 1][j] + 1), in[i][j] = (dp[i][j] != dp[i - 1][j] + 1);
			else{
				dp[i][j] = dp[i - 1][j] + (dp[i - 1][j] == i);
				in[i][j] = (dp[i - 1][j] != i);
			}
		}
	}

	if(dp[l - 1][0] == l){
		for(int i = 0; i < l; i++){
			if(s[i] == '0') return cout<<"0\n", 0;
		}
		return cout<<-1, 0;
	}

	string ans = "";
	int sm = 0;
	for(int i = l - 1; i >= 0; i--){
		if(in[i][sm]){
			ans += s[i];
			sm += 3 - (s[i] - '0')%3;
			sm %= 3;
		}
	}

	reverse(ans.begin(), ans.end());
	cout<<ans;
}