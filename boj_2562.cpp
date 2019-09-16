//	@date 2019/09/16
//	@author psunny0104
//	@brief boj_2562_ÃÖ´ñ°ª

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int ans = 0;
	int odr = 0;
	int input = 0;

	for (int i = 1; i <= 9; i++) {
		cin >> input;
		if (input > ans) {
			ans = input;
			odr = i;
		}
	}

	cout << ans << "\n" << odr << "\n";

	return 0;
}