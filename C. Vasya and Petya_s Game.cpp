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
int isprime[1001]={0};
void compute()
{
	int i;

	fr(i,2,1001)
	{
		if(isprime[i] == 0)
		{
			int j;
			for(j=i*i;j<=1000;j+=i)isprime[j]=1;
		}
	}
	fr(i,2,1001)isprime[i]=!isprime[i];
}
signed main()
{
 	start_routine
 	compute();
 	int n;
 	cin>>n;
 	int ans = 0;
 	vector <int> v;
 	int i;
 	
 	fr(i,2,n+1)
 	{
 		if(isprime[i])
 		{
 			int temp = i;
 			while(temp<=n){v.pb(temp),ans++; temp*=i;}
 		}
 	}
 	cout<<ans<<"\n";
 	fr(i,0,v.size())
 	{
 		cout<<v[i]<<" ";
 	}
 	end_routine
}



