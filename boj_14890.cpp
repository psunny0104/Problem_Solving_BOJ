//	@date 2019/10/20
//	@author psunny0104
//	@brief boj_14890_경사로

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L, ans;
int map[101][101];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		bool flag = false;
		for (int j = 1; j <= N-1; j++) {
			if (flag == true) {
				flag = false;
				break;
			}
			if (abs(map[i][j] - map[i][j + 1]) > 1) {
				flag = true;
				break;
			}

			if (map[i][j] > map[i][j + 1]) {
				if (j + L > N) {
					flag = true;
					break;
				}

				if (map[i][j] == map[i][j + L + 1]) {
					flag = true;
					break;
				}

				bool L_cnt = false;
				for (int k = j + 1; k <= L * 2 + j; k++) {
					if (map[i][k] > map[i][j + 1]) {
						L_cnt = true;
						break;
					}
				}
				if (L_cnt == true) {
					L_cnt = false;
					flag = true;
					break;
				}
				int diff_cnt = 0;
				int diff_ht = map[i][j + 1];
				for (int k = j+1; k <= j + L; k++) {
					if (map[i][k] == diff_ht)
						diff_cnt++;
				}
				if (diff_cnt != L) {
					flag = true;
					break;
				}
				j += L-1;
			}

			else if (map[i][j] < map[i][j + 1]) {
				if (j - L + 1 < 1) {
					flag = true;
					break;
				}
				
				if (map[i][j+1] == map[i][j - L]) {
					flag = true;
					break;
				}

				int diff_cnt = 0;
				int diff_ht = map[i][j];
				for (int k = j; k >= j - L+1; k--) {
					if (map[i][k] == diff_ht)
						diff_cnt++;
				}
				if (diff_cnt != L) {
					flag = true;
					break;
				}
			}
		}
		if(flag == false)
			ans++;
	}

	for (int j = 1; j <= N; j++) {
		bool flag = false;
		for (int i = 1; i <= N - 1; i++) {
			if (flag == true) {
				flag = false;
				break;
			}
			if (abs(map[i][j] - map[i+1][j]) > 1) {
				flag = true;
				break;
			}

			if (map[i][j] > map[i+1][j]) {
				if (i + L > N) {
					flag = true;
					break;
				}

				if (map[i][j] == map[i+L+1][j]) {
					flag = true;
					break;
				}

				bool L_cnt = false;
				for (int k = i + 1; k <= L * 2 + i; k++) {
					if (map[k][j] > map[i+1][j]) {
						L_cnt = true;
						break;
					}
				}
				if (L_cnt == true) {
					L_cnt = false;
					flag = true;
					break;
				}

				int diff_cnt = 0;
				int diff_ht = map[i+1][j];
				for (int k = i + 1; k <= i + L; k++) {
					if (map[k][j] == diff_ht)
						diff_cnt++;
				}
				if (diff_cnt != L) {
					flag = true;
					break;
				}
				i += L-1;
			}

			else if (map[i][j] < map[i+1][j]) {
				if (i - L + 1 < 1) {
					flag = true;
					break;
				}

				if (map[i+1][j] == map[i-L][j]) {
					flag = true;
					break;
				}

				int diff_cnt = 0;
				int diff_ht = map[i][j];
				for (int k = i; k >= i - L + 1; k--) {
					if (map[k][j] == diff_ht)
						diff_cnt++;
				}
				if (diff_cnt != L) {
					flag = true;
					break;
				}
			}
		}
		if (flag == false)
			ans++;
	}

	cout << ans << '\n';
	return 0;
}