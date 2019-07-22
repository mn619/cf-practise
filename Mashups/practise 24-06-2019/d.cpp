#include<bits/stdc++.h>
#define l long long
#define md 1000000009
using namespace std;
l n,m,k;l power(l a,l b){l ans=1;a %= md;while(b){if(b&1)ans=(ans*a)%md;a=(a*a)%md;b>>=1;}return ans;}int main(){cin>>n>>m>>k;l z=n-m;l rem=m-z*(k-1);if(rem<=0)return cout<<m,0;l ans=z*(k-1)+(rem%k);l b=rem/k;ans+=(k*(power(2,b+1)+md-2))%md;ans%=md;cout<<ans;}