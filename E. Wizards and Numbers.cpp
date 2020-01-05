#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define inf 1000000000000000000
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

bool check(int a, int b){
	if(a > b) swap(a, b);
	if(a == 0) return 0;

	// cout<<a<<" "<<b<<"\n";
	if(check(a, b%a) == 0) return 1;
	return 0;
}

void solv(){
	int a, b;
	cin>>a>>b;
	if(a > b) swap(a, b);

	int p = a;
	
	bool ans = check(a, b);
	cout<<ans<<" ";
	while(b - p >= 0){
		cout<<check(a, b - p)<<" ";
		if(check(a, b - p) == 0){ans=1; break;}
		if(p <= b/a + (b%a)){
			p *= a;
		}
		else break;
	}

	if(ans) cout<<"First\n";
	else cout<<"Second\n";
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	
 	int t ;

 	cin>>t;
 	while(t--) solv();	
}