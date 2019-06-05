#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, p = 0;
int a[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	a[1] = 1;

 	fr(i, 2, n + 1){
 		if(a[i] == 0){
 			p++;
 			for(int j = i; j <= n; j += i){
 				a[j] = p;
 			}
 		}
 	}

 	fr(i, 2, n + 1) cout<<a[i]<<" ";
}