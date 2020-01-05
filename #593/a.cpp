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
	int a,b,c;
 	cin>>a>>b>>c;
	int ans1 = 0, ans2 = 0;
	
	int t = min(b, c/2);
	ans1 += 3*t;
	t = min(a, (b-t)/2);
	ans1 += 3*t;
 	

 	t = min(a, b/2);
 	ans2 += 3*t;
 	t = min(b - 2*t, c/2);
 	ans2 += 3*t;
 	cout<<max(ans1, ans2)<<'\n';
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int tes;
 	cin>>tes;

 	while(tes--){
 		solv();
 	}
 	
}