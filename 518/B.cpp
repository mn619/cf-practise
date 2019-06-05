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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;


vector <int> v;

void compute()
{
	bool primes[200000] = {0};

	int i;
	fr(i,2,200000)
	{
		if(primes[i] == 0)
		{
			v.pb(i);
			int j;
			for(j = i*i; j<200000; j+=i) primes[j] = 1;
		}
	}
}


int solve(int n)
{
	vector <int> cnt;
	int i;
	fr(i,0,v.size())
	{
		if(n%v[i] == 0)
		{
			int temp = 0;
			while(n%v[i] == 0)
			{
				n/=v[i];
				temp++;
			}
			cnt.pb(temp);
		}
	}
	if(n!=1)
	{
		cnt.pb(1);
	}

	int ans = 1;
	fr(i,0,cnt.size())
	{
		ans*=(cnt[i]+1);
	}
	return ans;
}
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;
	compute();

	while(tests--)
	{
		int b;
		cin>>b;

		int ans = solve(b);
		cout<<ans<<'\n';
	}

 	//end_routine
}
