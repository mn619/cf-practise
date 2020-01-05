#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 300000

using namespace std;

int p[maxn], a, b, x, y, n, k;


bool check(int l){

	int g = __gcd(a, b);
	int lcm = a*b/g;

	int cmn = l/lcm;

	int fi = l/a - cmn, se = l/b - cmn;


	int k1 = k;

	fr(i, 1, n + 1){
		if(cmn > 0){
			cmn--;
			k1 -= (x + y)*p[i]/100;
		}
		else if(fi > 0){
			fi--;
			k1 -= x*p[i]/100;
		}
		else if(se > 0){
			se--;
			k1 -= y*p[i]/100;
		}
	}

	return (k1 <= 0);
}

void solv(){
	cin>>n;

	fr(i, 1, n + 1) cin>>p[i];
	cin>>x>>a>>y>>b>>k;

	if(x < y){
		swap(x, y);
		swap(a, b);
	}

	sort(p + 1, p + n + 1);
	reverse(p + 1, p + n + 1);
	int l = 1, r = n, ans = -1;

	while(l <= r){
		int mid = (l + r)/2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}


	cout<<ans<<'\n';
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	
 	int q;
 	cin>>q;
 	while(q--) solv();
}