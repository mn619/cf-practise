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
int n;

signed main()
{
 	//start_routine
 	cin>>n;
 	int ans=0;
 	if(n>=100)
 	{
 		int temp=n/100;
 		n-=temp*100;
 		ans+=temp;
	}
	if(n>=20)
 	{
 		int temp=n/20;
 		n-=temp*20;
 		ans+=temp;
	}
	if(n>=10)
 	{
 		int temp=n/10;
 		n-=temp*10;
 		ans+=temp;
	}
	if(n>=5)
 	{
 		int temp=n/5;
 		n-=temp*5;
 		ans+=temp;
	}
	ans+=n;
	cout<<ans;
	//end_routine
}




