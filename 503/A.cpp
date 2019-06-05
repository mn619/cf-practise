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
int abss(int x)
{
	if(x<0) return -x;
	return x;
}
signed main()
{
 	//start_routine
 	int n,h,a,b,k;
 	int ta,tb,fa,fb;
 	cin>>n>>h>>a>>b>>k;

 	while(k--)
 	{
 		cin>>ta>>fa>>tb>>fb;
 		int ans = abss(ta-tb);
 		if(ta!=tb)
 		{
 		if(fa<a && fb<a)
 		{
 			ans+=abss(fa-fb)+ 2*min(abss(fa-a),abss(fb-a));
 		}
 		else if(fa>b && fb>b) ans+=abss(fb-fa) + 2*min(abss(fa-b),abss(fb-b));
 		else 
 		{
 			ans += abss(fa-fb);
 		}
 		}
 		else ans+=abs(fa-fb);
 		cout<<ans<<'\n';
 	}
 	//end_routine
}



