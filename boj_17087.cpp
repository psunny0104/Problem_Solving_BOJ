//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_17087_숨바꼭질 6

#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int GCD(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S;
	int sr[MAX] = { 0, };
	int diff[MAX] = { 0, };

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> sr[i];
		diff[i] = abs(S - sr[i]);
	}

	int ans = diff[0];
	for (int i = 1; i < N; i++) {
		ans = GCD(ans, diff[i]);
	}

	cout << ans << '\n';

	return 0;
}