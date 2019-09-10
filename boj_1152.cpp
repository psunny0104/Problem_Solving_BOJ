//	@date 2019/09/09
//	@author psunny0104
//	@brief boj_1152_단어의 개수

#include <iostream>
#define MAX 1000001 //가능한 문자의 개수+NULL을 위한 +1
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char input[MAX];
	int ans = 0;
	cin.getline(input, sizeof(input));

	//입력받은 모든 문자를 확인하면서 띄어쓰기 개수 카운트
	for (int i = 1; i <= MAX - 1; i++) {  //실제 문자가 입력될 수 있는 MAX-1까지 반복함
		if (input[i] == '\0') { //마지막문자의 띄어쓰기를 확인하기위해 NULL인지 확인
			if (input[i - 1] == ' ') { //NULL 앞의 입력받은 문자열의 
				ans--;			       //마지막 문자가 띄어쓰기이면 - 해줌
			}
			break; //NULL은 입력받은 모든 문자열의 끝이므로, for문이 더 돌지 않도록 break
		}
		if (input[i] == ' ')
			ans++;
	}

	cout << ans+1 << "\n";

	return 0;
}