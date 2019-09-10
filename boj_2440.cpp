//	@date 2019/09/10
//	@author psunny0104
//	@brief boj_2440_º° Âï±â - 3

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin>>N;

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}