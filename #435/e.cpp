#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, q, sum = 0;
int a[100001], b[200021];
set <int> s;
const int inf = (int) 1000000000000000000;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>q;
 	fr(i, 1, n + 1){
 		cin>>a[i];
 		if(i&1) sum += a[i];
 		else sum -= a[i];
 	}

 	fr(i, 1, m + 1){
 		cin>>b[i];;
 	}

 	for(int i = m; i>=1; i--){
 		b[i] = b[i] - b[i + 1];
 	}


 	fr(i, 1, m - n + 2){
 		if((n-1)&1){
 			b[i] -= b[i + n];
 		}
 		else b[i] += b[i + n];
 		s.insert(b[i]);
 	}
 	s.insert(inf);
 	

 	auto it = s.lower_bound(sum);
 	int ans = *it - sum;
 	if(it != s.begin()) {
 		it--;
 	 	ans = min(ans, sum - *it);
 	}

 	cout<<ans<<'\n';

 	while(q--){
 		int l, r, x;
 		cin>>l>>r>>x;
 		int len = (r - l + 1);
 		if(len&1){
 			if(l&1){
 				sum += x;
 			}
 			else sum -= x;
 		}
 		it = s.lower_bound(sum);
 		ans = *it - sum;
 		if(it != s.begin()) {
 			it--;
 		 	ans = min(ans, sum - *it);
 		 }
 		cout<<ans<<'\n';
 	}
}