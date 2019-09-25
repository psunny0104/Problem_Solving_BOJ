//	@date 2019/09/25
//	@author psunny0104
//	@brief boj_2193_이친수

#include <iostream>
using namespace std;

//d[n][i] = 자릿수가 n인 이친수 중 마지막 자릿수가 i인 수의 개수
//d[n][1] = d[n-1][0]
//d[n][0] = d[n-1][1]+d[n-1][0]

//int 범위 넘어버림, 코너 케이스 확인!
long long d[91][2];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	d[1][1] = d[2][0] = 1;

	for (int i = 3; i <= 90; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	cout << d[N][0] + d[N][1] << '\n';

	return 0;
}