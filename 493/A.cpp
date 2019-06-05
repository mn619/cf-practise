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
int n,a[10];

signed main()
{
 	//start_routine
 	cin>>n;
 	int i,sum=0;
 	fr(i,0,n)
 	{
 		cin>>a[i];
 		sum+=a[i];
 	}
 	sum-=a[0];
 	if(n==1)return cout<<-1,0;
 	if(n==2)
 	{
 		if(a[0]==a[1]) return cout<<-1,0;
 		return cout<<1<<"\n"<<1,0;
 	}
 	if(a[0]==sum)return cout<<2<<"\n"<<1<<" "<<2,0;
 	cout<<1<<"\n"<<1;
	//end_routine
}



