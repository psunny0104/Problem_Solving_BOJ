//	@date 2019/10/31
//	@author psunny0104
//	@brief boj_1652_누울 자리를 찾아라

#include <iostream>
using namespace std;

char map[101][101];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int cnt_w_e = 0;
	int cnt_n_s = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '.' && map[i][j + 1] == '.') {
				cnt_w_e++;
				while (true) {
					if (map[i][j+1] == 'X' || j+1 == N)
						break;
					j++;
				}
			}
		}
	}

	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			if (map[i][j] == '.' && map[i + 1][j] == '.') {
				cnt_n_s++;
				while (true) {
					if (map[i+1][j] == 'X' || i + 1 == N)
						break;
					i++;
				}
			}
		}
	}

	cout << cnt_w_e << ' ' << cnt_n_s << '\n';

	return 0;
}