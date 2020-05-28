#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, k, p[62] = {1};

void solv(){
	cin>>n>>m;
	k = (p[m] - n - 1)>>1;

	vector <int> vals;

	for(int i = 1; i <= n; i++){
		string s;
		cin>>s;

		int a = 0;
		for(int j = 0; j < (int)s.size(); j++){
			a = 2*a + (s[j] == '1');
		}

		vals.push_back(a);
	}

	int num = -1;
	int l = 0, r = p[m] - 1;

	while(l <= r){
		int mid = (l + r)>>1;
		int c = 0;
		for(int i = 0; i < n; i++){
			c += vals[i] < mid;
		}

		if(mid - c <= k){
			num = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}	

	assert(num != -1);

	string ans;
	while(num){
		if(num&1) ans += '1';
		else ans += '0';
		num /= 2;
	}

	while((int)ans.size() < m)
		ans += '0';
	
	reverse(ans.begin(), ans.end());
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    for(int i = 1; i <= 61; i++) p[i] = 2*p[i - 1];
    int t;
    cin>>t;

    while(t--) solv();
}