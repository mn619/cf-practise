#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, k, d, a[maxn + 1];
void solv(){
	cin>>n>>k>>d;
	fr(i, 1, n + 1) cin>>a[i];

	map <int, int> m;
	set <int> cnt;
	int ans = 0;

	fr(i, 1, d + 1){
		m[a[i]]++;
		cnt.insert(a[i]);
	}

	ans = cnt.size();
	fr(i, d + 1, n + 1){
		m[a[i - d]]--;
		if(m[a[i - d]] == 0){
			cnt.erase(a[i - d]);
		}
		m[a[i]]++;
		cnt.insert(a[i]);
		ans = min(ans, (int)cnt.size());
	}

	cout<<ans<<'\n';
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