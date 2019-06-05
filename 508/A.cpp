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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,k, ans = 0;
	cin>>n>>k;
	string s;
	cin>>s;

	int cnt[26] = {0};
	int i;
	fr(i,0,n)
	{
		cnt[s[i]-'A']++;
	}
 	int c = 1000000;
 	int z[k]={0};
 	fr(i,0,n)
 	{
 		int x = s[i]-'A';
 		if(x<k) z[x]++;
 	}

 	fr(i,0,k)
 	{
 		if(z[i]<c) c= z[i];
 	}
 	cout<<k*(c);
 	//end_routine
}



