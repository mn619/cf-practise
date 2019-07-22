#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int m[2000*150 + 1], n, k, a[1001], s[1001];
priority_queue <pair<int, int>> pq;

int round_(int a, int b){
	return a/b + (a%b >= (b + 1)/2);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 	}

 	fr(i, 1, k + 1){
 		pq.push({0, 0});
 	}

 	fr(i, 1, n + 1){
 		auto p = pq.top();
 		pq.pop();
 		s[i] = -p.first;
 		pq.push({p.first - a[i], i});
 		m[s[i] + a[i]]++;
 	}

 	fr(i, 1, 2000*150 + 1) m[i] += m[i - 1];

 	int ans = 0;
 	fr(i, 1, n + 1){
 		bool ok = 0;
 		fr(j, 0, a[i]){
 			int per = round_(100*m[s[i] + j], n);
 			if(per == j + 1) {ok = 1;  break;}
 		}
 		ans += ok;
 	}

 	assert(m[2000*150] == n);

 	cout<<ans;
}