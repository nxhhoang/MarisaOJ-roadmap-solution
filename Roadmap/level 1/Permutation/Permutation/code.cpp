#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 7;

int n;
int arr[9];


//void tryy() {
//    
//}

void solve()
{
    cin >> n;
    FOR(i, 0, n) arr[i] = i + 1;
    while (1) {
        FOR(i, 0, n) cout << arr[i] << " ";
        cout << endl;

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                int minV = i + 1;
                FOR(j, i + 1, n) {
                    if (arr[minV] > arr[j] && arr[j] > arr[i]) minV = j;
                }
                swap(arr[i], arr[minV]);
                sort(arr + i + 1, arr + n);
                break;
            }
        }

        bool flag = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                flag = 0; break;
            }
        }
        if (flag) {
            if (n == 1) break;
            FOR(i, 0, n) cout << arr[i] << " ";
            cout << endl;
            break;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
