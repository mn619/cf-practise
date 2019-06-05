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
#define double long double
using namespace std;
int n,m;
double a[1001],b[1001];

signed main()
{
 	//start_routine
	cin>>n>>m;

	int i;
	fr(i,0,n)cin>>a[i];
	fr(i,0,n)cin>>b[i];

	double pdt1 = 1, pdt2 = 1;

	fr(i,0,n)
	{
		pdt1*=(a[i]-1)*(b[i]-1)/(a[i]*b[i]);
	}
	if(pdt1 == 0)
	{
		cout<<-1;
		return 0;
	}
	double ans = 1.0*m/pdt1;
	ans = ans -1.0* m;
	cout<<fixed;
	cout<<setprecision(10);
	cout<<ans;

 	//end_routine
}



