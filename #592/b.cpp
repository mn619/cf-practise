#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, dp[maxn];
string s;
vector <int> vp[]
void solv(){
	cin>>n>>s;
	if(s[0] == '1'){
		dp[0] = 2;
	}
	else dp[0] = 1;

	fr(i, 1, n){
		if(s[i] == '1'){
			dp[i] = 2 + dp[i - 1];
		}
		else dp[i] = dp[i - 1] + 1;
	}
	cout<<dp[n - 1]<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
	
	int t;
	cin>>t;
	while(t--) solv();	
}