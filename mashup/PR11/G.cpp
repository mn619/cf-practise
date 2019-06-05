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
	int n;
	cin>>n;
	char c[7]={'R','O','Y','G','B','I','V'};
	int i;
	int x=n/7;
	x*=7;
	fr(i,1,x+1)
	{
		cout<<c[i%7];
	}
	if(n%7==1)
	{
		cout<<c[4];
	}
	if(n%7==2)
	{
		cout<<c[4]<<c[5];
	}
	if(n%7==3)
	{
		cout<<c[4]<<c[5]<<c[6];
	}
	if(n%7==4)
	{
		cout<<c[4]<<c[5]<<c[6]<<c[0];
	}
	if(n%7==5)
	{
		cout<<c[4]<<c[5]<<c[3]<<c[6]<<c[4];
	}
	if(n%7==6)
	{
		cout<<c[4]<<c[5]<<c[1]<<c[2]<<c[3]<<c[4];
	}

	//end_routine
}



