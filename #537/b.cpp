#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int n,k,m, a[100001];

signed main()
{
	FILEIO
 	FLASH
 	cin>>n>>k>>m;
 	int sum = 0;

 	cout<<setprecision(10);

 	fr(i,1,n + 1)
 	{
 		cin>>a[i];
 		sum += a[i];
 	}

 	sort(a + 1, a+ n + 1);
 	int i;
 	for(i = 1; i < min(m,n - 1) + 1; i++)
 	{
 		if((sum - a[i] + min(m - i , k*(n - i)))*(n -i + 1) > (n - i)*(sum + min(m - i + 1, k*(n - i + 1))))
 		{
 			sum -= a[i];
 		}
 		else
 		{
 			sum += min(m - i + 1, k*(n -i + 1));
 			double ans = 1.0*sum/(n -i + 1);
 			cout<<ans;
 			return 0;
 		}
 	}
 	double ans = (1.0*sum + 1.0*min(m - i + 1, k*(n - i + 1)))/(n - i + 1);
 	cout<<ans;
}