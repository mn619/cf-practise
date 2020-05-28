#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, cnt[200001];

void solv(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		int e;
		cin>>e;
		cnt[e]++;
	}

	int ans = 0, in = 0;

	for(int i = 1; i <= n; i++){
		ans += (cnt[i] + in)/i;
		in = (cnt[i] + in)%i;
	}
	
	for(int i = 1; i <= n; i++){
		cnt[i] = 0;
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