#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
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
int n, k, fac[100001] = {1};
vector <int> primes;
bitset <10000001> b;

void compute()
{
	int i;
	fr(i,2,10000001)
	{

		if(b[i] == 0)
		{
			primes.pb(i);
			for(int j = i*i; j<=10000000; j+=i) b[j] = 1;
		}
	}

	fr(i,1,100001) fac[i] = (i*fac[i - 1])%mod;
}

vector <int> d;

int f(int x)
{
	int ans = 1;
	fr(i,0,primes.size())
	{
		int cnt = 0;
		while(x%i == 0)
		{
			x /=i;
			cnt++;
		}
		ans *= fac[cnt + k];
		ans %= mod;
		ans *= power((fac[cnt]*fac[k])%mod, mod - 2, mod);
		ans %=mod;
	}
	return ans;
}

signed main()
{
	//FILEIO
 	//start_routine
 	k = 2;
	compute();
	cout<<f(10);
	return 0;
	cin>>n>>k;
	cout<<primes.size();
	int n1 = n;
	for(int i =1; i*i <= n; i++)
	{
		if(n%i == 0) 
			{
				d.pb(i), d.pb(n/i);
				while(n1%i == 0) n1/=i;
				while(n1%(n/i) == 0) n1 /= (n/i);
			}
	}
	if(n1 != 1) primes.pb(n1);
	return 0;
	int ans = 0;
	for(int i = 1; i*i<= n; i++)
	{
		int temp;
		if(n%i == 0) temp = (((n*power(i,mod - 2, mod))%mod)*f(i))%mod;
		if(i*i != n) temp += (i*f(n/i))%mod;
		ans += temp;
	}
		
	cout<<ans<<'\n';
 	//end_routine
}
