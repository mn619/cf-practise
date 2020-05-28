#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[51];

void solv(){
	cin>>n;

	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	int o = 0, e = 0;
	for(int i = 1; i <= n; i++){
		if(a[i]&1)o++;
		else e++;
	}

	if(e&1){
		bool ok = 0;
		for(int i  = 2; i <= n; i++){
			if((a[i]&1) != (a[i - 1]&1) and a[i] == a[i - 1] + 1){
				ok = 1;
			}
		}

		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
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