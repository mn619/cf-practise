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

int p[65] = {1};

pair<int, int> compute(int S, int X) 
{ 
    int A = (S - X)/2; 
    int a = 0, b = 0; 
  
    for (int i=0; i <= 64; i++) 
    {
        int Xi = (X&p[i]); 
        int Ai = (A&p[i]); 

        if (Xi == 0 && Ai == 0){ 
          continue; 
        } 
        else if (Xi == 0 && Ai > 0){
            a = (p[i] | a);  
            b = (p[i] | b);
        } 
        else if (Xi > 0 && Ai == 0) { 
            a = (p[i] | a);  
        }
        else{ 
            return {-1, -1}; 
        } 
    }
	
	return make_pair(a, b);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    for(int i = 1; i < 65; i++){
    	p[i] = 2*p[i - 1];
    }

    int u, v;
    cin>>u>>v;
    if(((u&1) != (v&1)) or (v < u)){
    	cout<<"-1\n";
    	return 0;
    }
    if(u == v){
    	if(v == 0){
    		cout<<0<<'\n';
    		return 0;
    	}

    	cout<<"1\n"<<u<<'\n';
    	return 0;
    }
    auto ans = compute(v, u);
    if(ans.F != -1){
    	cout<<2<<'\n';
    	cout<<ans.F<<" "<<ans.S<<'\n';
    }	
    else{
    	cout<<3<<'\n'<<u<<" "<<(v - u)/2<<" "<<(v - u)/2<<'\n';
    }
}