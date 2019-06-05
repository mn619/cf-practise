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
int n,a[201],arr[201];

signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	fr(i,1,2*n+1)cin>>a[i];
 	int cnt=1;
 	map <int,int> m;
 	fr(i,1,2*n+1)
 	
 	{
 		if(m.count(a[i]))
 		{
 			arr[i]=m[a[i]]+1;
		}
		else {arr[i]=cnt; m[a[i]]=cnt; cnt+=2;}
	}
	 
	
	int j;
	cnt=0;
	fr(i,1,2*n+1)
	{
		fr(j,1,i)
		{
			if(arr[j]>arr[i])cnt++;
		}
	}
	cout<<cnt;
	//end_routine
}




