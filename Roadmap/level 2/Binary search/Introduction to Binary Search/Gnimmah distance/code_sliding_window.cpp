#include<bits/stdc++.h>
#include <iostream>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5 + 1;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;

void solve() {
    string a,b;
    cin >> a >> b;
    int na = a.size();
    int nb = b.size();
    ll sum = 0;

    vector<int> cnt(26, 0);
    int i = 0;
    for (; i < na - nb + 1; i++) cnt[a[i] - 'a']++; 
    sum += cnt[b[0] - 'a'];

    for (int j = 0; j < b.size() - 1; j++) {
        cnt[a[j] - 'a']--;
        if (j + i < a.size()) cnt[a[j + i] - 'a']++;
        sum += cnt[b[j + 1] - 'a'];
    }

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
