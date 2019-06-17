#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;

int sm(int x){
	int ans = 0;
	while(x) ans += x%10, x /= 10;
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;

	int t = (5*n)%9;
	int p = n - t + 90;

	vector<int> ans;

	while(p + 1000 >= n and p >= 1){
		if(p + sm(p) == n) ans.pb(p);
		p -= 9;
	}

	cout<<ans.size()<<'\n';
	sort(ans.begin(), ans.end());
	
	for(auto x: ans) cout<<x<<"\n";
}