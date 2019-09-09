//	@date 2019/09/09
//	@author psunny0104
//	@brief boj_11719_그대로 출력하기 2

#include <iostream>
using namespace std;

int main()
{
	char input[101] = { "\0", };

	while (cin.getline(input, sizeof(input))) {
		cout << input << "\n";
	}

	return 0;
}