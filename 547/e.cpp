#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
using namespace std;

int h, n, d[200001], inf = 1000000000000000000;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>h>>n;
 	int sum = 0;
 	fr(i, 1,n + 1) {cin>>d[i]; sum += d[i];}
 	if(sum < 0)
 	{
 		int x = 0;
	 	int ans = (int) inf;
	 	debug(ans);
	 	fr(i, 1, n + 1)
	 	{
	 		x +=  d[i];
	 		int l = 0, r = (int) (h/(-sum) + 100);

	 		int ans1 = 0;
	 		while(l <= r)
	 		{
	 			int mid = (l + r)/2;
	 			if(h + mid*sum + x <= 0)
	 			{
	 				ans1 = mid;
	 				r = mid - 1;
	 			}
	 			else l = mid + 1;
	 		}
	  		int h1 = h + ans1*sum + x;
	 		ans1 = ans1*n + i; 
	 		ans = min(ans, ans1);
 		}
	 	cout<<ans<<'\n';
 	}
 	else
 	{
 		fr(i, 1, n + 1)
 		{
 			h += d[i];
 			if(h <= 0) return cout<<i, 0;
 		}
 		return cout<<-1, 0;
 	}
}
