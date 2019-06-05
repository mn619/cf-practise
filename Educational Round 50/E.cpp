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

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;

	set < pair<int,int> >  s;
	while(n--)
	{
		int x1, x2, y1, y2;
		cin>>x1>>y1>>x2>>y2;

		int g = gcd(abs(y2-y1), abs(x2-x1));
		int xi = x1, yi = y1;
		int dx = (x2-x1)/g, dy = (y2-y1)/g;

		while(1)
		{
			if(s.count({xi,yi}) == 0)s.insert({xi,yi});
			if(xi == x2 && yi == y2) break;
			xi+=dx, yi+=dy;
		}
	}
	cout<<s.size();
 
 	//end_routine
}



