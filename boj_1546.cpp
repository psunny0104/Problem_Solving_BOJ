//	@date 2019/10/03
//	@author psunny0104
//	@brief boj_1546_평균

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	double scr[1000] = { 0, };
	double max = 0;
	double sum = 0;
	for (int i = 0; i < T; i++) {
		cin >> scr[i];
		if (scr[i] > max)
			max = scr[i];
	}
	for (int i = 0; i < T; i++) {
		scr[i] = scr[i] / max * 100;
		sum += scr[i];
	}

	cout.precision(2);
	cout << fixed;
	cout << sum / T << '\n';
	return 0;
}