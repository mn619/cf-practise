#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[51];

void solv(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}

	sort(a + 1, a + n + 1);

	int ans = (int)10000000000;
	for(int i = 2; i <= n; i++) ans = min(ans, a[i] - a[i - 1]);

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