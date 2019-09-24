//	@date 2019/09/24
//	@author psunny0104
//	@brief boj_13235_팰린드롬

#include <iostream>
#include <string>
using namespace std;

//팰린드롬은 앞에서부터 읽을 때와 
//뒤에서부터 읽을 때가 똑같은 단어를 의미한다. 
//eg eve->팰린드롬, eeve->X
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string word;
	cin >> word;

	int size = word.size();
	for (int i = 0; i < size; i++) {
		if (word[i] != word[size - i - 1]) {
			cout << "false\n";
			return 0;
		}
	}

	cout << "true\n";

	return 0;
}