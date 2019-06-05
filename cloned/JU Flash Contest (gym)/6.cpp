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

int x1,x2,x3,x4,h;

signed main()
{
	//FILEIO
 	//start_routine
	cin>>x1>>x2>>x3>>x4>>h;
	if(x2 >= x4)
	{
		cout<<max((int)0, h*(x4 - max(x1,x3)));
		return 0;
	}
	else 
	{
		cout<<max((int)0, h*(x2 - max(x1, x3)));
		return 0;
	}

 	//end_routine
}
