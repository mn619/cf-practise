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
int a[101];

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
 	for(int i=n;i>=1;i--)
 	{
 		socnt[i]=socnt[i+1]+a[i]%2;
 	}
 	vector <int> cost;
 	fr(i,1,n+1)cout<<pocnt[i]<<" ";
 	cout<<"\n";
 	fr(i,1,n+1)cout<<socnt[i]<<" ";
 	cout<<"\n";
 	fr(i,1,n)
 	{
		if(pocnt[i]*2==i && socnt[i+1]*2==(n-i))cost.pb(abs(a[i+1]-a[i]));
 	}
 	sort(cost.begin(), cost.end());

 	int temp=0;
 	int cnt=cost.size();
 	cout<<cnt<<"\n\n";
 	fr(i,0,cnt)

 	{
 		if(temp+cost[i]>b)break;
 	}
 	cout<<i;
	//end_routine
 	
}



