//	@date 2019/09/16
//	@author psunny0104
//	@brief boj_2349_�� ��� - 2

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = N; j >= 1; j--) {
			if (j > i)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}

	return 0;
}