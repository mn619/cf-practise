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

int n,a,b,s;

signed main()
{
	//FILEIO
 	//start_routine
	
	cin>>n>>a>>b>>s;
	int ans = 1;
	if(a > b) ans = 0;
	if(s < (n - 1)*a + b) ans=  0;
	if(s > (n - 1)*b + a)ans = 0;
	if(ans)cout<<"YES";
	else cout<<"NO";
 	//end_routine
}