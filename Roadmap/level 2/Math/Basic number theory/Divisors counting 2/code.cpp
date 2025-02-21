// nxxhoang - the dreamer
#include<bits/stdc++.h>
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
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve() {
    int q;
    cin >> q;

    vector<bool> prime(31700, 1);
    vector<int> pri_save;
    for (int i = 2; i < 31700; i++){
        if (prime[i] == 0) continue;
        pri_save.push_back(i);
        for (ll j = 1ll * i * i; j < 31700; j += i) prime[j] = 0;
    }

    while(q--){
        int x;
        cin >> x;
        ll sum = 1;
        for (int i = 0; i < pri_save.size(); i++) {
            int cnt = 0;
            while(x % pri_save[i] == 0){
                cnt++;
                x /= pri_save[i];
            }
            cnt++;
            sum *= cnt;
            if (x == 1) break;
        }
        if (x > 1) sum *= 2;
        cout << sum << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
