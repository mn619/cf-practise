#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s, t;
bool b[100001];
int dp[100001], p;

vector<int> prefix_function(string s) {
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
    return pi;
}

bool check(int ind){
	int l = t.size();
	fr(j, 0, t.size()){
		if(s[ind - j] != t[l - j - 1] and s[ind - j] != '?') return 0;
	}
	return 1;
}

int cnt(int ind){
	string x = t;
	reverse(x.begin(), x.end());
	int lt = t.size();

	int pos = lt - p - 1;

	fr(j, 0, t.size()){
		if(ind - lt - j < 0) break;
		if(s[ind - lt - j] == '?') x += t[pos];
		else x += s[ind - lt - j];
		pos--;
		if(pos < 0) pos = lt - p - 1;
	} 

	reverse(x.begin(), x.end());
	x = t + '$' + x;
	auto v = prefix_function(x);
	int ans = 0;
	int l = x.size();

	fr(j, 0, lt){
		if(v[x.size() - j - 1] >= t.size()) ans++;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>s>>t;

	auto v = prefix_function(t);
	p = v[t.size() - 1];
	

	int ans = 0;
	if(check(t.size() - 1)){ ans = 1; dp[t.size() - 1] = 1;}
	

	fr(i, t.size(), s.size()){
		if(check(i)){
			dp[i] = dp[i - t.size()] + cnt(i);
		}
		else{
			dp[i] = dp[i - 1];
		}
		ans = max(ans, dp[i]);
	}
	cout<<ans;

}