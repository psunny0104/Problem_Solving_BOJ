/*
	@date 2020/06/08
	@author psunny0104
	@brief boj_2480_주사위 세개
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int arr[3];;
	cin >> arr[0]>>arr[1]>>arr[2];

	if (arr[0] == arr[1] && arr[0] == arr[2] && arr[1] == arr[2]) {
		cout << 10000 + arr[0] * 1000 << "\n";
	}
	else if (arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2]) {
		sort(arr, arr + 3);
		cout << arr[2] * 100 << "\n";
	}
	else {
		if (arr[0] == arr[1])
			cout << 1000 + arr[0] * 100 << "\n";
		else if(arr[0] == arr[2])
			cout << 1000 + arr[0] * 100 << "\n";
		else
			cout << 1000 + arr[2] * 100 << "\n";
	}
}