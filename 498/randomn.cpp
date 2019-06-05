#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
char a[MAXN], b[MAXN];
int ans[MAXN];

int main()
{
#ifdef LOCAL
	freopen("C:/input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	scanf("%s%s", a, b);
	for (int i = 0; i < n / 2; i++)
	{
		if (b[i] != a[i] && b[i] != a[n - i - 1] ||
			b[n - i - 1] != a[i] && b[n - i - 1] != a[n - i - 1] ||
			a[i] != b[i] && a[i] != b[n - i - 1] ||
			a[n - i - 1] != b[i] && a[n - i - 1] != b[n - i - 1])
			ans[i] = 1;
		if (b[i] != a[i] && b[i] != a[n - i - 1] &&
			b[n - i - 1] != a[i] && b[n - i - 1] != a[n - i - 1] && 
			b[i] != b[n - i - 1])
			ans[i] = 2;
		if (a[i] == a[n - i - 1] &&
			b[i] == b[n - i - 1])
			ans[i] = 0;
	}
	int s = 0;
	for (int i = 0; i < n; i++)
		s += ans[i];
	if (n & 1 && a[n / 2] != b[n / 2])
		s++;
	cout << s << endl;

	return 0;
}