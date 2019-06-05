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
signed main()
{
 	//start_routine
 	int n;
 	cin>>n;
 	int i;
 	int a[n];
 	map <int,int> count;
 	map <int,bool> in;
 	fr(i,0,n)
 	{
 		cin>>a[i];
 		count[a[i]]++;
 		in[a[i]]=1;
 	}
 	int ans=0;
 	
 	fr(i,0,n)
 	{

 		int k=1;
 		while(k<=20000*100000)
 		{
 			if(in.count(k-a[i]))
 			if(k-a[i] != a[i] || count[k-a[i]]>=2)
 				{
 					//cout<<i<<" "<<k-a[i]<<" "<<count[k-a[i]]<<"\n";
 					ans++;
 					break;
 				}
 			k*=2;
 		}
 	}
 	cout<<n-ans<<"\n";
 	//end_routine
}



