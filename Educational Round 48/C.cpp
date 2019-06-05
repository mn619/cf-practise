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
int n,a[2][n+1], up[n+1] = {0},bottom[n+1]={0};



void solve(int l, int val, int time)
{
	if(l==n+1) return 0;
	int max = 0 ;
	max = solve(l+1,val + time*a[0][l] + (time+1)*a[1][l]+ (time+2)*a[0][l+1]+(time+3)*a[1][l+1], time+=2);
}

void find()
{
	int fsum[2][n+1] = {0};
	fr(i,1,n+1)
	{
		fsum[0][i]=fsum[0][i-1]+a[0][i];
	}
	fsum[1][n] = fsum[0][n]+a[1][n];
	for(i=n-1;i>0;i--)
	{
		fsum[1][i] = fsum[1][i+1]+a[1][i];
	}

	
}
signed main()
{
 	//start_routine
 	cin>>n;
 	fr(i,1,n+1)
 	{
 		cin>>a[0][i];
 	}
 	fr(i,1,n+1)
 	{
 		cin>>a[1][i];
 	}
 	find();

 	int t = 0;
 	int max = 0;
 	int ans = 0;
 	int j
 	


 	fr(i,0,n)
 	{
 		max += a[0][i]*t;
 		t++;
 	}
 	for(i = n;i>0;i--)
 	{
 		max += a[1][i]*t;
 		i++;
 	}
 	if(max > ans)ans = max;
 	
 	max = solve(1,n,0,0);


 	//end_routine
}



