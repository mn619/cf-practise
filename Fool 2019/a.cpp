#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int a[17];


int solve(int l, int r)
{
	bool ok = 1;
	fr(i, l + 1, r + 1)
		if(a[i] < a[i - 1]) ok = 0;
	if(ok) return r - l + 1;
	int mid = (l + r)/2;
	return max(solve(l, mid), solve(mid + 1, r));

}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;

 	fr(i, 1, n + 1) cin>>a[i];
 	cout<<solve(1, n);
}