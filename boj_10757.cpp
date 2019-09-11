//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_10757_Å« ¼ö A+B

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char A[10001] = { '\0', };
	char B[10001] = { '\0', };
	char ans[10002] = { '\0', };
	
	cin >> A >> B;

	int cnt_A = 0;
	int cnt_B = 0;

	for (int i = 0; i < 10001; i++) {
		if (A[i] == '\0') {
			cnt_A = i-1;
			break;
		}
	}
	for (int i = 0; i < 10001; i++) {
		if (B[i] == '\0') {
			cnt_B = i-1;
			break;
		}
	}

	int up = 0;
	int sum = 0;
	int ans_cnt = 0;

	while (1)
	{
		if (cnt_A != -1 && cnt_B != -1)
			sum = (A[cnt_A--]-'0') + (B[cnt_B--]-'0') + up;
		else if (cnt_A == -1 && cnt_B != -1)
			sum = (B[cnt_B--] - '0') + up;
		else if (cnt_A != -1 && cnt_B == -1)
			sum = (A[cnt_A--] - '0') + up;

		if (sum >= 10) {
			up = sum / 10;
			sum = sum % 10;
		}
		else
			up = 0;

		ans[ans_cnt++] = sum + '0';

		if (cnt_A == -1 && cnt_B == -1) {
			if (up == 1) {
				ans[ans_cnt++] = up + '0'; 
			}
			break;
		}
	}
	
	int size = ans_cnt-1;
	for (int i = size; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}