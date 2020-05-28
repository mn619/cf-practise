#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

void solv(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;

	if(a <= b){
		cout<<b<<"\n";
		return;
	}

	if(c <= d){
		cout<<"-1\n";
		return;
	}

	a -= b;
	int k = a/(c - d) + (a%(c - d) != 0);
	int ans = b + c*k;
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