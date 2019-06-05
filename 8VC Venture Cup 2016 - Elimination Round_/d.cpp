#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define double long double

using namespace std;

int n, a[2011];

double diff[5011] = {0}, dsm[10011] = {0}; 
double dp[2011] = {0};

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cout<<setprecision(10);

 	cin>>n;
 	fr(i, 1, n + 1) cin>>a[i];
 	sort(a + 1, a + n +  1);

 	fr(i, 1, n + 1)
 	{
 		fr(j, 1, i)
 		{
 			diff[a[i] - a[j]] += 1;
 		}
 	}
 	dsm[5000] = diff[5000];
	
	for(int i  = 4999; i>=1; i--) 	
 	{
 		dsm[i] = dsm[i + 1] + diff[i];
 	}

 	double ans = 0;

 	fr(i, 1, 5001)
 	{
 		fr(j,1, 5001)
 		{
 			ans += diff[i]*diff[j]*dsm[i + j + 1];
 		}
 	}
 	
 	fr(i, 1, 4) ans /= n*(n - 1)/2;
 	cout<<ans<<"\n";
}	