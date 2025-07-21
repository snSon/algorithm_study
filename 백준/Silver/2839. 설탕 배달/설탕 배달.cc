#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, count_3 = 0, count_5 = 0;
	cin >> n;

	while (n % 5 != 0) {
		n -= 3;
		if (n < 0)
			break;
		count_3++;
	}

	if (n < 0)
		cout << -1;
	else
		cout << count_3 + (n / 5);

	return 0;


}