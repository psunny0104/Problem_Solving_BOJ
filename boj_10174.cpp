//	@date 2019/09/24
//	@author psunny0104
//	@brief boj_10174_팰린드롬

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	//개행 비우기
	cin.get();

	while (N--) {
		string word;
		//띄어쓰기 허용하므로 getline으로 받자
		getline(cin,word);
		
		int size = word.size();
		bool ans = true;

		//대문자->소문자
		for (int i = 0; i < size; i++) {
			if ('A' <= word[i] && word[i] <= 'Z')
				word[i] = word[i] - 'A' + 'a';
		}
		//문자 길이의 절반까지만 확인해도 됨
		for (int i = 0; i < size/2; i++) {
			if (word[i] != word[size - i - 1]) {
				ans = false;
				break;
			}
		}

		if (ans == true ? cout << "Yes\n" : cout << "No\n");
	}
	return 0;
}