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
int n;
string sl[101],sn[101];
int cntl[9]={0},cntn[9]={0};
int f(string s)
{
	if(s=="M")return 0;
	if(s=="S")return 1;
	if(s=="XS")return 2;
	if(s=="XXS")return 3;
	if(s=="XXXS")return 4;
	if(s=="L")return 5;
	if(s=="XL")return 6;
	if(s=="XXL")return 7;
	if(s=="XXXL")return 8;
}
signed main()
{
 	//start_routine
 	cin>>n;
 	int i;
 	fr(i,0,n)cin>>sl[i];
 	fr(i,0,n)cin>>sn[i];

 	fr(i,0,n)
 	{
 		cntl[f(sl[i])]++;
 		cntl[f(sn[i])]--;
 	}

 	int ans=0;
 	fr(i,0,9)
 	{
 		ans+=abs(cntl[i]);
 	}
 	cout<<ans/2;


	//end_routine
}



