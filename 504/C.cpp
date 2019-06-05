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
int n,m;
string s,t;

signed main()
{
 	//start_routine
 	cin>>n>>m>>s>>t;
 	if(n-1>m) {cout<<"No\n"; return 0;}
 	int i, pos = -1;

 	fr(i,0,n) if(s[i] == '*'){pos =i; break;}
 	if(pos==-1)
 	{
 		if(s == t) cout<<"YES\n";
 		else cout<<"NO\n";
 		return 0;
 	}
 	else
 	{
 		fr(i,0,pos)
 		{
 			if(s[i]!=t[i]) 
 			{
 				cout<<'\n';
 				cout<<"NO\n";
 				return 0;
 			}
 		}
 		int j = m-1;
 		for(i=n-1;i>pos; i--)
 		{
 			if(s[i]!=t[j])
 			{
 				cout<<"NO\n";
 				return 0;
 			}
 			j--;
 		}

 		cout<<"YES\n";
 	}
 	//end_routine
}



