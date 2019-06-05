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
#define FILEIO freopen("C:/Users/Aman/Desktop/kachda/input.txt", "r", stdin); freopen("C:/Users/Aman/Desktop/kachda/output.txt", "w", stdout);

using namespace std;

signed main()
{
	//FILEIO
 	//start_routine
 	
	string s;
	cin>>s;
	int n = s.size();
	int ans = 0;

	int i;
	bool ok0 = 0, ok1 = 0;

	int l = -1, r = -1;
	fr(i,0,n)
	{

		if(s[i] == '[' && !ok0)
		{
			ok0 = 1;
			continue;
		}
		if(!ok0) {ans++; continue;}

		if(s[i] == ':' && !ok1)
		{
			ok1 = 1;
			l = i;
			break;
		}
		if(!ok1) {ans++; continue;}
		l = i;
		break;
	}
	if(l == -1) return cout<<-1,0;


	ok0 = 0, ok1 = 0;
	for(i = n - 1; i > l; i--)
	{
		if(s[i] == ']' && !ok0)
		{
			ok0 = 1;
			continue;
		}

		if(!ok0)
		{
			ans++;
			continue;
		}

		if(s[i] == ':' && !ok1)
		{
			ok1 = 1;
			r = i;
			break;
		}

		if(!ok1)
		{
			ans++;
			continue;
		}
		
		r = i;
		break;
	}

	if(r == -1) return cout<<-1, 0;
	fr(i,l + 1, r)
	{
		if(s[i] != '|') ans++;
	}

	cout<<n - ans;

 	//end_routine
}