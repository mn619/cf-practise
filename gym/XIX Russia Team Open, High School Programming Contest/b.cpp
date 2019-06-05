#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

map <string,int> mp;
signed main()
{
	FILEIO
 	//start_routine
	string s;
	int c = 0;
	string start, end = "\\end{thebibliography}";
	while(getline(cin, s))
	{
		string temp = "\\begin{thebibliography}";
		bool ok = 1;
		int i;
		fr(i,0,22) if(s[i]!= temp[i]) {ok = 0;break;}
		if(ok) {start = s; break;}

		fr(i,0,s.size())
		{
			if(s[i] == '\\')
			{
				temp = "";
				int j = i + 6;
				while(s[j] != '}' && j < s.size())
				{
					temp += s[j];
					j++;
				}

				if(mp.count(temp)) continue;
				mp[temp] = c++;
			}
		}
	}

	string ans[100];
	bool ok = 1;
	int cnt = 0;

	while(getline(cin, s))
	{
		if(s == "\\end{thebibliography}") break;
		
		int i = 9;
		string temp = "";
		while(s[i] != '}'&& i<s.size())
		{
			temp += s[i];
			i++;
		}
		if(mp.count(temp) == 0) continue;
		if(mp[temp] != cnt) ok = 0;
		cnt++;
		ans[mp[temp]] = s;
	}
	int i;

	if(!ok)
	{
		cout<<"Incorrect\n";
		cout<<start<<'\n';
		fr(i,0,100){if(ans[i] == "")break; else cout<<ans[i]<<"\n";}
		cout<<end;
		return 0;
	}	
	cout<<"Correct";

 	//end_routine
}


// \cite{<reference>}  