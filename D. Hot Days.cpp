#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, ans = 0;

signed main()
{
	FILEIO
 	FLASH

 	cin>>n>>m;
 	fr(i,1,n+ 1)
 	{
 		int t,T,x,cost;
 		cin>>t>>T>>x>>cost;
 	
 		int k = max((int) 0, T - t);
 		
 		if(k == 0)
 		    ans += x*m + cost;
 		else if(m <= k)ans += cost; 

 		else if(cost > (k + m%k)*x)
 			ans += cost + x*m;
 		else
 			ans += (m/k + !(m%k == 0))*cost;
 	}
 	cout<<ans;


}