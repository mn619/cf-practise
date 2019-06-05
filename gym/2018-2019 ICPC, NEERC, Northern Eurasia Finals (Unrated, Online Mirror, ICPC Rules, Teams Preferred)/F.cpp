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

int n;
vector <int> p;

void compute()
{
	bool b[100001] = {0};
	fr(i,2,100001) 
	{
		p.pb(i);
		if(b[i] == 0)
		{
			for(int j = i*i; j <= 100000; j+=i) b[j] = 1;
		}
	}
}
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		cin>>n;
		compute();
		int temp = n;
		fr(i,0,p.size())
		{
			if(temp%p[i] == 0)
			{
				v.pb(p[i]);
				while(temp%p[i] == 0) temp/=p[i];
			}
		}
		if(temp > 1) v.pb(temp);

		
	}

 	//end_routine
}
