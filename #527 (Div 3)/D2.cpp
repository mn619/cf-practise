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

signed main()
{
	//FILEIO
 	//start_routine
	
	int n;
	cin>>n;
	int a[n + 1];
	int i;
	priority_queue <pair<int, int>> pq;
	map <int,int> hcnt;

	fr(i,1,n +1)
	{
		cin>>a[i];
		pq.pb(-a[i]);
		hcnt[a[i]]++;
	}
	int ans = 1;
	while(!pq.empty())
	{
		pair <int, int> e1 = pq.top(), e2;
		pq.pop();
		if(pq.empty())
		{
			ans = 0;
			break;
		}
		e2 = pq.top();
		pq.pop();
		if(e2.sc != e1.sc + 1 || e1.fs != e2.fs)
		{
			ans = 0;
			break;
		}
		hcnt[-e1.fs]--;
		hcnt[-e2.fs]--;

		hcnt[-e1.fs+ 1]++;
		hcnt[-e2.fs + 1]++;
		pq.push({e1.fs - 1, e1.sc});
		pq.push({e2.fs - 1, e2.sc});

		if(hcnt(-e1.fs + 1) == 1) 
		{
			break;
		}
	}
	if(ans)cout<<"YES";
	else cout<<"NO";

 	//end_routine
}
