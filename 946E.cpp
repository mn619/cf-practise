#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

bool check(string s){
    int a = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] != '0' and s[i] != '1') return false;
        a += s[i] == '1';
    }
    return (a == 1);
}

int n;
string s;

void solv(){
    vector <bool> cnt(10, 0);
    cin>>s;
    n = s.size();
    if(check(s)){
        for(int i = 0; i < n - 2; i++) cout<<'9';
        cout<<'\n';
        return;
    }

    vector <int> odd(n, 0);
    int las = -69;
    for(int i = 0; i < n; i++){
        bool ok = 0;

        cnt[s[i] - '0'] = cnt[s[i] - '0']^1;
        if(cnt[s[i] - '0']) odd[i]++;
        else odd[i]--;

        if(i > 0) odd[i] += odd[i - 1];
        if(s[i] == '0')  continue;
        bool les = 0;
        for(int j = 0; j < s[i] - '0'; j++) les |= cnt[j];

        // if(n - i >= (i?odd[i - 1]: 0) + ((!les)?2 : ))
        if(les and n - i >= (i?odd[i - 1]:0)){
            ok = true;
        }
        else if(!les and n - i >= (i?odd[i - 1]:0) + 2){
            ok = true;
        }
        if(ok) las = i;
    }

    assert(las != -69);

    if(las == 0){
        if(s[0] != '1')
        cout<<s[0] - '0' - 1;
        for(int i = 0; i < n - 2; i++) cout<<'9';
        if(s[0] != '1')
        cout<<s[0] - '0' - 1;
        cout<<'\n';
        return;
    }

    string ans = "";
    for(int i = 0; i < las; i++) ans += s[i];

    vector <bool> req(10, 0);
    for(int i = 0; i < las; i++)
        req[s[i] - '0'] = req[s[i] - '0']^1;

    int reqcnt = 0;
    for(int i = 0; i < 10; i++) reqcnt += req[i];


    bool done = 0;
    
    if(s[las] != '0')
    if(n - las >= 2 + reqcnt or req[s[las] - '0' - 1]){
        done = 1;
        char c = s[las];
        c--;
        ans += c;
        req[c - '0'] = req[c - '0']^1;
        las++;
    }

    if(!done)
    for(int i = s[las] - '0' - 1; i >= 0; i--){
        if(req[i]){
            char c = (char)'0' + i;
            ans += c;
            req[i] = 0;
            done = 1;
            las++;
            break;
        }
    }

    assert(done);
    reqcnt = 0;
    for(int i = 0; i < 10; i++) reqcnt += req[i];

    int d = n - las - reqcnt;
    for(int i = 0; i < d; i++) ans += '9';
    
    for(int i = 9; i >= 0; i--){
        if(!req[i]) continue;
        char c = (char)'0' + i;
        ans += c;
    }

    // cout<<n<<" "<<las<<" "<<d<<' '<<reqcnt<<'\n';
    cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    // FLASH

    int t;
    cin>>t;

    while(t--) solv();
}