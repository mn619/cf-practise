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
double a,b,m,vx,vy,vz,x,z;
double modulo(double x, double a)
{
	x<0?x=-x:x=x;
	int temp=x/(2*a);
	x=x-1.0*temp*2*a;
	x>a?x=2*a-x:x=x;
	return x;
}
signed main()
{
 	//start_routine
 	cout<<setprecision(25);
 	cin>>a>>b>>m>>vx>>vy>>vz;
 	double t=1.0*m/abs(vy);
 	x=modulo(1.0*a/2+1.0*vx*t,a);
 	z=modulo(1.0*vz*t,b);
 	cout<<x<<" "<<z;
	//end_routine
}