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
int n;
string a,b;

signed main()
{
 	//start_routine
	cin>>n>>a>>b;

	int i=1;
	int len = n;
	n--;
	int ans= 0;
	fr(i,0,(len+1)/2)
	{
		if(a[i] == b[i] && a[n-i] == b[n-i]) continue;
		if(a[i] == b[n-i] && a[n-i] == b[i]) continue;
		if(i!=n-i)
		{
			if(a[i] == a[n-i] && b[n-i] == b[i]) continue;
		}

		int cnt = 2;
		if(i==n-i)cnt--;
		if(a[n-i] == b[n-i]) cnt--;
		else if(a[i] == b[i]) cnt--;
		else if(b[i] == b[n-i] && i!=n-i)cnt--;
		else if(a[n-i] == a[i] && i!=n-i) cnt--;
		else if(a[i] == b[n-i]) cnt--;
		else if(a[n-i] == b[i]) cnt--;
		cout << i <<" "<< cnt <<'\n';
		ans+=cnt;
	}

	cout<<ans;
 	//end_routine
}