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
string s;

signed main()
{
 	//start_routine
	cin>>n>>k>>s;

	int i;
	int cnt[26]={0};
	fr(i,0,s.size())
	{
		cnt[s[i]-'a']++;
	}
	//fr(i,0,26)cout<<cnt[i]<<" ";
	int ans=0;
	bool b = 0;
	i=0;

	i= 0;
	while(cnt[i]==0)
	{
		 i++;
	}
	
	int j = i;
	int in=0;
	int temp = -2;
	for(j=i; j<26; j++)
	{
		if(cnt[j]!=0 && j>temp+1)
		{
			in++;
			ans+=j+1;
			if(in==k)break;
			temp=j;
		}
		
	}
	if(in<k)cout<<-1;
	else cout<<ans;
 	//end_routine
}



