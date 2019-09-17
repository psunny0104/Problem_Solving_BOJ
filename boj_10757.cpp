//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_10757_큰 수 A+B

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char A[10001] = { '\0', };
	char B[10001] = { '\0', };
	//아무리 큰 값끼리 더해도 두 자리이상 늘어날 수는 없으므로 +1 해줌
	char ans[10002] = { '\0', }; 
	
	cin >> A >> B;

	int cnt_A = 0;
	int cnt_B = 0;

	//A와 B의 자릿수 계산
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

	int up = 0;      //올림 저장
	int sum = 0;     //같은 자릿수끼리의 합
	int ans_cnt = 0; //더한 값의 자릿수

	while (1)
	{
		//A와 B 모두 더할 자릿수가 남았을 때
		if (cnt_A != -1 && cnt_B != -1) 
			sum = (A[cnt_A--]-'0') + (B[cnt_B--]-'0') + up;
		//B만 남았을 떄
		else if (cnt_A == -1 && cnt_B != -1)
			sum = (B[cnt_B--] - '0') + up;
		//A만 남았을 때
		else if (cnt_A != -1 && cnt_B == -1)
			sum = (A[cnt_A--] - '0') + up;

		//더한 값들이 10을 넘기면 up과 sum 다시 계산
		if (sum >= 10) {
			up = sum / 10;
			sum = sum % 10;
		}
		else
			up = 0;

		//새로운 자릿수에 계산값 저장
		ans[ans_cnt++] = sum + '0';

		//마지막 자릿수끼리 더했는데, 올림이 있는 경우
		//올림 값만 저장하고 종료
		if (cnt_A == -1 && cnt_B == -1) {
			if (up == 1) {
				ans[ans_cnt++] = up + '0'; 
			}
			break;
		}
	}
	
	//앞에서부터 저장했으므로, 거꾸로 출력
	//stack이용 가능
	int size = ans_cnt-1;
	for (int i = size; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}