//	@date 2020/05/24
//	@author psunny0104
//	@brief boj_10093_숫자

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	unsigned long long A, B;
	cin >> A >> B;

	if (B > A) {
		cout << (B - A) - 1 << "\n";
		for (unsigned long long i = A + 1; i < B; i++) {
			cout << i << ' ';
		}
	}
	else if (A > B) {
		cout << (A - B) - 1 << "\n";
		for (unsigned long long i = B + 1; i < A; i++) {
			cout << i << ' ';
		}
	}
	else {
		cout << '0';
		return 0;
	}

	return 0;
}