//	@date 2019/10/02
//	@author psunny0104
//	@brief boj_8958_OX퀴즈

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		string input;
		cin >> input;
		int scr = 0;
		int cnt = 0;
		for (int i = 0; i<input.size(); i++) {
			if (input[i] == 'X') {
				cnt = 0;
			}
			else {
				cnt++;
				scr += cnt;
			}
		}
		cout << scr << '\n';
	}

	return 0;
}