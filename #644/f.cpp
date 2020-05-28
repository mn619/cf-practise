#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m;
string a[10];

void solv(){
	cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>a[i];

	for(int i = 0; i < 26; i++){
		for(int j = 0; j < m; j++){
			string s = a[0];
			s[j] = (char)'a' + i;
			bool ok = 1;

			for(int k = 0; k < n; k++){
				int c = 0;
				for(int l = 0; l < m; l++){
					c += (s[l] != a[k][l]);
				}

				if(c > 1){
					ok = 0;
					break;
				}
			}
			if(ok){
				cout<<s<<'\n';
				return;
			}
		}

	}

	cout<<"-1\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t ;
    cin>>t;

    while(t--) solv();
}