//	@date 2019/09/08
//	@author psunny0104
//	@brief boj_11718_그대로 출력하기

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char input[101] = { "\0", };

	while (cin.getline(input, sizeof(input))) { //getline을 쓰면 공백을 포함해서
		cout << input << "\n";                  //한 줄을 통째로 입력받을 수 있다!
	}

	return 0;
}
