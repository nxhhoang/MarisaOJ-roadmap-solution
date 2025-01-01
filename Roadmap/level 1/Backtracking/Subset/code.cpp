#include<iostream>
#include<vector>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
using namespace std;
using ll = long long;

int n, k;
vector<int> ar;

void Try(vector<int> ar, int i) {
    if (i == ar.size()) {
        FOR(i, 1, k + 1) cout << ar.at(i) << " ";
        cout << '\n';
        return;
    }
    FOR(j, ar[i - 1] + 1, n - (k - i) + 1) { // a b c d    // 17 18 19 20
        ar[i] = j;
        Try(ar, i + 1);
    }
}

int main() {
    cin >> n >> k;
    ar.resize(k + 1);
    FOR(i, 0, k + 1) ar[i] = 0; // what's wrong with this code
    Try(ar, 1);
    return 0;
}
