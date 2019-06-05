#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

string s;

struct state {
    int len, link, cnt = 0;
    bool is_end = 0;
    map<char, int> next;
};

const int MAXLEN = 100001;
state st[MAXLEN * 2];
int sz, last;
bool vis[MAXLEN * 2];

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}
void sa_extend(int ind) {
    char c = s[ind];
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;

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
    if(vis[node]) return;
    if(st[node].is_end == 1 and node != 0) st[node].cnt = 1;
    else st[node].cnt = 0;

    vis[node] = 1;

    for(auto x: st[node].next){
        dfs(x.second);
        st[node].cnt += st[x.second].cnt;
    }
}

signed main()
{

    FLASH
    cin>>s;
    sa_init();

    fr(i, 0, s.size()) sa_extend(i);
    sz--;
 
    int cur = last;
    while(cur){
        st[cur].is_end = 1;
        cur = st[cur].link;
    }

    dfs(0);

    int q;
    cur = 0;
    vector <pair<int, int>> ans;

    fr(i, 0, s.size()){
        cur = st[cur].next[s[i]];
        if(st[cur].is_end){
            ans.pb({i + 1, st[cur].cnt});
        }
    }

    cout<<ans.size()<<'\n';
    fr(i, 0, ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

}