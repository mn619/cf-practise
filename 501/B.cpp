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
 	string s,t;
 	cin>>n>>s>>t;
 	if(s==t)return cout<<0,0;
 	vector <int> scnt[26], tcnt[26] ;
 	int i;
 	fr(i,0,n)
 	{
 		scnt[s[i]-'a'].pb(i);
 		tcnt[t[i]-'a'].pb(i);
 	}

 	fr(i,0,26)
 	{
 		if(scnt[i].size() != tcnt[i].size())return cout<<-1,0;
 	}

 	vector <int> ans;

 	fr(i,0,n)
 	{
 		int j;
 		fr(j,i,n)
 		{
 			if(s[j]==t[i])break;
 		}
 		int k;
 		for(k = j-1;  k>=i; k--)
 		{
 			char temp = s[k];
 			s[k]= s[k+1];
 			s[k+1]=temp;
 			ans.pb(k);
 		}
 		
 	}
 	cout<<ans.size()<<"\n";
 	fr(i,0,ans.size())
 	{
 		cout<<ans[i]+1<<" ";
 	}

 	//end_routine
}



