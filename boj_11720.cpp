//	@date 2019/09/07
//	@author psunny0104
//	@brief boj_11720_������ ��

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	char input[101]; //���ڿ��� input����
	cin >>N>>input;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += input[i] - '0';//�� ��¥�� ���ڷ� ��ȯ �� sum�� ����
	}
	cout << sum << "\n";

	return 0;
}