#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;
 	string s;
 	cin>>s;

 	vector <int> v;
 	int l = 1, mx = 1;

 	fr(i, 1, n){
 		if(s[i] != s[i - 1]){v.pb(l); l = 1;}
 		else l++;
 		mx = max(mx, l);
 	}

 	v.pb(l);
 	int k = v.size();
 	int ans = k;
 	if(mx > 2) ans += 2;
 	else if(mx == 2){
 		int cnt = 0;
 		fr(i, 0, k){
 			if(v[i] == 2){
 				cnt++;
 			}
 		}
 		if(cnt > 1){
 			ans += 2;
 		}
 		else {
 			ans += cnt;
 		}
 	}
 	cout<<ans<<'\n';
}