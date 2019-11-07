//	@date 2019/11/07
//	@author psunny0104
//	@brief boj_4344_평균은 넘겠지

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		int N;
		cin >> N;
		int scr[1000] = { 0, };
		int mean = 0;
		for (int i = 0; i < N; i++) {
			cin >> scr[i];
			mean += scr[i];
		}

		mean /= N;
		double cnt = 0;
		for (int i = 0; i < N; i++) {
			if (scr[i] > mean)
				cnt++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (cnt * 100) / N << "%\n";
	}

	return 0;
}