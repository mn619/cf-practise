#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, k, dp[101][101][26];
vector<int> v;
string s;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>k>>s;
	reverse(s.begin(), s.end());
	s += '%';
	reverse(s.begin(), s.end());

	dp[1][1][s[1] - 'a'] = 1;
	fr(i, 2, n + 1){
		fr(j, 0, n + 1){
			int c = s[i] - 'a';
			fr(k, 0, 26){
				dp[i][j][c] += dp[i - 1][j - 1][k];
			}
			dp[i][j][c] -= dp[i - 1][j][c];
		}
	}

}