#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 1000000

using namespace std;

int n;
double d, a;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cout<<setprecision(25);
 	cin>>n>>a>>d;

 	double las = 0, ans = 0;

 	fr(i, 1, n + 1){
 		double t, v;
 		cin>>t>>v;
 		double finish = 1.0*(v)/a;
 		if(0.5*a*finish*finish < 1.0*d){
 			double rem = 1.0*d - 0.5*a*finish*finish;
 			ans = max(las, t + finish + 1.0*rem/v);
 		}
 		else{
 			ans = max(las, t + sqrt(2.0*d/a));
 		}
 		cout<<ans<<'\n';
 		las = ans;
 	}
}