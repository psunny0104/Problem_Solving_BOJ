//	@date 2019/09/09
//	@author psunny0104
//	@brief boj_1152_�ܾ��� ����

#include <iostream>
#define MAX 1000001 //������ ������ ����+NULL�� ���� +1
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char input[MAX];
	int ans = 0;
	cin.getline(input, sizeof(input));

	//�Է¹��� ��� ���ڸ� Ȯ���ϸ鼭 ���� ���� ī��Ʈ
	for (int i = 1; i <= MAX - 1; i++) {  //���� ���ڰ� �Էµ� �� �ִ� MAX-1���� �ݺ���
		if (input[i] == '\0') { //������������ ���⸦ Ȯ���ϱ����� NULL���� Ȯ��
			if (input[i - 1] == ' ') { //NULL ���� �Է¹��� ���ڿ��� 
				ans--;			       //������ ���ڰ� �����̸� - ����
			}
			break; //NULL�� �Է¹��� ��� ���ڿ��� ���̹Ƿ�, for���� �� ���� �ʵ��� break
		}
		if (input[i] == ' ')
			ans++;
	}

	cout << ans+1 << "\n";

	return 0;
}