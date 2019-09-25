//	@date 2019/09/26
//	@author psunny0104
//	@brief boj_2309_일곱 난쟁이

#include <iostream>
#include <algorithm>
using namespace std;

int ht[10];
//조합을 위한 배열
bool selected[10];
bool flag;

void cmb(int idx, int cnt)
{
	//한 번 조합을 찾았으면 더 찾지 않음
	if (flag == true)
		return;

	//2개를 골라냈으면 합을 계산하자
	if (cnt == 2) {
		int sum = 0;
		for (int i = 1; i <= 9; i++) {
			if (selected[i] == false)
				sum += ht[i];
		}
		if (sum == 100) {
			for (int i = 1; i <= 9; i++) {
				if (selected[i] == false)
					cout << ht[i] << '\n';
			}
			flag = true;
			return;
		}
	}

	for (int i = idx; i <= 9; i++) {
		if (selected[i] == true)
			continue;

		selected[i] = true;
		cmb(i, cnt + 1);
		selected[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	//조합 9c2

	for (int i = 1; i <= 9; i++) {
		cin >> ht[i];
	}
	//미리 정렬
	sort(ht, ht + 10);
	//배열의 인덱스를 1~9를 이용하므로
	//idx가 1부터 시작임을 주의!
	cmb(1, 0);

	return 0;
}