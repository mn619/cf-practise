#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001];
int cnt[1000001];
int ans[1000001];

int power(int a, int b, int m)
{
	if(b < 0) return 0;
    int ans = 1;
    a %= m;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		cin>>a[i]; 
 		for(int j = 1; j * j <= a[i]; j++) 
 		if(a[i]%j == 0) {
 			cnt[j]++; 
 			if(a[i] != j*j) cnt[a[i]/j]++;
 		}
 	}

 	for(int i = 1000000; i >= 1; i--){
 		int t = cnt[i]*power(2, cnt[i] - 1, mod);
 		t %= mod;

 		for(int j = 2*i; j <= 1000000; j+=i){
 			t += mod - ans[j];
 			t %= mod;
 		} 
 		ans[i] = t;
 	}
 	

 	int a  = 0;
 	fr(i, 2, 1000001){
 		a += i*ans[i];
 		a %= mod;
 	}

 	cout<<a;
}