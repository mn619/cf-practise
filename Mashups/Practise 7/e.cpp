#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, ans, las = 0;
vector <int> v[5001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		int a, b;
 		cin>>a>>b;

 		v[i].pb(a);
 		v[i].pb(b);
 	}

 	sort(v + 1, v + n + 1);

 	fr(i, 1, n + 1){
 		ans = (v[i][1] >= las)?v[i][1]: v[i][0]; 
 		las = ans;
 	}

 	cout<<ans<<'\n';
}