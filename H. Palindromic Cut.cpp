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
string s;
signed main()
{
 	//start_routine
 	cin>>s;
 	int i;
 	map <char,int> cnt;
 	fr(i,0,n)cnt[s[i]-'a']++;
 	map <char,int> :: iterator it = cnt.begin();
 	while(it!=cnt.end())
 	{
 		if(it->second % 2 == 1)o++;
 		it++;
 	}
 	if(n%o!=0)
	//end_routine
}



