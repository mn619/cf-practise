#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define maxn 400000
#define int long long
#define mod 1000000007
#define inf 1000000000007

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace __gnu_pbds;
using namespace std;

int s[maxn*4 + 10], s2[maxn*4 + 10], s3[4*maxn + 10], s4[4*maxn + 10];
struct lec{
	int xa, ya, xb, yb;
};

lec l[maxn];

int n;

void compress(){
    vector <int> v;
    fr(i, 1, n + 1){
        v.pb(l[i].xa);
        v.pb(l[i].ya);
        v.pb(l[i].xb);
        v.pb(l[i].yb);
    }

    sort(v.begin(), v.end());

    map <int, int> cnt;
    int cur = 1;
    cnt[v[0]] = cur;

    fr(i, 1, v.size()){
        if(v[i] != v[i - 1]) cur++;
        cnt[v[i]] = cur;
    }

    fr(i, 1, n + 1){
        l[i].xa = cnt[l[i].xa];
        l[i].ya = cnt[l[i].ya];
        l[i].xb = cnt[l[i].xb];
        l[i].yb = cnt[l[i].yb];
    }
}

bool comp1(lec l1, lec l2){
	return l1.ya < l2.ya; 
}

bool comp2(lec l1, lec l2){
	return l1.yb < l2.yb; 
}

void update(int ind, int pos, int l, int r, int node){
	if(l == r){
        s[node] = min(s[node], ind);
        return;
    }

    int mid = (l + r)>>1;
    if(pos <= mid) update(ind, pos, l, mid, 2*node);
    else update(ind, pos, mid + 1, r, 2*node + 1);
    s[node] = min(s[2*node], s[2*node + 1]);
}

void update2(int ind, int pos, int l, int r, int node){
    if(l == r){
        s2[node] = min(s2[node], ind);
        return;
    }

    int mid = (l + r)>>1;
    if(pos <= mid) update2(ind, pos, l, mid, 2*node);
    else update2(ind, pos, mid + 1, r, 2*node + 1);
    s2[node] = min(s2[2*node], s2[2*node + 1]);
}

void update3(int x, int y, int l, int r, int node){
    if(l == r){
        s3[node] = max(s3[node], y);
        return;
    }

    int mid = (l + r)>>1;
    if(x <= mid) update3(x, y, l, mid, 2*node);
    else update3(x, y, mid + 1, r, 2*node + 1);
    s3[node] = max(s3[2*node], s3[2*node + 1]);
}

void update4(int x, int y, int l, int r, int node){
    if(l == r){
        s4[node] = min(s4[node], x);
        return;
    }

    int mid = (l + r)>>1;
    if(y <= mid) update4(x, y, l, mid, 2*node);
    else update4(x, y, mid + 1, r, 2*node + 1);
    s4[node] = min(s4[2*node], s4[2*node + 1]);
}

int queri(int l1, int r1, int l, int r, int node){
    if(l1 > r or r1 < l) return inf;
	if(l1 <= l and r <= r1) return s[node];
    int mid = (l + r)>>1;
    return min(queri(l1, r1, l, mid, 2*node), queri(l1, r1, mid + 1, r, 2*node + 1));
}

int queri2(int l1, int r1, int l, int r, int node){
    if(l1 > r or r1 < l) return inf;
    if(l1 <= l and r <= r1) return s2[node];
    int mid = (l + r)>>1;
    return min(queri2(l1, r1, l, mid, 2*node), queri2(l1, r1, mid + 1, r, 2*node + 1));
}

int queri3(int l1, int r1, int l, int r, int node){
    if(l1 > r or r1 < l) return inf;
    if(l1 <= l and r <= r1) return s3[node];
    int mid = (l + r)>>1;
    return max(queri3(l1, r1, l, mid, 2*node), queri3(l1, r1, mid + 1, r, 2*node + 1));
}

int queri4(int l1, int r1, int l, int r, int node){
    if(l1 > r or r1 < l) return inf;
    if(l1 <= l and r <= r1) return s4[node];
    int mid = (l + r)>>1;
    return min(queri4(l1, r1, l, mid, 2*node), queri4(l1, r1, mid + 1, r, 2*node + 1));
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

   
    fr(i, 1, 4*maxn + 10) s[i] = s2[i] = s4[i] = inf, s3[i] = -inf;
    cin>>n;
    fr(i, 1, n + 1){
    	int a, b, c, d;
    	cin>>a>>b>>c>>d;
    	l[i].xa = a;
    	l[i].ya = b;
    	l[i].xb = c;
    	l[i].yb = d;
    }

    compress();
    sort(l + 1, l + n + 1, comp1);

   	// fr(i, 1, n + 1){
    // 	cout<<l[i].xa<<" "<<l[i].ya<<" "<<l[i].xb<<" "<<l[i].yb<<'\n';
    // }

   	fr(i, 1, n + 1){
   		int l1 = 1, r1 = i - 1, ans = 0;
   		while(l1 <= r1){
   			int mid = (l1 + r1)>>1;
   			if(l[mid].ya < l[i].xa){
   				ans = mid;
   				l1 = mid + 1;
   			}
   			else r1 = mid - 1;
   		} 

   		if(ans > 0){
   			if((queri(l[i].xb, l[i].yb, 1, maxn, 1) <= ans) or (queri2(l[i].xb, l[i].yb, 1, maxn, 1) <= ans)){
   				return cout<<"NO\n", 0;
   			}
            if((queri3(1, l[i].xb - 1, 1, maxn, 1) >= l[i].xb) or  (queri4(l[i].yb + 1, maxn, 1, maxn, 1) <= l[i].yb)){
                return cout<<"NO\n", 0;
            }
   		}
   		update(i, l[i].xb, 1, maxn, 1);
   		update2(i, l[i].yb, 1, maxn, 1);
        update3(l[i].xb, l[i].yb, 1, maxn, 1);
        update4(l[i].xb, l[i].yb, 1, maxn, 1);
   	}

   	fr(i, 1, 4*maxn + 10) s[i] = s2[i] = s4[i] = inf, s3[i] = -inf;
   	sort(l + 1, l + n + 1, comp2);

   	// fr(i, 1, n + 1){
    // 	cout<<l[i].xa<<" "<<l[i].ya<<" "<<l[i].xb<<" "<<l[i].yb<<'\n';
    // }

   	fr(i, 1, n + 1){
   		int l1 = 1, r1 = i - 1, ans = 0;
   		while(l1 <= r1){
   			int mid = (l1 + r1)>>1;
   			if(l[mid].yb < l[i].xb){
   				ans = mid;
   				l1 = mid + 1;
   			}
   			else r1 = mid - 1;
   		}

   		if(ans > 0){
   			if((queri(l[i].xa, l[i].ya, 1, maxn, 1) <= ans) or (queri2(l[i].xa, l[i].ya, 1, maxn, 1) <= ans)){
   				return cout<<"NO\n", 0;
   			}
            if((queri3(1, l[i].xa - 1, 1, maxn, 1) >= l[i].xa) or  (queri4(l[i].ya + 1, maxn, 1, maxn, 1) <= l[i].ya)){
                return cout<<"NO\n", 0;
            }
   		}
   		update(i, l[i].xa, 1, maxn, 1);
   		update2(i, l[i].ya, 1, maxn, 1);
        update3(l[i].xa, l[i].ya, 1, maxn, 1);
        update4(l[i].xa, l[i].ya, 1, maxn, 1);

   	}

   	cout<<"YES";
}