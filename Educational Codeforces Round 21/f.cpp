#include <bits/stdc++.h>
using namespace std;
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

struct S{int64_t w,c,operator<(S s){return c>s.c;}} s[100179];
int64_t N,M,i,m,x,w,c,a,d[300179];

int main(){
	FILEIO
for(cin>>N>>M;i<N;i++)cin>>w>>c,s[i]={w,c*6/w};sort(s,s+N);
for(i=0;i<N;i++){
	w=s[i].w;c=s[i].c*w/6;
	x+=w;x=min(x,M);
	for(m=x;m>x-4&&m>=w;m--)d[m]=max(d[m],d[m-w]+c),a=max(a,d[m]);
}
cout<<a;
}