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
int n,b;
int a[110];

signed main()
{
 	//start_routine
 	cin>>n>>b;
 	int i;
 	int pocnt[n+1]={0},socnt[n+2]={0};
 	fr(i,1,n+1)
 	{
 		cin>>a[i];
 		pocnt[i]=pocnt[i-1]+a[i]%2;
 	}
 	if(n%2)return cout<<0,0;
 	if(pocnt[n]*2!=n)return cout<<0,0;
 	
 	vector <int> cost;
 	
 	
 	fr(i,1,n)
 	{
		if(pocnt[i]*2==i)cost.pb(abs(a[i+1]-a[i]));
 	}
 	sort(cost.begin(), cost.end());

 	int temp=0;
 	int cnt=cost.size();
 	fr(i,0,cnt)
 	{
 		if(temp+cost[i]>b)break;
 		temp+=cost[i];
 	}
 	cout<<i;
	//end_routine
 	
}



