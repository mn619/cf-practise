#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

set <int> s;
void compute(){
	int p = 1;
	while(p <= 1000001){
		s.insert(p - 1);
		p *= 2;
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int x;
 	cin>>x;
 	compute();

 	vector <int> ans;
 	int d = 0;
 	while(1){
 		int l = log2(x) + 1;
 		if(d > 40) break;
 		ans.pb(l);
 		x ^= (1<<l) - 1;
 		d++;
 		if(s.find(x) != s.end()) break;
 		d++;
 		x += 1;
 	}

 	cout<<d<<'\n';
 	for(auto x: ans) cout<<x<<" ";
}
