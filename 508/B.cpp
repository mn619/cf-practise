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
signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,i;
	cin>>n;
	int k = n*(n+1)/2;
	int sq = sqrt(k);
	bool primes[sq + 1] = {0};

	vector <int> v;

	fr(i,2,sq+1)
	{
		if(primes[i] == 0)
		{
			int j;
			for(j = i*i; j<=sq; j+=i)
			{
				primes[j] = 1;
			}
		}
	}

	fr(i,2,sq+1)
	{
		if(primes[i] == 0)
		{
			v.pb(i);
		}
	}
 	int temp = 0;
 	fr(i,0,v.size())
 	{
 		if(k%v[i] == 0 && k/v[i] > 1) 
 		{	
 			temp = v[i];
 			break;
 		}
 	}
 	if(temp>1)
 	{
 		cout<<"Yes\n";
 		cout<<1<<" "<<temp<<"\n";
 		cout<<n-1<<" ";
 		fr(i,1,n+1) if(i!=temp) cout<<i<<" ";
 		return 0;
 	}
 	cout<<"No";
 	//end_routine
}



