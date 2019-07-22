#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int s, b;
int a[maxn];
vector <int> v[maxn];

int bs(int x){
	int ans = 0;
	int l = 0, r = b;
	while(l <= r){
		int mid = (l + r)/2;
		if(v[mid][0] <= x){
			ans = v[mid][1];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s>>b;
 	fr(i, 1, s + 1) cin>>a[i];
 	fr(i, 1, b + 1){
 		int d, g;
 		cin>>d>>g;
 		v[i].pb(d);
 		v[i].pb(g);
 	}

 	v[0].pb(0);
 	v[0].pb(0);
 	
 	sort(v + 1, v + b + 1);
 	fr(i, 2, b + 1){
 		v[i][1] += v[i - 1][1];
 	}

 	fr(i, 1, s + 1){
 		int ans = bs(a[i]);
 		cout<<ans<<" ";
 	}
 	
}