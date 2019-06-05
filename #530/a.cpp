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
	
	int w,h,u1,d1,u2,d2;

	cin>>w>>h>>u1>>d1>>u2>>d2;
	if(d1 < d2)
	{
		swap(u1,u2);
		swap(d1,d2);
	}

	bool in = 0;
	for(int i = h; i>=0; i--)
	{
		w += i;
		if(in == 0)
		{
			if(d1 == i)
			{
				w -= u1;
				in = 1;
			}
			
		}
		else
		{
			if(d2 == i)
			{
				w -= u2;
			}
		}
		if(w < 0) w = 0;
	}
	cout<<w;

 	//end_routine
}
