#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

vector <int> v[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;

 	fr(i, 1, n + 1){
 		int a, b;
 		cin>>a>>b;
 		v[i].pb(a + b);
 		v[i].pb(a);
 		v[i].pb(b);
 	}


 	sort(v + 1, v + n + 1);
 	reverse(v + 1, v + n + 1);
 	int ans = 0;

 	int i = 1;

 	while(i <= n){
 		if(i == n) {ans += max(v[n][1], v[n][2]) + 1; break;}
 		int l1 = v[i][1], r1 = v[i][2], l2 = v[i + 1][1], r2 = v[i + 1][2];
 		if(max(l1,r1) + max(l2,r2) <= max(l1, r2) + max(l2, r1)){
 			ans += max(l1, r1) + 1;
 			i++;
 		}
 		else{
 			ans += 2 + max(l1, r2) + max(l2, r1);
 			i += 2;
 		}
 		//ans += 2 + min(max(l1,r1) + max(l2,r2), max(l1, r2) + max(l2, r1));
 	}

 	cout<<ans;

}