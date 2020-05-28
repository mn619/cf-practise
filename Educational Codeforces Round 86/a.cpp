#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int x, y, a, b;

void solv(){
	cin>>x>>y>>a>>b;
	if(x > y) swap(x, y);
	int ans;
	if(b <= 2*a){
		ans = (y - x)*a + x*b;
	}
	else{
		ans = (x + y)*a;
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