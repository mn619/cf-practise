#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, k;

void solv(){
	cin>>n>>k;

	
	if(k%3 != 0){
		if(n%3 != 0)
			cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	else{
		n %= k + 1;
		if(n == k || (n%3 != 0)) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
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