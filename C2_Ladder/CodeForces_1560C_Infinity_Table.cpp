#include<bits/stdc++.h>
using namespace std ;
int main() {
    int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		int a = 1;
		int b = 1;
		int c = 1;

		while (k >= b + a)
		{
			b += a;
			a += 2;
			c += 1;
		}

		int ans = k - b + 1;
		if (ans <= c)
			cout << ans << ' ' << c << '\n';
		else
			cout << c << ' ' << (c - (ans - c)) << '\n';
	}
    return 0 ;
}