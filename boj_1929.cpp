//	@date 2019/09/04
//	@author psunny0104
//	@brief boj_1929_소수 구하기

#include <iostream>
#define MAX 1000001
using namespace std;

bool not_prime[MAX];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int st, ed;
	cin >> st >> ed;

	not_prime[1] = true;
	not_prime[2] = false;

	for (int i = 2; i <= ed; i++) {
		if (not_prime[i] == false) {
			for (int j = i+i; j <= ed; j += i) {
				not_prime[j] = true;
			}
		}
	}

	for (int i = st; i <= ed; i++) {
		if (not_prime[i] == false)
			cout << i << '\n';
	}

	return 0;
}