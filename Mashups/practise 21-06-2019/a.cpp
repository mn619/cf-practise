#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 100000

using namespace std;
int cnt[maxn*2][26];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	string s;
 	cin>>s;

 	int n = s.size();
 	reverse(s.begin(), s.end());
 	s += '$';
 	reverse(s.begin(), s.end());
 	
 	for(int i = n; i >=1;i--){
 		
 		if(i != n)
 		fr(j, 0, 26){
 			cnt[i][j] = cnt[i + 1][j];
 		}
 		cnt[i][s[i] - 'a']++;
 	}
 	int c = 25;
 	string ans = "";

 	fr(i, 1, n + 1){
 		while(cnt[i][c] == 0){
 			c--;
 		}
 		
 		if(s[i] - 'a' == c) {ans += s[i];}
 	}

 	cout<<ans;
}