#include<bits/stdc++.h>
#define maxn 300000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m, l[maxn], r[maxn];
pair<int, int> a[maxn];
vector <int> in[maxn], out[maxn];

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>l[i]>>r[i];
    }

    for(int i = 1; i <= m; i++){
        cin>>a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + m + 1);
    vector <pair<int, int>> v(n);
    vector <int> ans(n);

    for(int i = 1; i < n; i++){
        int mn = l[i + 1] - r[i], mx = r[i + 1] - l[i];
        v[i] = {mx, i};
        int l = 1, r = m, ind = -1;

        while(l <= r){
            int mid = (l + r)>>1;
            if(a[mid].first >= mn){
                ind = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if(ind == -1 or a[ind].first > mx){
            return cout<<"No\n", 0;
        }

        in[ind].push_back(i);
        ind = -1;

        l = 1, r = m;
        while(l <= r){
            int mid = (l + r)>>1;
            if(a[mid].first <= mx){
                ind = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        assert(ind != -1);
        out[ind + 1].push_back(i);
    }

    set <pair<int, int>> s;
    for(int i = 1; i <= m + 1; i++){
        for(auto x: out[i]){
            if(s.count(v[x])){
                return cout<<"No\n", 0;
            }
        }

        for(auto x: in[i])
            s.insert(v[x]);

        if(!s.empty()){
            int ind = (*s.begin()).second;
            ans[ind] = a[i].second;
            s.erase(s.begin());
        }
    }

    cout<<"Yes\n";
    for(int i = 1; i < n; i++) cout<<ans[i]<<" ";
}