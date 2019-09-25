//	@date 2019/09/25
//	@author psunny0104
//	@brief boj_10844 쉬운 계단 수

#include <iostream>
using namespace std;

const int mod = 1e9;

//d[n][i] 자릿수가 n인 계단수 중 끝자리의 수가 i인 것의 개수
//d[i][j] = d[i-1][j-1]+d[i-1][j+1], 0과 9는 예외(1개씩만 생김)

int d[101][10];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= 8; j++) {
			d[i][j] = (d[i - 1][j - 1] % mod) + (d[i - 1][j + 1] % mod);
		}
		d[i][9] = d[i - 1][8];
		d[i][0] = d[i - 1][1];
	}

	//하나씩 더하면서 바로바로 나누면 long long 필요 없음
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[N][i] % mod;
		ans %= mod;
	}

	cout << ans << '\n';

	return 0;
}