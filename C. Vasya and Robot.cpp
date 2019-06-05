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

int n, xf,yf;
char c[200001];

int xstep(char c)
{
	if(c == 'R') return 1;
	if(c == 'L') return -1;
	return 0;
}

int ystep(char c)
{
	if(c == 'U') return 1;
	if(c == 'D') return -1;
	return 0;
}
signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	while(tests--)
	{
		c[0] = 'A';
		cin>>n;

		int i,x = 0,y = 0;
		fr(i,1,n+1)
		{
			cin>>c[i];
			if(c[i] == 'U') y++;
			if(c[i] == 'R') x++;
			if(c[i] == 'L') x--;
			if(c[i] == 'D') y--;
		}

		cin>>xf>>yf;
		if(x+y > n)
		{
			return  cout<<-1,0;
		}

		int xd = xf - x, yd = yf - y;
		int l = 0, r = n, ans;
		cout<<xd<<" "<<yd<<'\n';
		while(l<=r)
		{
			int mid = (l+r)>>1;
			int L = 0, R = 0, U = 0, D = 0;
			bool bb = 0;
			fr(i,1,n+1)
			{
				if(i>=mid)
				{
					if(c[i] == 'U') U++;
					if(c[i] == 'D') D++;
					if(c[i] == 'R') R++;
					if(c[i] == 'L') L++;

					if(c[i-mid] == 'U') U--;
					if(c[i-mid] == 'D') D--;
					if(c[i-mid] == 'R') R--;
					if(c[i-mid] == 'L') L--;

					if(2*L >= 	)
				}
			}

			if(bb)
			{
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout<<ans<<'\n';


	}

 	//end_routine
}
