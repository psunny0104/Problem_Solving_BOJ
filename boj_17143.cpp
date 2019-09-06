//	@date 2019/09/05
//	@author psunny0104
//	@brief boj_17143_���ÿ�

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//��� ���� ������ ���� ����ü �迭
struct SK {
	int spd; //�ӷ�
	int dir; //�̵� ����
	int size;//ũ��
	int y;   //y��ǥ(R)
	int x;   //x��ǥ(C)
	bool death = true; //�����ų� �������� ������ ��� �ִ� ������ �ʱ�ȭ
	                   //true�� ��� ����,false�� ����
} sk[100 * 100 + 1]; //sk[100*100]...........

int Y, X, M, ans;

//�̵� ���� �迭
int dx[] = { 0, 0, 0, +1, -1 }; //���ڸ�, ��, �Ʒ�, ��, ��
int dy[] = { 0, -1, +1, 0, 0 };

//�ش� ĭ�� �� �ִ��� �ߺ�üũ�� ���� �迭
int st[101][101];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Y >> X >> M;
	for (int i = 1; i <= M; i++) {//x, y,�ӷ�,�̵�����,ũ��
		cin >> sk[i].y >> sk[i].x >> sk[i].spd >> sk[i].dir >> sk[i].size;
	}

	int nsw = 0; //���ÿ��� ��ġ, 0���� ����
	while (1)
	{
		nsw++;       //���ÿ� �̵�, ���, ����̵�, ����ߺ�üũ ������ �̷����
		if (nsw > X) //���ÿ��� �������� �־��� �ִ� X��ǥ�� ����� ��� �۾� ����
			break;

		int idx = 0; //���ÿ��� �̹� x��ǥ���� ���� �� �ִ� ����� �ε��� ���� ����
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death) //���� ���� ����
				continue;

			if (sk[i].x == nsw) {//���ÿհ� ����� x��ǥ�� ������ Ȯ��
				if (idx == 0)    //ó������ ������ ���� �ٷ� ����� �ε��� ����
					idx = i;
				else { //�̹� ����� �� �ִٸ� ���� y��ǥ�� ���Ͽ�
					   //�� ���� ����� ���� ���ÿ��� ���� ����� �ε����� ����
					   //�ϳ��� ĭ�� �� �̻��� �� �ִ� ��찡 ���ٰ� �־������Ƿ� �ϳ��� �� ����
					if (sk[i].y < sk[idx].y) //i��° ����� y��ǥ�� �������� �� ������ �ε��� ����
						idx = i; //����
				}
			}
		}

		//�ε����� 0�� �ƴ� ������ �ε��� ������ 1~M������ ������
		//������ �Ǿ��ٸ� �ش� �� ���̰� �信 �ش� ����� ����� ����
		if (idx != 0) {
			sk[idx].death = false;
			ans += sk[idx].size;
		}

		//��� �̵�
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death)
				continue;

			int step = sk[i].spd; //�ش� ����� �ӵ��� ���� ����
			while (1) {           //�ݺ����� ���鼭 ����� �ӵ���ŭ ���������� ����
				if (step == 0)
					break;
				if (sk[i].dir == 1) { //���⿡ ���� �ٸ�
					if (step <= sk[i].y - 1) { //���� ������ �̵��� �� �ִ� �Ÿ����� �۰ų� ������
						sk[i].y -= step;       //�ٷ� �̵�
						step = 0;              //���� ���� 0
						if (sk[i].y == 1)      //�̵� �� �� ���� �����ߴٸ� 
							sk[i].dir = 2;     //�ݴ� ������ �ٲ� ��
					}
					else { //���� ������ �̵��� �� �ִ� �Ÿ����� ũ�ٸ�
						step = step - (sk[i].y - 1); //�̵� ������ �ּ� Ȥ�� �ִ� �������� ���̸�ŭ�� ���ܿ��� ��
						sk[i].y = 1;                 //�̵� �������� ���� ������ ���� �ּ� Ȥ�� �ִ� ������ ��ġ �̵�
						sk[i].dir = 2;               //���� �ٲ� �� -> ���� while���� ���ο� ������ ���ǹ����� ó��
					}
				}    
				else if (sk[i].dir == 2) { //�Ʒ�, ������, ���� ��� ���� ������� ó��
					if (step <= Y - sk[i].y) {
						sk[i].y += step;
						step = 0;
						if (sk[i].y == Y)
							sk[i].dir = 1;
					}
					else {
						step = step - (Y - sk[i].y);
						sk[i].y = Y;
						sk[i].dir = 1;
					}
				}
				else if (sk[i].dir == 3) {
					if (step <= X - sk[i].x) {
						sk[i].x += step;
						step = 0;
						if (sk[i].x == X)
							sk[i].dir = 4;
					}
					else {
						step = step - (X - sk[i].x);
						sk[i].x = X;
						sk[i].dir = 4;
					}
				}
				else if (sk[i].dir == 4) {
					if (step <= sk[i].x - 1) {
						sk[i].x -= step;
						step = 0;
						if (sk[i].x == 1)
							sk[i].dir = 3;
					}
					else {
						step = step - (sk[i].x - 1);
						sk[i].x = 1;
						sk[i].dir = 3;
					}
				}
			}
		}

		//����ߺ�üũ
		memset(st, 0, sizeof(st)); //�ߺ��� üũ�ϱ� ���� ������ �迭 �ʱ�ȭ
		for (int i = 1; i <= M; i++) {
			if (!sk[i].death) //����ִ� �� üũ
				continue;

			int tmp_y = sk[i].y;
			int tmp_x = sk[i].x;
			if (!st[tmp_y][tmp_x])    //�ش� �����ǿ� ���� �� ���ٸ�
				st[tmp_y][tmp_x] = i; //����� �ε��� ����
			else if (st[tmp_y][tmp_x] != 0) {
				if (sk[st[tmp_y][tmp_x]].size < sk[i].size) {  //�̹� ����� �� �ִٸ� ����� ��
					sk[st[tmp_y][tmp_x]].death = false;        //���ο� ����� ����� �� ũ�ٸ�
					st[tmp_y][tmp_x] = i;                      //���� ���� ���̰�, ������ �迭�� ��� �ε��� ����
				}
				else
					sk[i].death = false; //���ο� ����� ����� �� �۴ٸ� �ش� ��� ����
			}
		}
	}

	cout << ans << "\n";

	return 0;
}