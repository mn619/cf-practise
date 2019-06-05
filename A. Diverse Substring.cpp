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

int n, cnt[26] = {0};
string s;

signed main()
{
	//FILEIO
 	//start_routine
	
	int tests = 1;
	//cin>>tests;

	int l = -1,r = -1;
	while(tests--)
	{
		cin>>n>>s;

		int i;
		fr(i,0,n)
		{
			int mx = 0;
			int j;
			fr(j,i,n)
			{
				cnt[s[j]-'a']++;
				mx = max(mx, cnt[s[j]-'a']);
				if(2*mx <= (j-i+1))
				{
					l = i, r = j;
					break;
				}
			}
			if(l!=-1) break;

			fr(j,0,26) cnt[j] = 0;
		}
		
		if(l == -1)
		{
			return cout<<"NO",0;
		}

		cout<<"YES\n";
		fr(i,l,r+1)
		{
			cout<<s[i];
		}

		return 0;
	}

 	//end_routine
}
		