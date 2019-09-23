//	@date 2019/09/22
//	@author psunny0104
//	@brief boj_9095_1, 2, 3 더하기

#include <iostream>
using namespace std;

int memo[11];
//memo[n] : 1, 2, 3의 합으로 나타내는 방법의 수
//memo[n] : memo[n-1]+memo[n-2]+memo[n-3]]
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	memo[1] = 1; //1도 가능
	memo[2] = 2; //2도 가능
	memo[3] = 4; //3도 가능

	for (int i = 4; i <= 10; i++) {
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
	}
	while (T--) {
		int N;
		cin >> N;
		cout << memo[N] << '\n';
	}


	return 0;
}