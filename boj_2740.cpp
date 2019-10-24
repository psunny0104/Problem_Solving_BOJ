//	@date 2019/10/24
//	@author psunny0104
//	@brief boj_2740_행렬 곱셈

#include <iostream>
using namespace std;

int one[101][101];
int two[101][101];
int N, M, K;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> one[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= K; j++) {
			cin >> two[i][j];
		}
	}
	

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= K; k++) {
			int tmp = 0;
			for (int m = 1; m <= M; m++) {
				tmp += one[i][m] * two[m][k];
			}
			cout << tmp << ' ';
		}
		cout << '\n';
	}

	return 0;
}