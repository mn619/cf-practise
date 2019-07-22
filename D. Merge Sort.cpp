#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, k, calls = 0, b, f = 1, a[100001];

void fun(int l, int r){
	if(r == l + 1){
		return;
	}
	if(calls != k){
		int mid = (l + r)/2;
		calls += 2;
		fun(l, mid);
		fun(mid, r);
	}
	else{
		sort(a + l, a + r);
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	b = n;

 	if(!(k&1)) return cout<<-1, 0;
 	for(int i = n - 1; i >= 0; i--) a[i] = n - i;
 	
 	calls++;
 	fun(0, n);

 	if(calls != k) cout<<-1;
 	else{
 		fr(i, 0, n) cout<<a[i]<<" ";
 	}
}