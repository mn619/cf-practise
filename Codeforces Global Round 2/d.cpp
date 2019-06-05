#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int s[100001], n, ans[100001], d[100001], q;
vector <int> queri[100001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>s[i];
 	}

 	sort(s + 1, s + n + 1);

 	fr(i, 1, n){
 		d[i] = s[i + 1] - s[i];
 	}
 	sort(d + 1, d + n);

 	stack<int> s;

 	for(int i = n - 1;i > 0; i--){
 		s.push(d[i]);
 	}

 	cin>>q;
 	fr(i, 1, q + 1){
 		int l, r;
 		cin>>l>>r;
 		queri[i].pb(r - l + 1);
 		queri[i].pb(i);
 	}

 	sort(queri + 1, queri + q + 1);

 	int sm = 0;

 	fr(i, 1, q + 1){
 		int len = queri[i][0];

 		if(!s.empty())
 		while(s.top() < len)
 		{
 			sm += s.top();
 			s.pop();
 			if(s.empty()) break;
 		}
 		ans[queri[i][1]] = sm + len*(s.size() + 1);
 	}

 	fr(i, 1, q + 1){
 		cout<<ans[i]<<" ";
 	}

}