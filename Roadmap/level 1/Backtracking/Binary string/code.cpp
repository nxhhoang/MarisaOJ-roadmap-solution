#include<iostream>
using namespace std;

void solve(string m, int i) {
	for (int j = 0; j <= 1; j++) {
		m[i] = j + '0';
		if (m[i] == '1') {
			string t = m.substr(0, m.size() - 1);
			cout << t << endl;
		}
		if (i == m.size() - 1) return;
		else solve(m, i + 1);
	}
}

int main() {
	int n;
	cin >> n;
	string m;
	for (int i = 0; i < n; i++) m += '0';
	cout << m << endl;
	solve(m + '0', 0);
	return 0;
}
