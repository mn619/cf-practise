#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;
int b[100001];
int p[100001];

int nex(int a){
	a++;
	if(a == n + 1) a = 1;
	return a;
}

signed main()
{

	FILEIO

 	cin>>n;

 	fr(i, 1, n + 1){
 		int a;
 		cin>>a;
 		if(a) p[a] = -mod;
 		if(a != 0) s.insert(a);
 	}


 	fr(i, 1, n + 1){
 		cin>>b[i];
 		if(b[i]) p[b[i]] = i;
 	}

 	bool ok = 1;
 	int las = b[n];

 	for(int i = n - 1; i >= 1; i--){
 		if(las == 1) break;
 		if(b[i] != las - 1){
 			ok = 0;
 			las = 0;
 			break;
 		}
 		else{
 			las--;
 		}
 	}

 	if(las){
  		fr(i, b[n] + 1, n + 1){
			if(p[i] >= i - b[n]){
				ok = 0;
				break;
			}
 		}
 	}

 	int len = ok*b[n], mx = 0;
 	
 	for(int i = 1; i <= n - len; i++){
 		if(b[i] != 0){
 			mx = max(mx, i - b[i] + 1);
 		}
 	}

 	int ans = mx + n - len;
	cout<<ans<<'\n'; 	
}