#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, k;

void solv(){
	cin>>n>>k;
	int ans = 0;
	for(int i = 1; i*i <= n and i <= k; i++){
		if(n%i != 0) continue;
		if(ans < i){
			ans = i;
		}
		int d = n/i;
		if(d <= k){
			ans = max(ans, d);
		}
	}	

	assert(ans);
	cout<<n/ans<<'\n';
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