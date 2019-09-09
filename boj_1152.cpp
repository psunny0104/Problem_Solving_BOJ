//	@date 2019/09/09
//	@author psunny0104
//	@brief boj_1152_단어의 개수

#include <iostream>
#define MAX 1000001
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char input[MAX];
	int ans = 0;
	cin.getline(input, sizeof(input));

	for (int i = 1; i <= MAX - 1; i++) {
		if (input[i] == '\0') {
			if (input[i - 1] == ' ')
				ans--;
			break;
		}
		if (input[i] == ' ')
			ans++;
	}

	cout << ans+1 << "\n";

	return 0;
}