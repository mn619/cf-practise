#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
int caseno = 0;

vector<int> prefix_function(string a, string b) {
	string s = a + '$' + b;

    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    vector <int> ans(b.size());
    for(int i = 0; i < b.size(); i++){
    	ans[i] = pi[i + a.size() + 1]; 
    }

    return ans;
}

void solve(){
	string s, t;
	cin>>s>>t;

	vector<int> vs = prefix_function(t, s), vt = prefix_function(s, t);

	int ans = 0;
	fr(i, 0, t.size()){
		int lt = vt[i];
		int ls = vs[i];
		if(lt + ls >= i + 1) ans = i + 1;
	}

	cout<<"Case "<<++caseno<<": "<<ans<<"\n";
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	int tests;
	cin>>tests;
	while(tests--){
		solve();
	} 		
}