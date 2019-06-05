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
int n,a[100001];
signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	int min=1000000000;
 	fr(i,1,n+1){cin>>a[i];}
 	
 	int j=0,ans;
 	bool b=0;
 	map<int,int> m;
	fr(i,1,n+1)
	{
	 	int j=(a[i]-i+1)/n+1+((a[i]-i+1)%n!=0);
	 	if(a[i]-i+1<=0){return cout<<i,0;}
	 	if(!m.count(j))
	 	m[j]=i;
	}
	map <int,int>:: iterator it=m.begin();
	while(it!=m.end())
	{
		if(it->first<min)
		{
			min=it->first;
			ans=it->second;
		}
		it++;
	}
	cout<<ans;
	//end_routine
}




