#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 300000


using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int inversion(int a[], int n)
{
	int i;
	int ans = 0;
	reverse(a, a + n);

	ordered_set  s;

	fr(i, 0, n){
		s.insert({a[i], i});
		ans += s.order_of_key({a[i], i});
	}
	return ans;
}

void solve(){
	int n;
	cin>>n;
	int a[n + 1], b[n + 1];
	int cnt[n + 1] = {0};

	multiset <int> as, bs;
	fr(i, 0, n) {
		cin>>a[i];
		cnt[a[i]] += 1;
	}

	int inva = inversion(a, n);

	fr(i, 0, n){
		cin>>b[i];
		cnt[b[i]] -= 1;
	}

	int invb = inversion(b, n);

	fr(i, 0, n){
		if(cnt[i] != 0){
			cout<<"NO\n";
			return ;
		}
	}

	if(inva < invb){
		cout<<"NO\n";
		return;
	}
	
	cout<<inva<<" "<<invb<<'\n';

	cout<<"YES\n";
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	int t;
	cin>>t;
	while(t--) solve(); 	
}