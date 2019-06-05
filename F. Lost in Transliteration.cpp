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
set <string> s;
string f(string x)
{
	string ans="";
	int l=x.size(),i;
	fr(i,0,l)
	{
		if(x[i]=='k' && x[i+1]=='h')
		{
			ans.insert(ans.size(),"h");
			i++;
		}
		else if(x[i]=='u')
		{
			ans.insert(ans.size(), "oo");
		}
		else ans.insert(ans.end(), x[i]);
	}
	return ans;
}
signed main()
{
 	start_routine
	cin>>n;
	int i;
	string x;
	fr(i,0,n)
	{
		cin>>x;
		string temp = f(x);
		while(temp!=x)
		{
			x=temp;
			temp=f(x);
		}
		s.insert(x);
	}
	cout<<s.size();
	end_routine
}



