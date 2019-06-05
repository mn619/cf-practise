#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define inf 1000000007
#define AB inf

using namespace std;
int n,q;
int a[35]={0},arr[35]={0};
void colve(int x)
{
	int j,ans=0;
	fr(j,0,35)arr[j]=a[j];
	vector <int> v;
	j=0;
	while(x>0)
	{
		if(x%2)v.pb(j);
		x/=2; j++;
	}
	reverse(v.begin(),v.end());
	fr(j,0,v.size())
	{
			int k=v[j];
			int temp=pow(2,k);
			int req=1;
			while(k>=0)
			{
				if(arr[k]>0)
				{
					int temp2=pow(2,k);
				    req=temp/temp2;
					int xxx=min(arr[k],req);
					arr[k]-=xxx;
					ans+=xxx;
					temp-=xxx*temp2;
				}
				if(temp==0)break;
				k--;
			}
			if(temp!=0){cout<<-1<<"\n";return;}
	}
	cout<<ans<<"\n";
}
signed main()
{
 	start_routine
 	cin>>n>>q;
 	int i;

 	fr(i,0,n)
 	{
 		int x,k=0;
 		cin>>x;
 		int temp=1;
 		while(AB==inf)
 		{
 			if(temp==x)break; temp*=2; k++;
 		}
 		a[k]++;
 	}

 	fr(i,0,q)
 	{
 		int x;
 		cin>>x;
 		colve(x);
 	}
	end_routine
}