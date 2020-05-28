#include<bits/stdc++.h>
#define inf 10000000000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k;
string s;

void solv(){
	cin>>n>>k>>s;

	vector <int> a(k), b(k);
	int cnta =  0, cntb = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == '0') b[i%k]++, cntb++;
		else a[i%k]++, cnta++;
	}

	int ans = inf;
	for(int i = 0; i < k; i++){
		vector <int> p;
		p.push_back(0);
		for(int j = i; j < n; j += k){
			int pref = p[(int)p.size() - 1] + (s[j] == '1');
			p.push_back(pref);
		}

		int temp = p[(int)p.size() - 1];
		int ans1 = p[(int)p.size() - 1];
		int minval = inf;
		for(int j = 1; j < (int)p.size(); j++){
			minval = min(minval, 2*p[j - 1] - (j - 1));
			ans1 = min(ans1, temp - 2*p[j] + j + minval);
		}

		ans = min(ans, ans1 + cnta - a[i]);
	}
	cout<<ans<<'\n';
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