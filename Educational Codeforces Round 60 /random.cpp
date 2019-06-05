#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int fac[100] = {1};
int power(int a, int b, int m)
{
	if(b == 0) return 1;
	int temp = power(a, b/2, m);
	temp *= temp;
	temp %= m;
	if(b&1) temp *=a%m, temp%=m;
	return temp;
}
int solve(int n, int m)
{
	m--;
	int t = m;
	int ans = 0;
	while(n - t >= t/m)
	{
		ans += fac[n - t]/(fac[n - t- t/m]*fac[t/m]);
		t += m;
	}
	return ans + 1;
}


void compute()
{
	fr(i,1,10) fac[i] = (i*fac[i - 1]);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	compute();

 	int n = 10;

 	fr(i,1,n  + 1)
 	{
 		fr(j,2,i + 1)
 		{
 			cout<<solve(i,j)<<" ";
 		}
 		cout<<'\n';
 	}


}