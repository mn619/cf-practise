#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

void solv(){
	string s;
	cin>>s;

	int steps = s.size() - 2;

	set <int> c;
	for(auto x: s) c.insert(x);

	if(s.size() == 2){
		cout<<"Bash\n";
	}
	else{
		steps -= (s[0] == s[s.size() - 1]);
		steps %= 2;

		if(steps == 0){
			cout<<"Bash\n";
		}
		else cout<<"Chipaku\n";
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;

 	while(t--) solv();

}