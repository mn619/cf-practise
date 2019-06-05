#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

set <int> s;
int m, ans[1001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	fr(i, 1, 11){
 		char c;
 		cin>>c;
 		if(c == '1') s.insert(i);
 	}
 	cin>>m;
	int w1 = 0, w2 = 0;

	fr(i, 1, m + 1){
		s.erase(ans[i - 1]);
		if(i&1){
			if(s.upper_bound(w2 - w1) == s.end()) return cout<<"NO", 0;
			ans[i] = *(s.upper_bound(w2 - w1));
			w1 += ans[i];
		}
		else{
			if(s.upper_bound(w1 - w2) == s.end()) return cout<<"NO", 0;
			ans[i] = *(s.upper_bound(w1 - w2));
			w2 += ans[i];
		}
		if(i > 1) s.insert(ans[i - 1]);
		cout<<ans[i]<<" ";
	}


	cout<<"YES\n";
	fr(i, 1, m + 1) cout<<ans[i]<<" ";
}