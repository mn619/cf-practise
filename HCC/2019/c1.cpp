#include<bits/stdc++.h>
#define int long long int
#define fr(i,x,y) for(int i=x;i<y;i++)
#define f(n) for(int i=0;i<n;i++)
#define ff(m) for(int j=0;j<m;j++)
#define F(x) for(auto it:x)
#define in insert
#define pb push_back
#define pi pair<int,int>
#define si second
#define fi first
#define show_(x) cerr<<"-> "<<#x<<endl;F(x){cerr<<it<<" ";}cout<<endl;
#define show(x) cerr<<#x<<"-> "<<x<<endl;
//#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
//#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define FILEIO freopen("F:\\inout\\input.txt", "r", stdin); freopen("F:\\inout\\output.txt", "w", stdout);
using namespace std;
void print(int a[],int n){f(n){cout<<a[i]<<" ";}cout<<endl;}
int m(int x){return x%1000000007;} 
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int p(int a,int b){if(b==0)return 1;int t=p(a,b/2); if(b%2==0)return t*t; else return a*t*t; } 
//strlen(s.c_str());  set <int, greater<int>> s; numeric_limits<double>::max()
//---------------------------------------------------------------------------------------------------------------------------------------------
 int t[100000];
 
 
signed main(){
	//FILEIO
	//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[4*n+1];
	int b[4*n+1];
	
	f(4*n+1){
		cin>>a[i]>>b[i];
	}
	ff(4*n+1){	
		int mx1=-10000000;
		int mi1=100000000000;
		int mx2=-10000000;
		int mi2=100000000000;
		f(4*n+1){
			if(i==j){
				continue;
			}
			if(mx1<a[i]){
				mx1=a[i];
			}
			if(mi1>a[i]){
				mi1=a[i];
			}
			if(mx2<b[i]){
				mx2=b[i];
			}
			if(mi2>b[i]){
				mi2=b[i];
			}
		}
		int u=0;
		if(mx1-mi1!=mx2-mi2){
			continue;
		}
		else return cout<<a[j]<<" "<<b[i], 0;
	}
 
	return 0;
}