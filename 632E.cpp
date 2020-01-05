#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define maxn 1000000
#define mod 1000000007
#define inf 1000000000000000000
#define eps 1e-5

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

using cd = complex<double>;
const double PI=acos(-1);
 
inline int rev(int x,int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(x&(1LL<<i))
            res|=1LL<<(n-i-1);
    }
    return res;
}
 
inline void fft(vector<cd> &a,bool invert)
{
    int n=a.size();
    int lg_n=0;
    while((1LL<<lg_n)<n)
        lg_n++;
 
    for(int i=0;i<n;i++)
        if(i<rev(i,lg_n))
            swap(a[i],a[rev(i,lg_n)]);
 
    for(int len=2;len<=n;len<<=1LL)
    {
        double ang=2*PI/len * (invert?-1:1);
        cd wlen(cos(ang),sin(ang));
        for(int i=0;i<n;i+=len)
        {
            cd w(1);
            for(int j=0;j<len/2;j++)
            {
                cd u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
 
    if(invert){
        for(int i=0;i<n;i++)
            a[i]/=n;
    }
}
 
inline vector<int> multiply(vector<int> const&a,vector<int> const&b)
{
    vector<cd> fa(a.begin(), a.end()),fb(b.begin(), b.end());
    int n = 1;
    while(n < (int)a.size() + (int)b.size()-1)
        n<<=1LL;
    // cout<<n<<'\n';
    assert(n <= 2*maxn);
    
    fa.resize(n);fb.resize(n);
    fft(fa,0);
    fft(fb,0);
    for(int i=0;i<n;i++)
        fa[i]*=fb[i];
    fft(fa,1);
 
    vector<int> res(n);
    int mx = 0;
    for(int i=0;i<n;i++){
        res[i]=round(fa[i].real()), res[i] = (res[i] > 0);
        if(res[i]) mx = i;
    }

    res.resize(mx + 1);
    return res;
}

vector<int> power(vector<int> v, int k){
	if(k==1) return v;
	vector<int> ans = power(v, k/2);
	ans = multiply(ans, ans);
	if(k&1) ans = multiply(ans, v);
	return ans;
}

int n, k;
set <int> s;
vector<int> v(1001);

signed main()
{
    // #ifndef ONLINE_JUDGE
    FILEIO
    // #endif
    //FLASH

    cin>>n>>k;

    int mx = 0;

    fr(i, 1, n + 1){
    	int a;
    	cin>>a;
    	v[a] = 1;
    	mx = max(mx, a);
    }
    v.resize(mx + 1);
    auto ans = power(v, k);

    fr(i, 1, ans.size()){
    	if(ans[i]) cout<<i<<" ";
    }
}