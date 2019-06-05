#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define p 57

using namespace std;

int N;
vector <string> v;


vector<int> string_hash(string x){
	int pwr = 1;
	int l = x.size();
	vector <int> ans(l, 0);
	fr(i, 0, l){
		ans[i] = x[i]*pwr;
		pwr *= p;
		pwr %= mod;
		if(i > 0) ans[i] += ans[i - 1];
		ans[i] %= mod;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	while(cin>>N){
 		if(N == 0) return 0;
 		set <string> s;
 		fr(i, 1, N + 1){
 			string x;
 			cin>>x;
 			if(s.find(x) != s.end()) continue;
 			v.pb(x);
 			s.insert(x);
 		}

 		int n = v.size();
 		vector <int> h[n];
 		fr(i, 0, n){
 			h[i] = string_hash(v[i]);
 		}

 		int dp[n];

 		fr(i, 0, n){
 			dp[i] = 1;
 			fr(j, 0, i){
 				
 			}
 		}
 	}
 		
}