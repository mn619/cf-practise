#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;
int n, a[300001];

signed main()
{
	//FILEIO
 	FLASH
	cin>>n;
	fr(i,1,n + 1)
	{
		cin>>a[i];
	}

	sort(a+1, a+n + 1);

	int ans = 0;
	fr(i,1,n/2 + 1)
	{
		ans += (a[i] + a[n - i + 1])*(a[i] + a[n - i + 1]);
	}
	cout<<ans;
}