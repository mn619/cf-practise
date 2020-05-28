#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k, a[31], b[31];

void solv(){
	cin>>n>>k;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++) cin>>b[i];


	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(i <= k){
			ans += max(a[i], b[i]);
		}
		else ans += a[i];
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