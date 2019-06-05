#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001], cnt[200001];
int in[200001];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>a[i];
  		cnt[a[i]]++;
 	}


 	int ans = 0;
 	queue <int> q;

 	fr(i, 1, n + 1){
 		if(cnt[i] == 0) {
 			ans++;
 			q.push(i);
 		}
 	}

 	cout<<ans<<'\n';
 	fr(i, 1, n + 1){
 		int x = a[i];
 		if(cnt[x] > 1){
 			if(x > q.front() || in[x]){
 				a[i] = q.front();
 				q.pop();
 				cnt[x]--;
 			}
 		}

 		in[a[i]] = 1;
  	}

 	fr(i, 1, n + 1){
 		cout<<a[i]<<" ";
 	}

}