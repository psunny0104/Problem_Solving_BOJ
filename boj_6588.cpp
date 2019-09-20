//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_6588_골드바흐의 추측

#include <iostream>
#define MAX 1000000
using namespace std;

bool not_prime[MAX + 1];

void find_prime(int N)
{
	for (int i = N - 1; i >= 3; i--) {
		if (not_prime[i] == false && not_prime[N - i] == false) {
			cout << N << " = " << N - i << " + " << i << '\n';
			return;
		}
	}
	cout << "Goldbach`s conjecture is wrong." << '\n';
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	
	//소수 구하기
	not_prime[1] = true;
	for (int i = 2; i <= MAX; i++) {
		if (not_prime[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				not_prime[j] = true;
			}
		}
	}

	//골드바흐의 추측
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		find_prime(N);
	}

	return 0;
}