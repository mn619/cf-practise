#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

vector<pair<int, int>> v;
int n, x[5100], y[5100];
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
 			int g = __gcd(p,q);

 			p /= g;
 			q /= g;

 			if(q < 0){
 				p *= -1;
 				q *= -1;
 			}
 			else if(q == 0){
 				p = abs(p);
 			}
 			else if(p == 0){
 				q = abs(q);
 			}

 			int c = y1*q - x1*p;
 			m.insert({{p, q}, c});
 		}	
 	}

	map <pair<int, int>, int> s;

	for(auto x: m){
		s[x.first]++;
	}

	n = m.size();

	int ans = n*(n - 1)/2;

	for(auto x: s){
		int t = x.second;
		ans -= t*(t - 1)/2;
	}

 	cout<<ans;
}