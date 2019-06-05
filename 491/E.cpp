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
string s;
bool comp(vector <int> a,vector <int> b)
{
	if(a[0]<b[0])return false;
	return true;
}
signed main()
{
 	//start_routine
 	cin>>s;
 	vector <int> a[10];
 	int i;
 	fr(i,0,10)
 	{
 		a[i].pb(0);
 		a[i].pb(i);
	}
 
 	fr(i,0,s.size())
 	{
 		a[s[i]-'0'][0]++;
	}
	sort(a,a+10,comp);
	cout<<a[0][1];
	int len=0;
	fr(i,0,10)if(a[i][0]>0)len++;
	cout<<len;
	
	//end_routine
}



