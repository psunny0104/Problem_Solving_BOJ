//	@date 2019/09/21
//	@author psunny0104
//	@brief boj_10808 알파벳 개수

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char word[101] = {'\0',};
	int word_cnt[26] = { 0, };
	int cnt = 0;

	cin >> word;

	while (true) {
		if (word[cnt] == '\0')
			break;
		word_cnt[word[cnt] - 97]++;
		cnt++;
	}

	for (int i = 0; i < 26; i++) {
		cout << word_cnt[i] << ' ';
	}

	return 0;
}