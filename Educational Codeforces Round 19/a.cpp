#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n, k;
 	cin>>n>>k;

 	vector <int> v;
 	int d = 2;
 	while(v.size() < k - 1 && n > 1)
 	{
 		if(n%d == 0) {v.pb(d); n /= d;}
 		else d++;
 	}

 	if(v.size() != k - 1 || n == 1) return cout<<-1, 0;
 	for(auto x: v) cout<<x<<" ";
 		cout<<n<<"\n";
}