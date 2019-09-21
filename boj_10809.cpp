//	@date 2019/09/22
//	@author psunny0104
//	@brief boj_10809_알파벳 찾기

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int lc[26];
	char word[101] = { '\0', };
	memset(lc, -1, sizeof(lc));
	
	cin >> word;

	for (int i = 0; i < 101; i++) {
		if (word[i] == '\0')
			break;
		if(lc[word[i] -'a'] == -1)
			lc[word[i] - 'a'] = i;
	}
	
	for (int i = 0; i < 26; i++) {
		cout << lc[i] << ' ';
	}

	return 0;
}