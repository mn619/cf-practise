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
string s1,s2;
signed main()
{
 	//start_routine
 	cin>>s1>>s2;
 	int n=s1.size();
 	int i,ans=0;
 	//cout<<s1<<"\n"<<s2;
 	bool in[n]={0};
 	fr(i,0,n)
 	{
 		if(s1[i]=='0'&&s2[i]=='0')
 		{
 			
 			if(!in[i])
 			{
 				
 			if(i+1<n && !in[i+1]&&!in[i])
 			if((s1[i+1]=='0'&&s2[i+1]=='X')||(s1[i+1]=='X'&&s2[i+1]=='0'))ans++,in[i+1]=1,in[i]=1;
			if(i-1>=0&&!in[i-1]&&!in[i])
			{
				if((s1[i-1]=='0'&&s2[i-1]=='X')||(s1[i-1]=='X'&&s2[i-1]=='0'))ans++,in[i]=1,in[i-1]=1;
			}
			if(i+1<n&&!in[i+1]&&!in[i])
			{
				if(s1[i+1]=='0'&&s2[i+1]=='0')ans++,in[i]=1,in[i+1]=1;
			}
			}
		}
	}
	cout<<ans;
	//end_routine
}



