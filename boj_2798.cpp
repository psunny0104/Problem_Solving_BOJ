/*
	@date 2020/05/25
	@author psunny0104
	@brief boj_2798_블랙잭
*/

#include <bits/stdc++.h>
using namespace std;

int N, T;
int input[101];
bool selected[101];
int ans;

void cmb(int idx, int cnt)
{
	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (selected[i] == true)
				sum += input[i];
		}

		if (sum >= ans && sum <= T)
			ans = sum;

		return;
	}
	for (int i = idx; i < N; i++) {
		if (selected[i] == true)
			continue;
		selected[i] = true;

		cmb(i, cnt + 1);
		selected[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	cmb(0, 0);

	cout << ans << '\n';

	return 0;
}