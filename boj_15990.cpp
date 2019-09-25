//	@date 2019/09/25
//	@author psunny0104
//	@brief boj_15990_1, 2, 3 더하기 5

#include <iostream>
#define mod 1000000009 //1e9+9로도 가능
using namespace std;

//d[n][p] = 1, 2, 3의 합으로 n을 나타내는 방법 중 마지막 수가 p인 방법의 개수
//d[n][0] = d[n-1][2]+d[n-1][3]+d[n-2][1]+d[n-2][3]+d[n-3][2]+d[n-3][3]

int d[100001][4];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;

	for (int i = 4; i <= 100000; i++) {
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
	}

	while (T--) {
		int N;
		cin >> N;
		//각각 10억이면 세 개의 항을 합칠 때 int 범위 넘어갈 수 있음
		//합할 때 하나의 원소라도 casting or 배열을 아예 long long 으로 만들어줌
		long long ans = (long long)d[N][1] + d[N][2] + d[N][3];
		cout << ans % mod << '\n';
	}

	return 0;
}