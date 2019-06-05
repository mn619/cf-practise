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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

signed main()
{
	//FILEIO
 	//start_routine
	
	string s;
	int k;
	cin>>s>>k;
	int a = 0, b = 0;
	int i;
	fr(i,0,s.size())
	{
		if(s[i] == '*') a++;
		if(s[i] == '?') b++;
	}

	int n = s.size() - (a + b);
	if(k < s.size() - (a + b + b + a)) return cout<<"Impossible",0;
	if(a == 0 && k > n) return cout<<"Impossible",0;

	if(k > n)
	{
		bool ok = 0;
		fr(i,0,s.size())
		{
			if(s[i] != '?' && s[i] != '*') cout<<s[i];
			if(s[i] == '*' && !ok)
			{
				char c = s[i - 1];
				int t = k - n;
				while(t--) cout<<c;
				ok = 1;
			}
		}
	}
	else if(k < n)
	{	int d = n - k;
		fr(i,0,s.size())
		{
			if( (s[i + 1] == '?' || s[i + 1] == '*') && i + 1 < s.size() && d > 0)
			{
				d--; continue;
			}
			if(s[i] != '?' && s[i] != '*') cout<<s[i];
		}
	}
	else
	{
		fr(i,0,s.size())
		{
			if(s[i] != '*' && s[i]!='?') cout<<s[i];
		}
	}

 	//end_routine
}
