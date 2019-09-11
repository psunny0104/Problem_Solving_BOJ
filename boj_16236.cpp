//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_16236_�Ʊ� ���

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 401 //����� �̵��� ������ �Ǵ��� Ȯ���� �� ���
using namespace std;

int N;
int map[21][21];
int dist[21][21];//bfs �湮 üũ �� �Ÿ� ����

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1, 0, 0 };

//��� ����ü
struct SHARK{
	int x; //x��ǥ
	int y; //y��ǥ
	int size = 2; //����� ũ��, �ʱⰪ 2
	int cnt = 0;  //�� ���� ����� ��
	int step = 0; //�� �̵��� �Ÿ�
} sk;

void bfs(int y, int x)
{
	memset(dist, 0, sizeof(dist)); //Ž���� ���� �ʱ�ȭ
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	dist[y][x] = 1;//�ʱⰪ 1�� ����

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			//���� ���̸� X
			if (nx<1 || ny<1 || nx>N || ny>N)
				continue;
			
			//�̹� �湮������ X
			if (dist[ny][nx] > 0)
				continue;

			//����� ������� ũ�� X
			if (map[ny][nx] > sk.size)
				continue;
			
			//�� ĭ�̰ų� ����� ������� ������
			if (map[ny][nx] >= 0) {
				dist[ny][nx] += dist[y][x]+1; //���� �Ÿ��� +1�ؼ� ����
				q.push(make_pair(ny, nx));
			}
		}
	}
}

bool select_feed()
{
	//���� for������ dist�迭�� ��� Ž���ϸ�
	//�ּҰŸ�, ����, �Ʒ���, ������ ������ ��
	//INF�� �ʱ�ȭ�Ͽ� ó������ �ּڰ����� ���� �ǵ��� ��
	int min_x = 0, min_y = 0, min_val = INF; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//map�� ����Ⱑ �������� �ʰų�
			//����� ������� ũ�ų� ������ ���� �� ��
			if (map[i][j] <= 0 || sk.size <= map[i][j])
				continue; 

			//����Ⱑ �����ϰ�, �̵��Ÿ��� �������� ������ ����
			if (dist[i][j] > 1 && dist[i][j] < min_val) {
				min_x = j;
				min_y = i;
				min_val = dist[i][j];
			}
		}
	}

	//INF �״�ζ�� �� �� �̻� ���̸� ���� �� �����Ƿ� ������ false ����
	if (min_val == INF)
		return false;

	//�� ������� ��ǥ�� �̵���Ű��
	sk.x = min_x;
	sk.y = min_y;

	//�� ���� ����� �� 1 ���� ��
	sk.cnt++;

	//�̵� �Ÿ� ������ ������ 1�� �����Ƿ�, 1���� ����
	sk.step += dist[min_y][min_x] - 1;

	//���� ���� 0 ����� ����
	map[sk.y][sk.x] = 0;
	
	//���� ����� ���� ����� ������
	//����� Ű��� ���� ����� �� 0���� �ʱ�ȭ
	if (sk.cnt == sk.size) {
		sk.size++;
		sk.cnt = 0;
	}
	//true ����
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			//����� ���� ��ġ ����ü�� ����
			if (map[i][j] == 9) {
				sk.x = j;
				sk.y = i;
			}
		}
	}

	bool flag = false;   //�̵����� ���� ����
	map[sk.y][sk.x] = 0; //����� ���� ��ġ 0���� �ٲ� ��

	//bfs�� ���� ���� ���� Ž����
	//�켱������ ����� ���� ��� �ݺ�
	while (1) {
		bfs(sk.y, sk.x);
		flag = select_feed(); //true�� ���� ��� ����->�ݺ�
		if (!flag) //false�� ���̸� ����� �� �����Ƿ� ����
			break;
	}
	
	cout << sk.step << "\n";

	return 0;
}