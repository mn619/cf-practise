#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

void solv(){
	int n, m, k;
	cin>>n>>m>>k;

	if(m <= n/k){
		cout<<m<<'\n';
		return;
	}
	int rem = m - n/k;
	int d = (rem + k - 2)/(k - 1);
	int ans = (n/k) - d;
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t = 1;
    cin>>t;

    while(t--) solv();
}