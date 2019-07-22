#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 500000
using namespace std;

map <int, int> p;

void sieve(){

	vector<bool> b(maxn + 1, 0);

	fr(i, 2, maxn + 1){
		if(b[i] == 0){
			p[i] = 1;
			for(int j = i*i; j <= maxn; j +=i){
				b[j] = 1;
			}
		}
	}
}

vector<int> solve(int n){

	vector<int> ans;
	if(p.count(n)){
		ans.pb(n);
		return ans;
	}
	if(n&1){
		if(p.count(n - 2)){
			ans.pb(2);
			ans.pb(n - 2);
			return ans;
		}
		else{
			ans.pb(3);
			n -= 3;
			for(auto x: p){
				if(p.count(n - x.first)){
					ans.pb(x.first);
					ans.pb(n - x.first);
					return ans;
				}
			}
		}
	}
	else{
		for(auto x: p){
			if(p.count(n - x.first)){
				ans.pb(x.first);
				ans.pb(n - x.first);
				return ans;
			}
		}
	}

	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;
 	sieve();

 	while(t--){
 		int n;
 		cin>>n;

 		vector<int> ans = solve(n);

 		int sum = 0;
 		cout<<ans.size()<<'\n';
 		for(auto x: ans){
 			cout<<x<<' ';
 			sum += x;
 		}
 		cout<<'\n';
 	}
}