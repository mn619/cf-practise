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
int mm(int x){return x%1000000009;} 
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int p(int a,int b){if(b==0)return 1;int t=mm(p(a,b/2)); if(b%2==0)return mm(t*t); else return mm(mm(a)*mm(t*t)); } 
//strlen(s.c_str());  set <int, greater<int>> s; numeric_limits<double>::max()
//---------------------------------------------------------------------------------------------------------------------------------------------
 int t[100000];


signed main(){
	//FILEIO
	//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	int x=(m)/(k-1);
	int y=m%(k-1);
	if(y==0){
		if(x*k-1<=n){
			//cout<<"EFE"<<endl;
			cout<<mm(m)<<endl;
			return 0;
		}
	}
	if(y!=0){
		if(n-x*k>=y){
			//cout<<"fEF"<<endl;
			cout<<m<<endl;
			return 0;
		}
	}




	int high=m/(k-1)+1;
	int low=0;
	int mid=-1;
	while(high-low>1){
		mid=(high+low)/2;
		if(n-(mid*(k))>=m-mid*(k-1)){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	int l=low;
	//cout<<low<<endl;

	int pre=l*(k-1);

	m-=pre;

	x=m/k;
	y=m%k;

	int ans=mm(mm(mm(2*mm(k))*(mm(p(2,x))-1))+mm(y)+mm(pre));
	ans+=1000000009;
	ans=mm(ans);
	cout<<ans<<endl;

	return 0;
}