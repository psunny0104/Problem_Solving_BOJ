//	@date 2019/10/21
//	@author psunny0104
//	@brief boj_11170_0의 개수

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T, N, M;
	cin >> T;
	while (T--){
		cin >> N >> M;
		int cnt = 0;
		for (int i = N; i <= M; i++) {
			int tg = i;
			while (true) {
				if (tg % 10 == 0)
					cnt++;
				if (tg == tg % 10)
					break;
				tg /= 10;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}