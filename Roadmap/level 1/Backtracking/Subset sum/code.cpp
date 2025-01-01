#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
 
using namespace std;
using ll = long long;
ll n, k;
ll ar[20];
 
bool Try(string pr, int i) {
    if (i == pr.size()) {
        ll sum = 0; 
        FOR(i, 0, n) sum += (pr[i] - '0') * ar[i];
        if (sum == k) return true;
        else return false;
    }
    FOR(j, 0, 2) {
        pr[i] = j + '0';
        if (Try(pr, i + 1)) return true;
    }

    return false;
}
 
void solve() {
    cin >> n >> k;
	string pr(n, '0');
	FOR(i, 0, n) cin >> ar[i]; 
	if (Try(pr, 0)) cout << "YES";
	else cout << "NO";
    return; 
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    solve();
    return 0;
}
