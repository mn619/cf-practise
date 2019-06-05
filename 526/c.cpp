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
	string s;
	cin>>s;
	int l = 0;
	int ans = 1;
	int i;

	fr(i,0,s.size())
	{
		if(s[i] == 'a')
		{
			l++; 
		}
		else if(s[i] == 'b')
		{
			ans*=(l + 1);
			ans %= mod;
			l = 0;
		}
	}
	ans*=(l + 1);
	ans %= mod;
	ans = (mod + ans)%mod;
	cout<<ans - 1<<'\n';

 	//end_routine
}
