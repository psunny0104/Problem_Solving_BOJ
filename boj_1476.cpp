//	@date 2019/09/26
//	@author psunny0104
//	@brief boj_1476_날짜 계산

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int E, S, M;
	cin >> E >> S >> M;

	int ans = 1;
	while (E != 1 || S != 1 || M != 1) {
		E--;
		S--;
		M--;

		ans++;

		if (E == 0)
			E = 15;

		if (S == 0)
			S = 28;

		if (M == 0)
			M = 19;
	}
	cout << ans << '\n';

	return 0;
}