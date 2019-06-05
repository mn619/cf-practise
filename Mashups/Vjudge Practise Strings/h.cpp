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
    int len, link;
    bool is_end = 0;
    map<char, int> next;
};

const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;

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
    if(ind == s.size() - 1) st[cur].is_end = 1;

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
            if(ind == s.size() - 1)st[clone].is_end = 1;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH
 	cin>>s;
 	sa_init();

 	fr(i, 0, s.size()) sa_extend(i);

 	int q;
 	cin>>q;

 	while(q--){
 		string t;
 		cin>>t;
 		int cur = 0, len = 0;
 		while(st[cur].next.count(t[len]) and len < t.size()){
 			cur = st[cur].next[t[len]];
 			len++;
 		}

 		if(len == t.size()) cout<<"Y\n";
 		else cout<<"N\n";
 	}
 		
}