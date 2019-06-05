#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


int sum(int a){
	int ans = 0;
	while(a){
		ans += a%10;
		a /= 10;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int n;
 	cin>>n;

 	int t = n, p = 1, a = 0;
 	
 	fr(i,0,13){
 		if(t%10 == t) a += (t - 1)*p;
 		else a += 9*p;
 		p *= 10;
 		t /= 10;
 		if(t == 0) break;
 	}

 	int ans = sum(a) + sum(n - a);
 	cout<<ans;

}