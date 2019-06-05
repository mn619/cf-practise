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

	int q;
	cin>>q;
	int l = 1, r = 0;
	map <int, int> m;

	bool bb = 1;
	while(q--)
	{
		char c;
		cin>>c;
		int id;
		if(c == 'L')
		{
			cin>>id;
			m[id] = --l;
		}
		else if(c == 'R')
		{
			cin>>id;
			m[id] = ++r;
		}
		else
		{
			cin>>id;
			cout<<min(m[id]-l, r-m[id])<<"\n";
		}
	}
 
 	//end_routine
}
