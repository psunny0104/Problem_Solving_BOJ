//	@date 2019/09/30
//	@author psunny0104
//	@brief boj_10871_X보다 작은 수

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X, input;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input < X)
			cout << input << ' ';
	}
	return 0;
}