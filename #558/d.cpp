#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

vector<pair<int, int>> v;
int n, x[51], y[51];
set<pair<pair<int, int>, int>> m;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		cin>>x[i]>>y[i];
 		fr(j, 1, i){
 			int x1 = x[i], x2 = x[j], y1 = y[i], y2 = y[j];
 			int p = y2 - y1, q = x2 - x1;
 			int c = y1*q - x1*p;

 			int g = __gcd(p,q);
 			//g = __gcd(g, c);

 			p /= g;
 			q /= g;
 			c /= g;

 			m.insert({{p, q}, c});
 		}	
 	}

	pair<int ,int>  las = {-mod, -mod};
	int sum = 0;
 	int ans = 0;
	int cursum = 0;

	for(auto x: m){
		if(x.first != las){
			las = x.first;
			sum += cursum;
			cursum = 1;
		}
		else{
			cursum += 1;
		}
		ans += sum;
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<' '<<ans<<"\n";
	}


 	cout<<ans;
}