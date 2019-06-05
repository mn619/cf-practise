#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

int a[5001], b[5000], dp[5001] = {0}, g[5001], val  = 0, cal[5001], n, m;

vector <int> primes;


set <int> s;
int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int f(int x)
{
	int ret = 0;
	fr(j,0,primes.size())
	{
		if(primes[j] > x) break;
		int ad = (s.count(primes[j]))? -1 : 1;
		while(x%primes[j] == 0)
		{
			ret += ad;
			x /= primes[j];	
		}
	}
	if(x > 1) {if(s.count(x)) ret--; else ret++;}
	return ret;
}

void compute()
{
	g[1] = a[1];
	fr(i,2,n + 1) g[i] = gcd(a[i], g[i - 1]);

	bool b[40001] = {0};

	fr(i,2,sqrt(mod))
	{
		if(b[i] == 0)
		{
			primes.pb(i);
			for(int j = i*i; j <= sqrt(mod); j+=i)
			{
				b[j] = 1;
			}
		}
	}

	fr(i,1,n + 1)
		cal[i] = f(g[i]), val += f(a[i]);
}

signed main()
{
	FILEIO
 	//FLASH
	
 	cin>>n>>m;
 	fr(i,1,n + 1) cin>>a[i];
 	fr(i,1,m + 1) {cin>>b[i]; s.insert(b[i]);}
 	compute();
 	
 	int ans = val;

 	for(int i = n; i >= 1; i--)
 	{

 		dp[i] = val - i*(cal[i]);
 		for(int j = i + 1; j <= n; j++)
 		{
 			dp[i] = max(dp[i], dp[j] - i*(cal[i] - cal[j]));
 		}
 		ans = max(ans, dp[i]);
 	}
 	
 	cout<<ans<<'\n';
}