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
int n,k;
int a[100001];

signed main()
{
 	//start_routine
 	cin>>n>>k;
 	int i;

 	fr(i,0,n)
 	{
 		cin>>a[i];
 		a[i]%=k;
 		a[i] = (a[i]+k)%k;
 	}
 	sort(a,a+n);
 	vector <int> p;
 	p.pb(a[0]);
 	fr(i,1,n)
 	{
 		if(a[i]!=a[i-1])p.pb(a[i]);
 	}
 	int l = p.size();

 	int in[k]={1,0};
 	int g = p[0];

 	fr(i,0,l)
 	{
 		g= __gcd(g,p[i]);
 	}
 	cout<<k/g<<"\n";
 	for(i=0;i<k;i+=g)cout<<i<<" ";

 	//end_routine
}

