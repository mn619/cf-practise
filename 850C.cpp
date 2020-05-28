#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

map <int, int> dp;

int calc(int mask){
	if(dp.count(mask)) return dp[mask];
	vector <int> v;
	for(int i = 0; i < 30; i++){
		if((mask>>i) == 0) continue;
		int mask1 = (mask&((1<<i) - 1))|mask>>(i + 1);
		int t = calc(mask1);
		v.push_back(t);
	}

	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.resize(distance(v.begin(), it));
	for(int i = 0; i < (int)v.size(); i++) if(v[i] != i) return dp[mask] = i;
	return dp[mask] = (int)v.size();
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    dp[0] = 0;

 	int n;
 	cin>>n;

 	map <int, int> m;

 	for(int i = 1; i <= n; i++){
 		int a;
 		cin>>a;

 		for(int i = 2; i*i <= a; i++){
 			if(a%i != 0) continue;
 			int c = 0;

 			while(a%i == 0){
 				a /= i;
 				c++;
 			}

 			m[i] = m[i]|(1<<(c - 1));
 		}

 		if(a != 1) m[a] = m[a]|1;
 	}

 	int xr = 0;

	for(auto x: m){
		xr ^= calc(x.second);
	}
		
	// cout<<'\n';
	// for(auto x: dp){
	// 	cout<<x.first<<" "<<x.second<<'\n';
	// }

	if(xr) cout<<"Mojtaba\n";
 	else cout<<"Arpa\n";
}