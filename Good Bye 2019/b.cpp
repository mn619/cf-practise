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
	int n;
	cin>>n;
	int a[n + 1];
	fr(i, 1, n + 1){
		cin>>a[i];
	}

	fr(i, 2, n + 1){
		if(abs(a[i] - a[i - 1]) >= 2){
			cout<<"YES\n"<<i - 1<<" "<<i<<'\n';
			return;
		}
	}
	cout<<"NO\n";
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