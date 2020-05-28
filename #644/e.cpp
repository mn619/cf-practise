#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


int n;
string s[51];

void solv(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		reverse(s[i].begin(), s[i].end());
		s[i] += '%';
		reverse(s[i].begin(), s[i].end());
	}


	bool ok = 1;

	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			if(s[i][j] == '0') continue;
			if(s[i][j + 1] == '0' and s[i + 1][j] == '0') ok = 0;
		}
	}

	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
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