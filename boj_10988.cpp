//	@date 2019/09/24
//	@author psunny0104
//	@brief boj_10988_팰린드롬인지 확인하기

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string word;
	bool ans = true;
	cin >> word;
	for (int i = 0; i < word.size() / 2; i++) {
		if (word[i] != word[word.size() - i - 1]) {
			ans = false;
			break;
		}
	}

	if (ans == true ? cout << 1 << '\n' : cout << 0 << '\n');

	return 0;
}