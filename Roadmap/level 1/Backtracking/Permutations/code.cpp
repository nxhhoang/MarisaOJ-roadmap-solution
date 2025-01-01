#include<iostream>
#include<vector>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
using namespace std;
using ll = long long;

int n, k;
vector<bool> flag(7, 1);

void Try(string m, int i) {
    if (i == m.size()) {
        FOR(i, 0, m.size()) cout << m[i] << " ";
        cout << endl;
        return;
    }

    FOR(j, 0, n) {
        if (flag[j]) {
            m[i] = '1' + j, flag[j] = 0;
            Try(m, i + 1);
            flag[j] = 1;
        }
    }
}

int main() {
    cin >> n >> k;
    string m(k, '0');
    Try(m, 0);
    return 0;
}
