//	@date 2019/09/05
//	@author psunny0104
//	@brief boj_17140_������ �迭�� ����

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int R, C, K; 
int cur_r, cur_c; //���� ��� ���� ������ �����ϱ� ���� ����
int map[101][101]; //���ڸ� �����ϱ� ���� ������ �迭
int cnt[101]; //������ �� ���ڵ��� ������ ī��Ʈ�ϱ� ���� �迭

//���� ������ �� ������ �����ϱ� ���� �켱���� ť
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void opr()
{
	//���꿡���� for���� ������ cur ������ �ϰԵǸ� �߰��� ������ �� ���
	//�� ������ ���̳� �࿡�� �ʿ� ���� ������ �߰���
	//���� ó�� ��� ���� ������ �����ϱ� ���� ������ ���� ���
	int pv_c = cur_c; //��, x
	int pv_r = cur_r; //��, y

	if (cur_r >= cur_c) { //R ����
		for (int i = 1; i <= pv_r; i++) {
			memset(cnt, 0, sizeof(cnt)); //ī��Ʈ �迭 �ʱ�ȭ
			for (int j = 1; j <= pv_c; j++) { //���� �����ϴ� ���� ī��Ʈ
				int val = map[i][j];
				cnt[val]++;
			}

			//ī��Ʈ�� ���ڿ� Ƚ���� �켱���� ť�� ����
			//����Ƚ���� pair���� first�� ����Ǿ� �����Ƿ�
			//����Ƚ��, ���� ������ �������� ���ĵ�
			for (int j = 1; j <= 100; j++) { 
				if (!cnt[j])
					continue;
				//pq�� size�� 50���� �����Ͽ� ���̰� 100�� ���� �ʵ��� ��
				if (pq.size() <= 50)
					pq.push(make_pair(cnt[j], j)); //����Ƚ��, ����
				else
					break;
			}

			//���� ���̰� ��������� Ȯ��
			//��������� cur���� ����
			int size_pq = pq.size();
			if (size_pq * 2 > cur_c)
				cur_c = size_pq * 2;

			//���� ���� cur�� ������ŭ 0���� �ʱ�ȭ
			for (int j = 1; j <= cur_c; j++)
				map[i][j] = 0;

			//���̸� 100���� ����Ͽ� ���ڿ� ����Ƚ�������� �� ����
			for (int j = 1; j <= size_pq*2 - 1; j+=2) {
				//if (j > 50) //pair�̹Ƿ� ���� 50�� ������ ���� ���� ����
				//	break;
				map[i][j] = pq.top().second;
				map[i][j + 1] = pq.top().first;
				pq.pop();
			}
		}
	}
	//C ������ R���꿡�� c�� r�� ���õ� ������ map�迭�� �ε����� ���� �ٲ���
	else { 
		for (int i = 1; i <= pv_c; i++) {
			memset(cnt, 0, sizeof(cnt));

			for (int j = 1; j <= pv_r; j++) {
				int val = map[j][i];
				cnt[val]++;
			}
			for (int j = 1; j <= 100; j++) {
				if (!cnt[j])
					continue;
				if (pq.size() <= 50)
					pq.push(make_pair(cnt[j], j)); //����Ƚ��, ����
				else
					break;
			}
			int size_pq = pq.size();
			if (size_pq * 2 > cur_r)
				cur_r = size_pq * 2;
			for (int j = 1; j <= cur_r; j++)
				map[j][i] = 0;
			for (int j = 1; j <= size_pq * 2 - 1; j += 2) {
				//if (j > 50)
				//	break;
				map[j][i] = pq.top().second;
				map[j+1][i] = pq.top().first;
				pq.pop();
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >>C >> K;
	
	//�ʱⰪ�� 3x3�� �迭�� ����
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	
	cur_r = 3, cur_c = 3; //��,�� ���� 3���� �ʱ�ȭ

	int ans = 0;

	//���� ������ 2�����迭������ ù��° �ε���
	//���� ������ 2�����迭������ �ι�° �ε������� ����!
	//������ ������ ������ ������ while���� ����
	//while�ȿ��� ���� ���� �� �ð��� 1�� ������
	while (map[R][C] != K) {

		//�ð��� 100�� �Ѿ�� -1 �� ����
		//ans���� �Ŀ� while�� �ٽ� ����� ���� 101��°�� ������ ����
		//���� ans > 100�� �ƴ� ans == 100���� �Ǵ��� ��
		//ans >100���� �� ��� while���� �� �� �� ���Ե�(����� ����)
		if (ans == 100) { 
			ans = -1;
			break;
		}
		opr(); //���� ����
		ans++; //�ð� ����
	}

	cout << ans << "\n";

	return 0;
}