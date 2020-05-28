#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int a, b;
vector <int> da, db;

vector <int> f(int n){
    vector <int> res;
    for(int i = 1; i*i <= n; i++){
        if(n%i) continue;
        res.push_back(i);
        if(i*i != n)
            res.push_back(n/i);
    }

    sort(res.begin(), res.end());
    return res;
}

int find_(vector <int> &d, int i){
    int l = 0, r = (int)d.size() - 1;
    int res = 1;
    while(l <= r){
        int mid = (l + r)>>1;
        if(d[mid] <= i){
            res = d[mid];
            l = mid + 1; 
        }
        else r = mid - 1;
    }
    return res;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>a>>b;
    da = f(a), db = f(b);

    int n = a + b;
    int ans = 2*(n + 1);
    for(int i = 1; i*i <= n; i++){
        if(n%i) continue;

        int len = find_(da, i);

        if(len <= i and a/len <= n/i)
            ans = min(ans, 2*(i + n/i));

        len = find_(db, i);
        if(len <= i and b/len <= n/i)
            ans = min(ans, 2*(i + n/i));        
    }

    cout<<ans<<'\n';
}