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
 
string fin(int b, int len = -1){
    string ans = "";
    if(b%9) ans += (b%9) + '0';
    b /= 9;
    while(b--) ans += '9';
    if(len != -1){
        reverse(all(ans));
        while((int) ans.size() < len){
            ans += '0';
        }
        reverse(all(ans));
    }
        return ans;
}
 
signed main()
{
    FILEIO
    FLASH
 
    int n;
    cin>>n;
 
    string s = "";
    int b;
    cin>>b;
    s = fin(b);
    cout<<s<<'\n';
 
    fr(i, 2, n + 1){
        int l = s.size();
        int sm = b;
        cin>>b;
 
        bool found = 0;
        for(int j = l - 1; j >= 0; j--){
            int d = s[j] - '0';
            fr(k, d + 1, 10){
                if(sm + k - d <= b and sm + k - d + 9*(l - j - 1) >= b){
                    found = 1;
                    s[j] = k + '0';
                    int rem = b - sm - k + d;
                    fr(m, j + 1, l) s[m] = '0';
                    string temp =  fin(rem);
                    for(int m = 1; m <= (int) temp.size(); m++)
                        s[l - m] = temp[(int)temp.size() - m];
                    break;
                }
            }
            sm -= (int)(s[j] - '0');
            if(found) break;
        }
 
        while(!found){
            l++;
            fr(j, 1, 10){
                if(j <= b and j + 9*(l - 1) >= b){
                    s = fin(b - j, l - 1);
                    reverse(all(s));
                    s += j + '0';
                    reverse(all(s));
                    found = 1;
                    break;
                }
            }
        }
 
        cout<<s<<'\n';
    }
}