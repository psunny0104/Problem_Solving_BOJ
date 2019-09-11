//	@date 2019/09/11
//	@author psunny0104
//	@brief boj_16236_아기 상어

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 401 //상어의 이동이 갱신이 되는지 확인할 때 사용
using namespace std;

int N;
int map[21][21];
int dist[21][21];//bfs 방문 체크 및 거리 저장

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1, 0, 0 };

//상어 구조체
struct SHARK{
	int x; //x좌표
	int y; //y좌표
	int size = 2; //상어의 크기, 초기값 2
	int cnt = 0;  //상어가 먹은 물고기 수
	int step = 0; //상어가 이동한 거리
} sk;

void bfs(int y, int x)
{
	memset(dist, 0, sizeof(dist)); //탐색을 위한 초기화
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	dist[y][x] = 1;//초기값 1로 시작

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			//지도 밖이면 X
			if (nx<1 || ny<1 || nx>N || ny>N)
				continue;
			
			//이미 방문했으면 X
			if (dist[ny][nx] > 0)
				continue;

			//상어의 사이즈보다 크면 X
			if (map[ny][nx] > sk.size)
				continue;
			
			//빈 칸이거나 상어의 사이즈보다 작으면
			if (map[ny][nx] >= 0) {
				dist[ny][nx] += dist[y][x]+1; //기존 거리에 +1해서 저장
				q.push(make_pair(ny, nx));
			}
		}
	}
}

bool select_feed()
{
	//이중 for문으로 dist배열을 모두 탐색하면
	//최소거리, 위쪽, 아래쪽, 순으로 갱신이 됨
	//INF로 초기화하여 처음부터 최솟값으로 갱신 되도록 함
	int min_x = 0, min_y = 0, min_val = INF; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//map에 물고기가 존재하지 않거나
			//상어의 사이즈보다 크거나 같으면 먹지 못 함
			if (map[i][j] <= 0 || sk.size <= map[i][j])
				continue; 

			//물고기가 존재하고, 이동거리가 기존보다 작으면 갱신
			if (dist[i][j] > 1 && dist[i][j] < min_val) {
				min_x = j;
				min_y = i;
				min_val = dist[i][j];
			}
		}
	}

	//INF 그대로라면 상어가 더 이상 먹이를 먹을 수 없으므로 끝내고 false 리턴
	if (min_val == INF)
		return false;

	//상어를 물고기의 좌표로 이동시키고
	sk.x = min_x;
	sk.y = min_y;

	//상어가 먹은 물고기 수 1 더해 줌
	sk.cnt++;

	//이동 거리 더해줌 시작을 1로 했으므로, 1빼고 더함
	sk.step += dist[min_y][min_x] - 1;

	//먹은 곳은 0 물고기 없앰
	map[sk.y][sk.x] = 0;
	
	//먹은 물고기 수와 사이즈가 같으면
	//사이즈를 키우고 먹은 물고기 수 0으로 초기화
	if (sk.cnt == sk.size) {
		sk.size++;
		sk.cnt = 0;
	}
	//true 리턴
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
			//상어의 시작 위치 구조체에 저장
			if (map[i][j] == 9) {
				sk.x = j;
				sk.y = i;
			}
		}
	}

	bool flag = false;   //이동유무 저장 변수
	map[sk.y][sk.x] = 0; //상어의 시작 위치 0으로 바꿔 줌

	//bfs를 통한 먹이 완전 탐색과
	//우선순위를 고려한 먹이 사냥 반복
	while (1) {
		bfs(sk.y, sk.x);
		flag = select_feed(); //true면 먹이 사냥 가능->반복
		if (!flag) //false면 먹이를 사냥할 수 없으므로 종료
			break;
	}
	
	cout << sk.step << "\n";

	return 0;
}