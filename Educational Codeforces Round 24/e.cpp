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
map <int, int> m[maxn];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>k;
 	for(int i = 2; i*i <= k; i++){
 		while(k%i == 0){
 			m[0][i]++;
 			k /= i;
 		}
 	}

 	if(k != 1) m[0][k]++;

 	fr(i, 1, n + 1){
 		int a;
 		cin>>a;
 		for(auto x: m[0]){
 			if(i > 1)m[i][x.first] = m[i - 1][x.first];
 			else m[i][x.first] = 0;

 			while(a%x.first == 0){
 				m[i][x.first]++;
 				a /= x.first;
 			}
 		}
 	}
 	
 	int ans = 0;

 	fr(i, 1, n + 1){
 		int l = i, r = n, ans1 = n + 1;
 		while(l <= r){
 			int mid = (l + r)/2;
 			bool ok = 1;

 			for(auto x: m[0]){
 				int p = x.first;
 				if(i == 1){
 					if(m[mid][p] < x.second){ok = 0; break;}
 				}
 				else{
 					if(m[mid][p] - m[i - 1][p] < x.second){ok = 0; break;}
 				}
 			}

 			if(ok){
 				ans1 = mid;
 				r = mid - 1;
 			}
 			else l = mid + 1;
 		}
 		ans += n - ans1 + 1;
 	}

 	cout<<ans;

}