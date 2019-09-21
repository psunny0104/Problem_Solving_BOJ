//	@date 2019/09/21
//	@author psunny0104
//	@brief boj_11653_소인수분해

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int prime = 2;
	while (true) {
		if (N == 1) //입력이 1도 들어옴
			return 0;
		if (N % prime == 0) {
			cout << prime << '\n';
			N /= prime;
			if (N == 1)
				break;
		}
		else
			prime++;
	}

	return 0;
}