#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,a,b,c,d,ans = 0;
vector <int> primes;

void compute()
{
	bitset <10000*10000+1> in;
	int i;
	fr(i,2,n+1)
	{
		if(!in[i])
		{
			int j;
			for(j = i*i; j<=n;j+=i)
			{
				in[j] = 1;
			}
		}


	}
	fr(i,2,n+1)
	{
		if(!in[i]) primes.pb(i);
	}

}
signed main()
{
 	//start_routine
 	cin>>n>>a>>b>>c>>d;

 	compute();

 	int ans = 0;
 	int i;
 	int val[primes.size()];
 	fr(i,0,primes.size())
 	{
 		val[primes[i]] = a*primes[i]*primes[i]*primes[i]+b*primes[i]*primes[i]+c*primes[i]+d;
 	}

 	fr(i,0,primes.size())
 	{
 		int temp = primes[i];

 		while(n/temp)
 		{
 			ans+=(n/temp)*val[i];
 			temp*=primes[i];
 		}
 	}
 	cout<<ans<<"here";
 	//end_routine
}



