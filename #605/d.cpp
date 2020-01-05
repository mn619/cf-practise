#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, k;
 	string s;
 	cin>>n>>k;
 	std::vector<bool> b(26);	
 	cin>>s;
 	fr(i, 0, k){
 		char c;
 		cin>>c;
 		b[c - 'a'] = 1;
 	}

 	int ans = 0, len = 0;
 	fr(i, 0, n){
 		if(b[s[i] - 'a'] == 0){
 			ans += len*(len + 1)/2;
 			len = 0;
 		}
 		else len++;
 	}
 	ans += len*(len + 1)/2;

 	cout<<ans<<'\n';
}