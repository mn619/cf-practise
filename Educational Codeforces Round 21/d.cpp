#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[100001], pre[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;

	int sum = 0;

	fr(i, 1, n + 1){
		cin>>a[i];
		sum += a[i];
		pre[i] = sum;
	} 	

	if(sum&1) return cout<<"NO", 0;
	set <int> s;
	sum /= 2;
	
	for(int i = n; i >= 1; i--){
		if(s.find(sum + a[i] - pre[i]) != s.end() || pre[i] == sum) return cout<<"YES", 0;
		s.insert(a[i]);
	}

	s.clear();

	for(int i = 1; i < n; i++){
		if(s.find(-sum + a[i + 1] + pre[i]) != s.end() || pre[i] == sum) return cout<<"YES", 0;
		s.insert(a[i]);
	}
	cout<<"NO\n";
}