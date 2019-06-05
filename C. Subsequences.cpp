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
int bit[15][100001]={{0}},a[100001];
int n,k;

int sum(int ind,int j)
{
	int ans=0;
	while(ind>0)
		ans+=bit[j][ind],ind-=ind&-ind;
	return ans;
}
void upd(int ind,int j,int val)
{
	while(ind<=n)
		bit[j][ind]+=val,ind+=ind&-ind;
}
signed main()
{
 	start_routine
 	int i,j;
	cin>>n>>k;
	k++;
	
	fr(i,1,n+1)cin>>a[i];
	
	fr(i,1,n+1)
	{
		upd(a[i],1,1);
		fr(j,2,k+1)
		{
			int val=sum(a[i]-1,j-1);
			upd(a[i],j,val);
		}
	}
	int ans=sum(n,k);
	
	cout<<ans<<"\n";
	end_routine
}



