#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

struct state {
    int len, link, cnt = 0;
    bool terminal = 0, vis = 0;
    map<char, int> next;
};

const int MAXLEN = 1000001;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void dfs(int node){
	st[node].vis = 1;
	if(st[node].terminal == 1) st[node].cnt++;
	for(auto x: st[node].next){
		int child = x.second;
		if(st[child].vis){
			st[node].cnt += st[child].cnt;
		}
		else{
			dfs(child);
			st[node].cnt += st[child].cnt;
		}
	}
}

int n;
string s[70001];


int count_(string x, string y){
	int l = x.size();
	int l2 = y.size();
	int ans = 0;
	fr(i, 0, l){
		bool ok = 1;
		fr(j, 0, l2){
			if(x[i + j] != y[j]){
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	string t = "";
 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>s[i];
 		t += s[i];
 		t += '$';
 	}

 	sa_init();

 	int l = t.size();
 	fr(i, 0, l){
 		sa_extend(t[i]);
 	}

	int p = last;
	while(p > 0){
  		st[p].terminal = 1;
  		p = st[p].link;
	}

 	dfs(0);
 	
 	fr(i, 1, n + 1){
 		string x = s[i];
 		int ans = 9, ansl = 0, ansr = 8;

 		fr(l, 0, 9){
 			int q = 0;
 			string y = "";
 			fr(r, l, 9){
 				y += x[r];
 				q = st[q].next[x[r]];
	 			if(st[q].cnt == count_(x, y)){
	 				if(ans > r - l + 1){
	 					ansr = r;
	 					ansl = l;
	 					ans = r - l + 1;
	 				}
	 			} 				
 			}
 		}

 		fr(j, ansl, ansr + 1) cout<<x[j];
 		cout<<'\n';
 	}

}