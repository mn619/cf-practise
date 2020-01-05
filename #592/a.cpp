#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;


void solv(){
	int a, b, c, d, k;
	cin>>a>>b>>c>>d>>k;

	int x = a/c + (a%c != 0), y = b/d + (b%d!=0);
	if(x + y > k) cout<<-1<<'\n';
	else cout<<x<<" "<<y<<"\n";
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