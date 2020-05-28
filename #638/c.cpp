#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
int n, k;
string s;

bool comp(string x, string y){
	int ind = 0;
	int a = x.size(), b = y.size();
	while(ind < min(a, b) and x[ind] == y[ind]) ind++;
	
	if(ind == a) return true;
	else if(ind == b) return false;

	return x[ind] < y[ind];
}

void solv(){
	cin>>n>>k>>s;
	// return;


	sort(s.begin(), s.end());
	bool ok = 1;
	for(int i = 0; i < n; i++){
		if(s[i] != s[0]) ok = 0;
	}

	if(ok){
		string ans;
		int l = n/k + (n%k != 0);
		for(int i = 0; i < l; i++) ans += s[0];
		cout<<ans<<'\n';
		return;
	}

	ok = 1;
	for(int i = 1; i < k; i++) if(s[i] != s[0]) ok = 0;

	if(!ok){
		cout<<s[k - 1]<<'\n';
		return;
	}
	else{
		ok = 1;
		for(int i = k; i < n; i++) if(s[i] != s[k]) ok = 0;
		string ans = "";
		if(ok){
			ans += s[0];
			int l = (n - k)/k  + (n%k != 0);
			for(int i = 0; i < l; i++) ans += s[k];
		}
		else{
			ans += s[0];
			for(int i = k; i < n; i++) ans += s[i];
		}
		cout<<ans<<'\n';
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