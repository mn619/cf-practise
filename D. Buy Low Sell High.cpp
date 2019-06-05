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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

int n;
int p[300001];

signed main()
{
	//FILEIO
 	//start_routine
	cin>>n;
	int i;
	set <int> s;
	priority_queue <int> pq;
	int ans = 0;

	fr(i,1,n+1)
	{
		int x;
		cin>>x;
		pq.push(-x);
		if(!pq.empty())
		{
			if(-pq.top() < x) ans += x + pq.top(), pq.pop(), pq.push(-x);
		}	
	}
	cout<<ans<<"\n";


 	//end_routine
}
