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

int power(int a,int b, int m)
{
	if (b==0)
	return 1;
	int temp = power(a,b/2,m);
	temp = (temp*temp)%m;
	if (b&1)
	return (temp*(a%m))%m; 
	return temp;
}
signed main()
{
	FILEIO
 	//start_routine
	cout<<power(0,0,mod);

 	//end_routine
}
