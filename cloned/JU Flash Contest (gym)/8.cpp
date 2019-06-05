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
int a[100001];

int gcd(int a, int b)
{
	if(b == 0)return a;
	return gcd(b,a%b);
}

signed main()
{
	//FILEIO
 	//start_routine
	
	cin>>n;

	int g = 0, ok = 1;
	int i;
	fr(i,1,n +1)cin>>a[i];

	fr(i,1,n/2 + 1)
	{
		g = gcd(abs(a[i] - a[n-i+1]), g);
	}

	if(!g)return cout<<-1,0;
	cout<<g<<'\n';
 	//end_routine
}
