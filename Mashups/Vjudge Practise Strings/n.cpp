#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

#define MAXN 100001
#define MAXLG 18

struct entry 
{     
	int nr[2], p; 
}L[MAXN]; 
 
int P[MAXLG][MAXN], N, stp, cnt;  
int cmp(struct entry a, struct entry b) 
{     return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0); }  

int n, s[MAXN];
map<int, vector <int>> v;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	N = n;

 	fr(i, 0, n) cin>>s[i];

 	for(int i = 0; i < N; i ++) P[0][i] = s[i]; 
		
	for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
	{
	    for(int i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(int i=0; i < N; i++)
            P[stp][L[i].p] =(i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] )? P[stp][L[i-1].p] : i;
    }

    int pos = 0;
    
    
    fr(i, 0, n){
    	for(int j = v[s[i]].size() - 1; j >= 0; j--){
    		int ind = v[s[i]][j];
    		int l = i - ind;
    		if(ind < pos || i + l - 1 > n) break;
    		int k = log2(l);
    		int pwr = (1<<k);
    		if(P[k][ind] == P[k][i] and P[k][i - pwr] == P[k][i + l - pwr]){
    			pos = i;
    		}
    	}
    	v[s[i]].pb(i);
    }

    cout<<n - pos<<'\n';
    fr(i, pos, n) cout<<s[i]<<" ";
 	
}