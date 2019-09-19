//	@date 2019/09/20
//	@author psunny0104
//	@brief boj_2609_최대공약수와 최소공배수

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int g = GCD(a, b);
	cout << g << '\n';
	cout << a * b / g << '\n';

	return 0;
}