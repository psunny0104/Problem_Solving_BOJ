//	@date 2019/09/16
//	@author psunny0104
//	@brief boj_2739_±¸±¸´Ü

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	for (int i = 1; i <= 9; i++) {
		cout << N << " * " << i << " = " << N * i << "\n";
	}

	return 0;
}