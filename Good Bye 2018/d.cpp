#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 998244353
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;


int power(int a,int b, int m)
{
	if (b==0)
	return 1;
	int temp = power(a,b/2,m);
	temp = (temp*temp)%m;
	if (b&1)
	return (temp*(a%m))%m; 
	return temp;
}

int p[1000001] = {1}, f[1000001] = {1}, n;

void compute()
{
	int i;
	fr(i,1,1000001) f[i] = (i*f[i - 1])%mod;
	p[0] = 1;
	fr(i,1,n + 1)
	{
		p[i] = (f[n]*power(f[n - i], mod - 2, mod))%mod;
	}
}
signed main()
{
	//FILEIO
 	//start_routine
	cin>>n;
	compute();

	
	int ans =0;
	int i;
	fr(i,0,n + 1)
	{
		ans += p[i]*(f[n - i] - 1);
		ans %=mod;
	}
	ans++;
	ans%=mod;
	cout<<ans<<'\n';
 	//end_routine
}
