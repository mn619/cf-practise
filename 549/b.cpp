#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int pwr[20] = {1};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	fr(i, 1, 20) pwr[i] = 9*pwr[i - 1];

 	int n;
 	cin>>n;
 	vector <int> v;
 	while(n)
 	{	
 		v.pb(n%10);
 		n /= 10;
 	}	
 	reverse(v.begin(), v.end());

 	int l = v.size();
 	if(l == 1) return cout<<v[0], 0;

 	int ans = pwr[l - 1], cur = v[0];
 	if(v[0] != 1) ans *= v[0] - 1;

 	fr(i, 1, l)
 	{
 		int d = v[i];
 		if(d <= 1) continue;
 		ans = max(ans, cur*(d - 1)*pwr[l - i - 1]);
 		cur *= d;
 	}
 	ans = max(ans, cur);
 	cout<<ans<<'\n';
}