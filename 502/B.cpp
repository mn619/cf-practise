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
string a,b;

signed main()
{
 	//start_routine
 	cin>>n>>a>>b;
 	char s[n];

 	int i;
 	fr(i,0,a.size())
 	{
 		if(a[i] == '1' || b[i] == '1') s[i] = '1';
 		else s[i] = '0';
 	}
 	int cnto=0,cntz= 0,ans = 0;
 	fr(i,0,n)
 	{
 		if(a[i] == '1')
 		{
 			cnto++;
 		}
 		else cntz++;
 	}

 	fr(i,0,a.size())
 	{
 		cout<<s[i]<<" ";
 	}

 	fr(i,0,n)
 	{
 		if(b[i] == '0')
 		{
 			if(s[i] == '1')
 			{
 				ans+=cntz;
 				cnto--;
 			}
 			else 
 			{
 				ans+=cnto;
 				cntz--;
 			}
 		}
 	}
 	cout<<ans;
 	//end_routine
}



