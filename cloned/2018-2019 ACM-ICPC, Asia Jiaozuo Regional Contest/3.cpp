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

int n = 10000;
bool d[1001] = {0};

void compute()
{
	int i;
	fr(i,2,n +1)
	{
		for(int j = i*i; j<=n; j += i*i)
		{
			d[j] = 1;
		}
	}

	fr(i,1,n +1) d[i] = !d[i];

}

int gcd(int a, int b)
{
	if(b == 0)return a;
	return gcd(b,a%b);
}
signed main()
{
	FILEIO
 	//start_routine
	int p = 1110, q  = 0;
	compute();
	d[1] = 1;

	int i;
	//fr(i,1,n +1) cout<<i<<" "<<d[i]<<'\n';
	
	fr(i,1,n +1)
	{
		int p1 = i, q1 = 0;
		int j;
		fr(j,1,i + 1)
		{
			if(i%j == 0 && d[j])
			{
				q1 += i/j;
			}
		}
		cout<<i<<" "<<p1/gcd(p1,q1)<<" "<<q1/gcd(p1,q1)<<'\n';
		if(p1*q < p*q1)
		{
			p = p1, q = q1;
			cout<<i<<" "<<p/gcd(p,q)<<"/"<<q/gcd(p,q)<<'\n';
		}
	}

 	//end_routine
}
