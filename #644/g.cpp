#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

vector <string> f(int n, int m, int a, int b){
	vector <string> s(n);
	assert(n/b == m/a and n%b == 0 and m%a == 0);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(i/b == j/a) s[i] += '1';
			else s[i] += '0';
	return s;
}

int n, m, a, b;

void solv(){
	cin>>n>>m>>a>>b;

	if(n/b == m/a and n%b == 0 and m%a == 0){
		cout<<"YES\n";
		auto s = f(n, m, a, b);
		for(auto x: s) cout<<x<<'\n';
		return;
	}
	
	for(int k = 0; k < n/b and k < m/b; k++){
		int n1 = n - k*b, m1 = m - k*a;
		int a1 = n1 - a, b1 = m1 - a;
		if(a1 <= 0 or b1 <= 0 or a1 > n1 or b1 > m1) continue;

		if(n1%b1 == 0 and m1%a1 == 0 and n1/b1 == m1/a1){
			cout<<"YES\n";
			auto s1 = f(k*a, k*b, a, b), s2 = f(n1, m1, a1, b1);
			for(int i = 0; i < (int)s1.size(); i++){
				int l = m - (int)s1[i].size();
				cout<<s1[i];
				while(l--) cout<<'0';
				cout<<'\n';
			}

			for(int i = 0; i < (int)s2.size(); i++){
				int l = m - (int)s2[i].size();
				while(l--) cout<<"0";
				for(int j = 0; j < (int)s2[i].size(); j++){
					if(s2[i][j] == '1') cout<<'0';
					else cout<<'1';
				}
				cout<<'\n';
			}
			return;
		}
	}
	cout<<"NO\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int  t;
    cin>>t;

    while(t--) solv();
}