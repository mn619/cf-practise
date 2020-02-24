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
    	int a, b;
    	cin>>a>>b;
    	if(a == b){
    		cout<<"0\n";
    		continue;
    	}
    	if(a < b){
    		if((a&1) != (b&1)){
    			cout<<"1\n";
    		}
    		else{
    			cout<<"2\n";
    		}
    	}
    	else{
    		if((a&1) == (b&1)){
    			cout<<"1\n";
    		}
    		else{
    			cout<<"2\n";
    		}
    	}
    }
}