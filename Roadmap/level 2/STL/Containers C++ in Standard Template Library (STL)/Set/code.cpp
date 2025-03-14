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
    multiset<int> pos;
    multiset<int> neg;
   
    while(q--){
        int x, y;
        cin >> x >> y;
        if (x == 1) pos.insert(y), neg.insert(-y);
        else if (x == 2) {
            if (pos.find(y) != pos.end()) pos.erase(pos.find(y)), neg.erase(neg.find(-y));
        } 
        else if (x == 3) {
            auto pit = pos.ub(y);
            if (pit != pos.end()) cout << *pit << endl;
            else cout << "-1" << endl;
        } else if (x == 4) {
            auto pit = neg.lb(-y);
            if (pit != neg.end()) cout << -(*pit) << endl;
            else cout << "-1" << endl;
        }
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
