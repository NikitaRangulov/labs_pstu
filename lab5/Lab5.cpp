#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_possible(string& s, int n) {
	if (s.length() != n * n) {
		return false;
	}

	vector<string> substrings(n);
	for (int i = 0; i < n; i++) {
		substrings[i] = s.substr(i * n, n);
	}

	sort(substrings.begin(), substrings.end());

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (substrings[j][i] <= substrings[j - 1][i]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	setlocale(0, "");
	int n;
	string s;

	cout << "Введите N: ";
	cin >> n;
	cout << "Введите строку из " << n * n << " цифр: ";
	cin >> s;

	if (is_possible(s, n)) {
		cout << "Цифры можно расположить в порядке возрастания" << endl;
	}
	else {
		cout << "Цифры нельзя расположить в порядке возрастания" << endl;
	}
}