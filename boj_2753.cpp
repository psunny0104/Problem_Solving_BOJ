//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_2753_À±³â

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	if ((N % 4 == 0 && N % 100 != 0) || N % 400 == 0) {
		cout << 1 << "\n";
	}
	else
		cout << 0 << "\n";

	return 0;
}