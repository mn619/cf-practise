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
    	int n;
    	cin>>n;
    	vector <int> p;
    	vector <pair<int, int>> ans;
    	int temp = n;
    	for(int i = 2; i*i < n; i++){
    		if(temp%i != 0) continue;
 
    		int cnt = 0;
    		while(temp%i == 0){
    			cnt++;
    			temp /= i;
    		}
    		ans.pb({i, cnt});
    	}
 
    	if(temp != 1) ans.pb({temp, 1});
 
    	if(ans.size() >= 3){
    		int a = ans[0].F, b = ans[1].F;
    		int c = n/(a*b);
    		cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
    	}
    	else if(ans.size() == 2){
    		if(ans[0].S + ans[1].S > 3){
    			int a = ans[0].F, b = ans[1].F;
    			int c = n/(a*b);
    			cout<<"YES\n"<<a<<" "<<b<<" "<<c<<'\n';
    		}
    		else cout<<"NO\n";
    	}
    	else if(ans.size() == 1){
    		if(ans[0].S >= 3){
    			int a = ans[0].F, b = ans[0].F*ans[0].F;
    			int c = n/(a*b);
    			if(b == c or a == c or c == 1){
    				cout<<"NO\n";
    			}
    			else cout<<"YES\n"<<a<<" "<<b<<" "<<c<<'\n';
    		}
    		else cout<<"NO\n";
    	}
    }
}