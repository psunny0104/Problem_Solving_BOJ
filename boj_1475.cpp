/*
	@date 2020/05/25
	@author psunny0104
	@brief boj_1475_방 번호
*/

#include <bits/stdc++.h>
using namespace std;

int ans[10];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		if (N[i] == '6' || N[i] == '9')
			ans[6]++;
		else {
			ans[N[i] - '0']++;
		}
	}
	if (ans[6] % 2 == 0)
		ans[6] /= 2;
	else
		ans[6] = (ans[6]/2) + 1;

	sort(ans, ans + 10);
	cout << ans[9];

	return 0;
}