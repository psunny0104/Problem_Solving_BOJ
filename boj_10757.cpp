//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_10757_ū �� A+B

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char A[10001] = { '\0', };
	char B[10001] = { '\0', };
	//�ƹ��� ū ������ ���ص� �� �ڸ��̻� �þ ���� �����Ƿ� +1 ����
	char ans[10002] = { '\0', }; 
	
	cin >> A >> B;

	int cnt_A = 0;
	int cnt_B = 0;

	//A�� B�� �ڸ��� ���
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

	int up = 0;      //�ø� ����
	int sum = 0;     //���� �ڸ��������� ��
	int ans_cnt = 0; //���� ���� �ڸ���

	while (1)
	{
		//A�� B ��� ���� �ڸ����� ������ ��
		if (cnt_A != -1 && cnt_B != -1) 
			sum = (A[cnt_A--]-'0') + (B[cnt_B--]-'0') + up;
		//B�� ������ ��
		else if (cnt_A == -1 && cnt_B != -1)
			sum = (B[cnt_B--] - '0') + up;
		//A�� ������ ��
		else if (cnt_A != -1 && cnt_B == -1)
			sum = (A[cnt_A--] - '0') + up;

		//���� ������ 10�� �ѱ�� up�� sum �ٽ� ���
		if (sum >= 10) {
			up = sum / 10;
			sum = sum % 10;
		}
		else
			up = 0;

		//���ο� �ڸ����� ��갪 ����
		ans[ans_cnt++] = sum + '0';

		//������ �ڸ������� ���ߴµ�, �ø��� �ִ� ���
		//�ø� ���� �����ϰ� ����
		if (cnt_A == -1 && cnt_B == -1) {
			if (up == 1) {
				ans[ans_cnt++] = up + '0'; 
			}
			break;
		}
	}
	
	//�տ������� ���������Ƿ�, �Ųٷ� ���
	//stack�̿� ����
	int size = ans_cnt-1;
	for (int i = size; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}