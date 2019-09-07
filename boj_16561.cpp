//	@date 2019/09/07
//	@author psunny0104
//	@brief boj_16561_3�� ���

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, ans = 0;
	cin >> N;

	for (int i = 3; i <= N; i += 3) { //3 ~ N���� 3�� ���ذ��� ù��° �� ����
		for (int j = 3; j <= N; j += 3) { //�������� ������� �ι�° �� ����
			if (N - i - j >= 3) //N���� ù��° ���� �ι�° ���� �� ���� ������ 3�� ��� or 0��
				ans++;         //0�� �ƴϸ� �� ���� 3�� ����� ������ ǥ���� �Ǵ� ���� 
		}					   //���� ���� ���� 3�� ����� >=3 Ȥ�� >0 �� ������ �����ϸ� ��
	}

	cout << ans << "\n";

	return 0;
}