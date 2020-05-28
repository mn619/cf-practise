#include<bits/stdc++.h>
#define pi 3.14159265359 
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

void solv(){
	int n;
	cin>>n;

	int k = n/2 + (n&1);
	long double y = 1/sqrt(2*(1 - cos(pi/n)));
	long double h = sqrt((1 - cos((k - 1)*pi/n))*2)*y;
	long double d = h/2 + cos((k - 1)*pi/(n*2))*y;
	long double ans = d*sqrt(2);

	cout<<fixed<<setprecision(15)<<ans<<'\n';
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