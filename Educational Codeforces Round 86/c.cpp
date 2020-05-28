#include<bits/stdc++.h>
#define int long long
#define maxn 1000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int a, b, q;

void solv(){
	cin>>a>>b>>q;
	if(a > b) swap(a, b);

	// for(int i = 1; i <= maxn; i++){
	// 	if((i%a)%b == (i%b)%a) cout<<i<<'\n';
	// }

	int lcm = a*b/__gcd(a, b);

	for(int i = 1; i <= q; i++){
		int l, r;
		cin>>l>>r;

		int x = (l/lcm)*lcm;
		int y = (r/lcm)*lcm;

		if(x + b - 1 >= r) {
			cout<<0<<" ";
			continue;
		}

		if(x == y) {
			cout<<(r - l + 1) - max((int)0, x + b - 1 - (l - 1))<<' ';
			continue;
		}

		int ans = max((int)0, x + b - 1 - (l - 1));
		x += lcm;
		ans += (((y - x))/lcm)*b;
		if(y + b - 1 >= r) ans += r - y + 1;
		else ans += b;
		cout<<r - l + 1 - ans<<' ';
	}
	cout<<'\n';
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