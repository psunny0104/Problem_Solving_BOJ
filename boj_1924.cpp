//	@date 2019/10/18
//	@author psunny0104
//	@brief boj_1924_2007년

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, d;
	cin >> m >> d;

	int cnt = d;
	for (int i = 1; i < m; i++) {
		if (i == 4 || i == 6 || i == 9 || i == 11) {
			cnt += 30;
		}
		else if (i == 2) {
			cnt += 28;
		}
		else {
			cnt += 31;
		}
	}
	cnt = cnt % 7;
	if (cnt == 1)
		cout << "MON\n";
	else if(cnt == 2)
		cout << "TUE\n";
	else if (cnt == 3)
		cout << "WED\n";
	else if (cnt == 4)
		cout << "THU\n";
	else if (cnt == 5)
		cout << "FRI\n";
	else if (cnt == 6)
		cout << "SAT\n";
	else if (cnt == 0)
		cout << "SUN\n";
	return 0;
}