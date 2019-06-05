#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int a[n+1];
for(int i=1;i<=n;++i)
{
    cin>>a[i];
}
int c=0;
for(int i=1;i<=n;++i)
{
    while(a[i]!=i)
    {
        int t=a[a[i]];
        a[a[i]]=a[i];
        a[i]=t;
        ++c;
    }
}
if(c%2==(3*n)%2)
cout<<"Petr";
else
cout<<"Um_nik";
}
