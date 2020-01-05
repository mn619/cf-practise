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
#define inf 1000000000000000007

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef priority_queue <int, std::vector<int>, function<bool(int, int)>> custom_priority_queue; //custom priority_queue to sort elements in an order defined by custom bool function: Eg- custom_priority_queue pq(comp)

ordered_set s[maxn + 1], s2[maxn + 1];

struct lec{
	int xa, ya, xb, yb;
};

lec l[maxn];

int n;

bool comp1(lec l1, lec l2){
	return l1.ya < l2.ya; 
}

bool comp2(lec l1, lec l2){
	return l1.yb < l2.yb; 
}


void compress(){
	vector <int> v;
	fr(i, 1, n + 1){
		v.pb(l[i].xa);
		v.pb(l[i].ya);
		v.pb(l[i].xb);
		v.pb(l[i].yb);
	}

	sort(v.begin(), v.end());

	unordered_map <int, int> cnt;
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

void update(int ind, int x){
	while(x <= maxn){
		s[x].insert(ind);
		x += x&-x;
	}
}

void update2(int ind, int x){
	while(x <= maxn){
		s2[x].insert(ind);
		x += x&-x;
	}
}

int queri(int val, int l, int r){
	int ans = 0;
	int x = r;
	while(x){
		ans += s[x].order_of_key(val + 1);
		x -= x&-x;
	}

	x = l - 1;
	while(x){
		ans -= s[x].order_of_key(val + 1);
		x -= x&-x;
	}

	return ans;
}

int queri2(int val, int l, int r){
	int ans = 0;
	int x = r;
	while(x){
		ans += s2[x].order_of_key(val + 1);
		x -= x&-x;
	}

	x = l - 1;
	while(x){
		ans -= s2[x].order_of_key(val + 1);
		x -= x&-x;
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
    	int a, b, c, d;
    	cin>>a>>b>>c>>d;
    	l[i].xa = a;
    	l[i].ya = b;
    	l[i].xb = c;
    	l[i].yb = d;
    }

    sort(l + 1, l + n + 1, comp1);

    compress();
   	
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

   		if(ans){
   			if(queri(ans, l[i].xb, l[i].yb) or queri2(ans, l[i].xb, l[i].yb)){
   				return cout<<"NO\n", 0;
   			}
   		}
   		update(i, l[i].yb);
   		update2(i, l[i].xb);
   	}

   	fr(i, 1, maxn + 1) s[i].clear(), s2[i].clear();

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
   		if(ans){
   			if(queri(ans, l[i].xa, l[i].ya) or queri2(ans, l[i].xa, l[i].ya)){
   				return cout<<"NO\n", 0;
   			}
   		}
   		update(i, l[i].ya);
   		update2(i, l[i].xa);
   	}

   	cout<<"YES";
}