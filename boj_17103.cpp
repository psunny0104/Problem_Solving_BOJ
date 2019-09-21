//	@date 2019/09/21
//	@author psunny0104
//	@brief boj_17103_골드바흐 파티션

#include <iostream>
#define MAX 1000000
using namespace std;

bool not_prime[MAX + 1];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	//소수 구하기
	not_prime[1] = true;
	for (int i = 2; i <= MAX; i++) {
		if (not_prime[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				not_prime[j] = true;
			}
		}
	}
	
	//골드 바흐
	while (T--) {
		int N, cnt = 0;
		cin >> N;
		for (int i = 2; i <= N / 2; i++) {
			if (not_prime[i] == false) {
				if (not_prime[N - i] == false)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}