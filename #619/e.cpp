#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int compres(vector <pair<int, int>> &v){
    vector <int> temp;
    fr(i, 0, v.size()){
        temp.pb(v[i].F);
        temp.pb(v[i].S);
    }    

    int res = 0;
    sort(all(temp));

    map<int, int> r;

    int cur = 0;
    r[temp[0]] = cur;
    fr(i, 1, temp.size()){
        if(temp[i] != temp[i - 1]) cur++;
        r[temp[i]] = cur;
        res = max(res, 2*cur);
    }

    fr(i, 0, v.size()){
        v[i].F = 2*r[v[i].F];
        v[i].S = 2*r[v[i].S];
    }
    return res;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        VII v;
        fr(i, 1, n + 1){
            int l, r;
            cin>>l>>r;
            v.pb({l, r});
        }

        int len = compres(v);
        vector <int> p(len + 2);
        for(auto x: v){
            // cout<<x.F<<" "<<x.S<<'\n';
            p[x.F]++;
            p[x.S + 1]--;
        }

        fr(i, 1, len + 1){
            p[i] += p[i - 1];
        }

        vector <int> s(len + 1);
        vector <int> q(len + 1);

        int l = 0, r = len;

        while(p[l] == 1 and l <= len) l++;
        while(p[r] == 1 and r >= 0) r--;

        fr(i, l, r + 1){
            if(p[i] == 1 and p[i - 1] != 1)
            s[i] = 1;
            else s[i] = 0;
        }

        // cout<<len<<'\n';

        fr(i, 0, len + 1){
            q[i] = (p[i] > 1);
            if(i){
                q[i] += q[i - 1];
            }
            // cout<<q[i]<<" ";
        }
        // cout<<'\n';

        // fr(i, 0, len + 1) cout<<p[i]<<" ";
        // cout<<'\n';

        // fr(i, 0, len + 1) cout<<s[i]<<" ";
        // cout<<'\n';

        fr(i, 0, len + 1) s[i] += s[i - 1];

        int ans = -10;

        fr(i, 0, n){
            if(q[v[i].S] - ((v[i].F > 0)?q[v[i].F - 1]:0) == 0){
                ans = max(ans, (int)-1);
            }
            else{
                ans = max(ans, s[v[i].S] - s[v[i].F - 1]);
            }
        }
        fr(i, 1, len + 1) ans += (p[i] == 0 and p[i - 1] != 0);
        cout<<ans + 1<<"\n";
    }
}