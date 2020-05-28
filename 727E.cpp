#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;


struct vertex{
    int p = -1, link = -1;
    unordered_map <int, int> next;
    unordered_map <int, int> go;
    int ind = -1, pch;
    vertex(int p=-1, int ch = -1) : p(p), pch(ch) {
    }
};
vector <vertex> trie(1);

void add_string(string s){
    int node = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(!trie[node].next.count(s[i] - 'a')){
            trie[node].next[s[i] - 'a'] = trie.size();
            trie.emplace_back(node, s[i]);
        }
        trie[trie[node].next[s[i] - 'a']].p = node;
        node = trie[node].next[s[i] - 'a'];
        trie[node].pch = s[i] - 'a';
    }
}

int go(int v, int c);

int get_link(int v) {
    if (trie[v].link == -1) {
        if (v == 0 || trie[v].p == 0)
            trie[v].link = 0;
        else
            trie[v].link = go(get_link(trie[v].p), trie[v].pch);
    }
    return trie[v].link;
}

int go(int v, int c) {
    if (!trie[v].go.count(c)) {
        if (trie[v].next.count(c))
            trie[v].go[c] = trie[v].next[c];
        else
            trie[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
    }
    return trie[v].go[c];
}

int find_size(vector <int> &t){
    set <int> s;
    for(auto x: t)
        s.insert(x);
    s.erase(-1);
    return (int)s.size();
};

int n, k, g;
string s;
vector <int> vals(1000000, -1);

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>k>>s;

    cin>>g;
    for(int i = 0; i < g; i++){
        string x;
        cin>>x;
        add_string(x);
        int node = 0;
        for(auto c: x){
            node = go(node, c - 'a');
        }

        trie[node].ind = i;
    }

    for(int i = 0, node = 0; i < 2*n*k; i++){
        node = go(node, s[i%(n*k)] - 'a');
        vals[i%(n*k)] = trie[node].ind;
    }

    for(int i = 0; i < k; i++){
        vector <int> v;

        for(int j = 0; j < n; j++){
            v.push_back(vals[(i + j*k)%(n*k)]);
        }
        if(find_size(v) == n){
            cout<<"YES\n";
            for(auto x: v) cout<<x + 1<<" ";
            return 0;
        }
    }

    cout<<"NO\n";
}