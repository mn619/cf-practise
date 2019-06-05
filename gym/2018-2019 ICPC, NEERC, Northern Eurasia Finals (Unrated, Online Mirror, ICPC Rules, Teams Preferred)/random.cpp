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

int a[1000] = {1073741824, 536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608, 4194304, 2097152, 1048576, 524288, 262144, 131072, 65536, 32768};
int p[100001];

void calculate()
{
	int i;
	fr(i,1,100001) p[i] = i;
	fr(i,2,100001)
	{
		if(p[i] == i)
		{
			int j;
			for(j = i; j<100001; j+=i) p[j]-=p[j]/i;
		}
	}

}

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
map <int, int> phi;

int solve(int a, int m)
{
	if(m == 1) return 0;
	int res =  power(a, solve(a, phi[m]), m);
	cout<<m<<" "<<res<<'\n';
	return res;
}
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		calculate();

		int i;
		fr(i,1,1000)if(a[i] == 0)break;
		cout<<i<<'\n';

		int ind = i;
		fr(i,ind,1000)
		{
			a[i] = p[a[i - 1]];
		}

		fr(i,0,1000)
		{
			if(a[i] == 1) break;
			cout<<a[i]<<'\n';
		}
		fr(i,0,1000)
		{
			if(a[i] == 1) break;
			phi[a[i]] = a[i + 1];
		}

		cout<<phi[2]<<'\n';
		cout<<solve(3,1073741824);
	}

 	//end_routine
}
