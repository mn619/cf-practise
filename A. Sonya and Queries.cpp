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
int num,cnt[1048577]={0};

inline int f(int n)
{
	int k=1,ans=0;
	while(n!=0)
	{
		ans+=k*((n%10)%2);
		k*=2;
		n/=10;
	}
	return ans;
}
int f(string s)
{
	int len=s.size();
	
	int i,ans=0,k=1;
	fr(i,0,len)
	{
		ans+=(s[i]-'0')*k;
		k*=2;
	}
	return ans;
}
signed main()
{
 	start_routine
 	
 	int t;
 	cin>>t;
 	char c;
 	string s;

 	while(t--)
 	{
 		cin>>c;
 		if(c=='+')
 		{
 			cin>>num;
 			cnt[f(num)]++;
 		}
 		else if(c=='-')
 		{
 			cin>>num;
 			cnt[f(num)]--;
 		}
 		else
 		{
 			cin>>s;
 			reverse(s.begin(),s.end());
 			cout<<cnt[f(s)]<<"\n";
 		}
 	}
 	end_routine
}



