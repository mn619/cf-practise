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

int n,m;
int x[5], y[5];


signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	cin>>tests;

	while(tests--)
	{
		cin>>n>>m;
		map <int, int> xmap, ymap;

		cin>>x[1]>>y[1]>>x[2]>>y[2];
		cin>>x[3]>>y[3]>>x[4]>>y[4];

		xmap[x[1]] = 0, xmap[x[2]] = 1;
		ymap[y[1]] = 0, ymap[y[2]] = 1;


		xmap[x[3]] = 0, xmap[x[4]] = 1;
		ymap[y[3]] = 0, ymap[y[4]] = 1;

		int area = n*m, warea = (x[2] - x[1])*(y[2] - y[1]), barea = (x[4] - x[3])*(y[4] - y[3]);

		sort(x+1, x+5);
		sort(y+1, y+5);

		int xx1 = x[2], xx2 = x[3], yy1 = y[2], yy2 = y[3];
		int carea;
		if( (xmap[xx1] == 1 && xmap[xx2] == 0)|| (ymap[yy1] == 1 && ymap[yy2] == 0) )
			care = 0;
		else carea  = (xx2 - xx1)*(yy2 - yy1);

		warea -= carea;

		int l
	}

 	//end_routine
}
