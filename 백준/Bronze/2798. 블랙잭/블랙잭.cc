#include <iostream>

using namespace std;

int main() {

	int n, m;

	cin >> n >> m;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int repeat = (n * (n - 1) * (n - 2)) / (3 * 2 * 1);

	int a = 0, b = 1, c = 2;
	int sum = 0, answer = 0;

	for (int i = 0; i < repeat; i++) {
		sum = arr[a] + arr[b] + arr[c];
		if ((sum <= m) && (m - sum < m-answer)) {
			answer = sum;
		}
		
		c++;
		if (c >= n) {
			b++;
			c = b + 1;
			if (b >= (n-1)) {
				a++;
				b = a + 1;
				c = b + 1;
			}
		}
	}

	cout << answer;

	return 0;
}