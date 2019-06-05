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
int n,k;
string s,t;
signed main()
{
 	//start_routine
 	cin>>n>>k>>s;
 	int i,  len=0;
 	fr(i,0,n)
 	{
 		int k=0,j;
 		bool b = 1;
 		fr(j,i+1,n)
 		{
 			if(s[j] != s[k]) {b=0; break;}
 			k++;
 		}
 		if(b) {len = k; break;}
 	}
 	cout<<s;
 	k--;
 	while(k--)
 	{
 		fr(i,len,n)cout<<s[i];
 	}
 	//end_routine
}



