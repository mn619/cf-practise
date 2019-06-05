#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int n, a[100001],b[100001], sum[100001], ans[100001];

signed main()
{
	FILEIO
 	FLASH
	cin>>n;
	fr(i,1,n + 1)
	{
		cin>>a[i];
	}
	sum[n] = a[n];
	ans[n] = 1;
	b[n] = 1;
	for(int i = n - 1; i>=1; i--)
	{
		if(sum[i + 1] >= a[i])
		{
			ans[i] = -1;
			b[i + 1] = 1;
			sum[i] = sum[i + 1] - a[i];
		}
		else 
		{
			sum[i] = a[i] - sum[i + 1];
			ans[i] = 1;
			b[i + 1] = -1;
		}
	}
	b[1] = 1;
	fr(i,2,n + 1)
	{
		b[i] *= b[i - 1];
		ans[i] *= b[i];
	}

	fr(i,1,n + 1) if(ans[i] > 0) cout<<"+"; else cout<<"-";
}