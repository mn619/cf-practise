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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int a[n+1];
	int i, temp = 0;
	fr(i,1,n+1) cin>>a[i];
	if(n==1) return cout<<a[1]<<"\n",0;
	if(n==2)
	{
		int temp = a[1]-a[2];
		if(temp>=0) return cout<<temp<<"\n",0;
		else return cout<<-temp<<"\n",0;
	}

	fr(i,1,n+1)
	{
		if(abs(a[i])<abs(a[temp])) temp = i;
	}
	int l = temp-1, r = temp+1, ans = a[temp];
	while(l>=1 || r<=n)
	{
		if(l>=1 && r<=n)
		{
			int temp1 , temp2;
			temp1 = max(a[l]-ans, ans-a[l]);
			temp2 = max(a[r]-ans, ans-a[r]);
			if(temp1 >= temp2) {l--,ans = temp1; }
			else {r++, ans=temp2;}
		}
		else if(l>=1)
		{
			ans=max(ans-a[l], a[l]-ans);
			l--;
		}
		else if(r<=n)
		{
			ans=max(ans-a[r], a[r]-ans);
			r++;
		}
		
	}
 	cout<<ans<<"\n"; 	
 	//end_routine
}



