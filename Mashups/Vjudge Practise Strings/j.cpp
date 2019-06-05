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

string s, m;
int q, k;

int bs_l(){
	int l = 0, r = N - 1, ans = N;
	while(l <= r){
		int mid = (l + r)/2;
		int ind = L[mid].p;
		int j = 0;
		while(s[ind] == m[j] and j < m.size() and ind < N){
			ind++;
			j++;
		}
		if(j == m.size()){
			ans = mid;
			r = mid - 1;
		}
		else if(ind == s.size()) l = mid + 1;
		else if(s[ind] < m[j]){
			l = mid + 1;
		} 
		else r = mid - 1;
	}
	return ans;
}

int bs_r(){
	int l = 0, r = N - 1, ans = -1;
	while(l <= r){
		int mid = (l + r)/2;
		int ind = L[mid].p;
		int j = 0;
		while(s[ind] == m[j] and j < m.size() and ind < N){
			ind++;
			j++;
		}
		if(j == m.size()){
			ans = mid;
			l = mid + 1;
		}
		else if(ind == s.size()) l = mid + 1;
		else if(s[ind] < m[j]){
			l = mid + 1;
		} 
		else r = mid - 1;
	}
	return ans;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif

 	FLASH

 	cin>>s;
 	N = s.size();

	for(int i = 0; i < N; i ++) P[0][i] = s[i]; 
		
	for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
	{
	    for(int i=0; i < N; i++)
	    {
	        L[i].nr[0]=P[stp- 1][i];
	        L[i].nr[1]=i + cnt<N? P[stp -1][i+ cnt]:-1;
	        L[i].p= i;
	    }
        sort(L, L+N, cmp);
        for(int i=0; i < N; i++)
        P[stp][L[i].p] =(i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] )? P[stp][L[i-1].p] : i;
	}

 	cin>>q;
 	while(q--){
 		cin>>k>>m;
 		int l = bs_l(), r = bs_r();
 		if(r - l + 1 < k){
 			cout<<-1<<'\n';
 			continue;
 		}
 		else{
 			vector <int> v;
 			fr(i, l, r + 1){
 				v.pb(L[i].p);
 			}
			sort(v.begin(), v.end());

			int len = mod;
			fr(i, 0, v.size() - k + 1){
				len = min(len, v[i + k - 1] - v[i] + (int)m.size());
			}

			cout<<len<<'\n';
 		}
 	}
}