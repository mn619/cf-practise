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

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t;
    cin>>t;

    while(t--){

        int n, x;
        cin>>n>>x;

        string s;
        cin>>s;

        vector <int> p(n, 0);
        int cnt = 0;
        int ans = 0;
        fr(i, 0, n){
            if(s[i] == '0') p[i]++;
            else p[i]--;
            if(i > 0) p[i] += p[i - 1];
            if(p[i] == x) cnt++;
        }   

        if(p[n - 1] == 0){
            if(cnt > 0)
                cout<<"-1\n";
            else 
                cout<<"0\n";
            continue;
        }

        fr(i, 0, n){
            int t = abs(x - p[i]), tp = abs(p[n - 1]);
            if(t%tp == 0 and ((x - p[i])*p[n - 1]) >= 0) ans++;
        }

        cout<<ans + (x == 0)<<'\n';
    }
}