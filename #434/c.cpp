#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;
bool bobel[26], isbob[30001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>s;

	bobel[0] = bobel['e' - 'a'] = bobel['i' - 'a'] = bobel['o' - 'a'] = bobel['u' - 'a'] = 1;

	fr(i, 1, s.size() + 1){
		isbob[i] = bobel[s[i - 1] - 'a'];
	}

	int n = s.size();
	int sum = 0;
	set <char> c;

	fr(i, 1, n + 1){
		if(isbob[i]){
			sum = 0;
			c.clear();
		}
		else{
			sum++;
			c.insert(s[i - 1]);

			if(sum > 2 and c.size() > 1){
				cout<<" ";
				sum = 1;
				c.clear();
				c.insert(s[i - 1]);
			}
		}
		//cout<<sum<<" "<<c.size()<<'\n';
		cout<<s[i - 1];
	}
}