//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_1978_소수 찾기

#include <iostream>
using namespace std;

int is_prime(int input)
{
	if (input < 2)
		return 0;
	for (int i = 2; i * i <= input; i++) {
		if (input % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, num, ans = 0;
	cin >> N;

	while (N--) {
		cin >> num;
		ans += is_prime(num);
	}

	cout << ans << '\n';

	return 0;
}
