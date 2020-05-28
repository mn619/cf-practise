#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 2000000000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int nr, ng, nb;
int r[maxn], g[maxn], b[maxn];

int gr(int val){
	int ans = -1;
	int l1 = 0, r1 = nr - 1;

	while(l1 <= r1){
		int mid = (l1 + r1)>>1;
		if(r[mid] >= val){
			ans = r[mid];
			r1 = mid - 1;
		}
		else l1 = mid + 1;
	}

	return ans;
}

int lr(int val){
	int ans = -1;
	int l1 = 0, r1 = nr - 1;

	while(l1 <= r1){
		int mid = (l1 + r1)>>1;
		if(r[mid] <= val){
			ans = r[mid];
			l1 = mid + 1;
		}
		else r1 = mid - 1;
	}
	return ans;
}

int gg(int val){
	int ans = -1;
	int l1 = 0, r1 = ng - 1;

	while(l1 <= r1){
		int mid = (l1 + r1)>>1;
		if(g[mid] >= val){
			ans = g[mid];
			r1 = mid - 1;
		}
		else l1 = mid + 1;
	}

	return ans;
}

int lg(int val){
	int ans = -1;
	int l1 = 0, r1 = ng - 1;

	while(l1 <= r1){
		int mid = (l1 + r1)>>1;
		if(g[mid] <= val){
			ans = g[mid];
			l1 = mid + 1;
		}
		else r1 = mid - 1;
	}
	return ans;
}

int gb(int val){
	int ans = -1;
	int l1 = 0, r1 = nb - 1;

	while(l1 <= r1){
		int mid = (l1 + r1)>>1;
		if(b[mid] >= val){
			ans = b[mid];
			r1 = mid - 1;
		}
		else l1 = mid + 1;
	}

	return ans;
}

int lb(int val){
	int ans = -1;
	int l1 = 0, r1 = nb - 1;

	while(l1 <= r1){
		int mid = (l1 + r1)>>1;
		if(b[mid] <= val){
			ans = b[mid];
			l1 = mid + 1;
		}
		else r1 = mid - 1;
	}
	return ans;
}

void solv(){
	cin>>nr>>ng>>nb;
	for(int i = 0; i < nr; i++)
		cin>>r[i];

	for(int i = 0; i < ng; i++)
		cin>>g[i];

	for(int i = 0; i < nb; i++)
		cin>>b[i];
	
	sort(r, r + nr);
	sort(g, g + ng);
	sort(b, b + nb);
	int ans = inf;	
	
	for(int i = 0; i < nr; i++){
		int x, y, z;
		x = r[i], y = gg(r[i]), z = lb(r[i]);
		if(y != - 1 and z != -1){
			ans = min(ans, (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z));
		}

		y = lg(r[i]), z = gb(r[i]);
		if(y != - 1 and z != -1){
			ans = min(ans, (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z));
		}
	}

	for(int i = 0; i < nb; i++){
		int x, y, z;
		x = b[i], y = gg(b[i]), z = lr(b[i]);
		if(y != - 1 and z != -1){
			ans = min(ans, (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z));
		}

		y = lg(b[i]), z = gr(b[i]);
		if(y != - 1 and z != -1){
			ans = min(ans, (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z));
		}
	}

	for(int i = 0; i < ng; i++){
		int x, y, z;
		x = g[i], y = gr(g[i]), z = lb(g[i]);
		if(y != - 1 and z != -1){
			ans = min(ans, (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z));
		}

		y = lr(g[i]), z = gb(g[i]);
		if(y != - 1 and z != -1){
			ans = min(ans, (x - y)*(x - y) + (y - z)*(y - z) + (x - z)*(x - z));
		}
	}

	cout<<ans<<'\n';
}

signed main()
{
	FILEIO
	FLASH
	int t;
	cin>>t;

	while(t--) solv();
}
