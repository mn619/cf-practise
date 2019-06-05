#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k;

string f(int x, int l){
	string s = "";
	fr(i, 0, l){
		if(x == 0) s += '0';
		else if(x&(1<<i)) {s += '1'; x -= (i<<1);}
		else s += '0';
	}
	reverse(s.begin(), s.end());
	return s;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n>>k;

	if(2*k >= n){
		fr(i, 0, k) cout<<0;
		fr(i, k, n) cout<<1;
	}
	else{
		string s = f(1, k - 1);
		auto ans = s;
		n -= 2*(k - 1);
		int p =1;
		while(n >= k){
			ans += f(p++, k);
			n -= k;
		}
		ans += f(p, n);
		ans += s;
		cout<<ans;
	}
}