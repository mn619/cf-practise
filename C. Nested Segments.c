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
#define print(xxx,a,b) for(int i=a;i<b;i++)cerr<<xxx[i]<<" ";
using namespace std;

int n,l[300011],ri[300011],bit[300011]={0};
vector <int> r[300001];
bool comp(vector <int> &r1,vector <int> &r2)
{
	if(r1[0]==r2[0])return l[r1[1]]>l[r2[1]];
	return (r1[0]<r2[0]);
}
inline int add(int ind)
{
	int x=l[ind]-1;
	int ans=0;
	while(x>0)
	{
		ans+=bit[x];
		x-=x&-x;
	}
	return ans;
}
inline void upd(int ind)
{
	int x=l[ind];
	while(x<=n)
	{
		bit[x]++;
		x+=x&-x;
	}
}

inline int solve()
{
	int i;
	int ans;
	fr(i,0,n)
	{
		ans=add(r[i][1]);
		if(i-ans!=0)return r[i][1];
		upd(r[i][1]);
	}
	return -1;
}

signed main()
{
 	start_routine
 	int i;
 	cin>>n;
 	fr(i,0,n)
 	{
 		cin>>l[i]>>ri[i];
 		r[i].pb(ri[i]);
 		r[i].pb(i);
 	}
 	sort(r,r+n,comp);
 	vector <int> compressL[n];
 	fr(i,0,n)compressL[i].pb(l[i]),compressL[i].pb(i);
 	sort(compressL,compressL+n);
 	int j=1;
 	l[compressL[0][1]]=1;
 	fr(i,0,n)
 	{
 		if(i>0)
 		{	
 			if(compressL[i][0]>compressL[i-1][0]&&i>0)l[compressL[i][1]]=++j;
 			else l[compressL[i][1]]=j;
 		}
 	}

 	int ans=solve(),ans2;
 	if(ans==-1)return cout<<-1<<" "<<-1,0;
 	fr(i,0,n)
 	{
 		if(i==ans)continue;
 		if(l[i]>=l[ans]&&ri[i]<=ri[ans]){ans2=i; break;}
 	}
 	cout<<ans2+1<<" "<<ans+1;
	end_routine
}

