#include <iostream>
#include <map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, string, greater<string>> m;

	int n;
	cin >> n;

	string name, state;
	for (int i = 0; i < n; i++) {
		cin >> name >> state;

		m[name] = state;
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second == "enter")
			cout << i->first << "\n";
	}

	return 0;
}