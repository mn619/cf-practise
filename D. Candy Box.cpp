#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

map<int, int> cnt;
vector<int>  v;

void solv(){
	int n;
	cin>>n;

	fr(i, 1, n + 1){
		int a;
		cin>>a;
		cnt[a]++;
	}

	for(auto x: cnt){
		v.pb(x.second);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int las = inf;
	int ans = 0;
	
	for(auto x: v){
		las = min(las - 1, x);
		if(las > 0) ans += las;
	}

	v.clear();
	cnt.clear();
	
	cout<<ans<<'\n';
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;
 	while(q--) solv();
}