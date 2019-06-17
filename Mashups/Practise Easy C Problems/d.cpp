#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 100000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, m, cs, ce, v, q;
int s[100001], e[100001];


int bse1(int x){
	int l = 1, r = ce, ans = mod;
	while(l <= r){
		int mid = (l + r)/2;
		if(e[mid] <= x){
			ans = e[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bse2(int x){
	int l = 1, r = ce, ans = mod;
	while(l <= r){
		int mid = (l + r)/2;
		if(e[mid] >= x){
			ans = e[mid];
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}


int bss1(int x){
	int l = 1, r = cs, ans = mod;
	while(l <= r){
		int mid = (l + r)/2;
		if(s[mid] <= x){
			ans = s[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bss2(int x){
	int l = 1, r = cs, ans = mod;
	while(l <= r){
		int mid = (l + r)/2;
		if(s[mid] >= x){
			ans = s[mid];
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n>>m>>cs>>ce>>v;

 	fr(i, 1, cs + 1){
 		cin>>s[i];
 	}

 	fr(i, 1, ce + 1){
 		cin>>e[i];
 	}
 		
 	cin>>q;
 	while(q--){
 		int x1, y1, x2, y2;
 		cin>>y1>>x1>>y2>>x2;

 		if(y1 == y2)
 		{
 			cout<<abs(x2-x1)<<endl;
 			continue;
 		}
 		
 		int ans = mod;
 		int xel = bse1(x1);		
 		int xer = bse2(x1);

 		int xsl = bss1(x1);
 		int xsr = bss2(x1);

 		int tempe = min(abs(x2 - xel) + abs(x1 - xel), abs(x2 - xer) + abs(x1 - xer));
 		int temps = min(abs(x2 - xsl) + abs(x1 - xsl), abs(x2 - xsr) + abs(x1 - xsr));
 		ans = min(temps + abs(y2 - y1), tempe + (abs(y2 - y1)/v + (abs(y2 - y1)%v != 0)));

 		cout<<ans<<'\n';
 	}
}