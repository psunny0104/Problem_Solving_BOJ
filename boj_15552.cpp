//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_15552_ºü¸¥ A+B

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, A, B;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << A + B << "\n";
	}

	return 0;
}