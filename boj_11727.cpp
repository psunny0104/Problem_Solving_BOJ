//	@date 2019/09/22
//	@author psunny0104
//	@brief boj_11727_2xn 타일링 2

#include <iostream>
#define div 10007
using namespace std;

//d[n]:2xn 사격형을 채우는 방법의 수
//d[n] = 2*d[n-2]+d[n-1]

int memo[1001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	memo[1] = 1;
	memo[2] = 3;

	for (int i = 3; i <= N; i++) {
		memo[i] = (2 * memo[i - 2] + memo[i - 1]) % div;
	}

	cout << memo[N] << '\n';
	return 0;
}