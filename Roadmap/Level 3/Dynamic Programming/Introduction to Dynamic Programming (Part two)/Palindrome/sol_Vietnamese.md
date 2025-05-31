# Ý tưởng
- Việc tìm Palindrome, tức là ta đi so sánh hai bên trái phải của chuỗi xem chúng có bằng nhau hay không.
- Vì đề bài yêu cầu cần phải thêm ít nhất bao nhiêu ký tự để chuỗi trở thành palindrome, vậy rõ ràng ta phải tìm được chuỗi palindrome dài nhất có thể có trong S (các ký tự không nhất thiết liền kề nhau).
- Mà một chuỗi palindrome dài nhất sẽ có hai phần trái và phải giống nhau và dài nhất nên bài toán này rõ ràng có thể quy về bài toán tìm chuỗi con không liên tục chung dài nhất. Bài toán **Longest common subsequence** có thể tìm thấy ở đường dẫn https://marisaoj.com/problem/144
- Vậy ta đi xét từng cặp chuỗi (với $n$ là độ dài chuỗi input)
    - $S[1 \rightarrow t]$ và $S[(t + 1) \rightarrow n]$ $\forall t \in [1, n - 1] $ gọi là **cặp chuỗi chẵn** (nối hai chuỗi lại ta được chuỗi $S$ ban đầu). Có tất cả $n - 1$ cặp.
    - $S[1 \rightarrow t]$ và $S[(t + 2) \rightarrow n]$ $\forall t \in [1, n - 2] $ với gốc đối xứng $S[t + 1]$ gọi là **cặp chuỗi lẻ** (nối chuỗi 1 với ký tự gốc với chuỗi 2 sẽ ra được chuỗi ban đầu). Có tất cả $n - 2$ cặp.
    - Chuỗi thứ 2 của các cặp chuỗi chẵn lẻ phải được nghịch đảo để thuận tiện cho việc so sánh. Ví dụ chuỗi $S$ là $abcdef$ thì một cặp chuỗi chẵn cần xét là $abc$ và $fed$ và một cặp chuỗi lẻ cần xét là $ab$ và $fed$ với $c$ là gốc đối xứng.
- Ta sẽ duyệt hết các cặp chuỗi lẻ rồi đến hết các cặp chuỗi chẵn. Thuật toán để tìm chuỗi con chung dài nhất giữa hai chuỗi $a$ và $b$ mà tác giả tìm được có độ phức tạp là $O(mn)$ với $m$ là độ dài của $a$ và $n$ là độ dài của $b$. Nếu như duyệt lần lượt như vậy độ phức tạp thời gian tổng thể sẽ là:
$$ \sum_{x = 1}^{n - 1} x.(n-x) + \sum_{x = 1}^{n-2}x.(n-x)$$
- Với $n$ lên tới 1000 thì tổng trên khá lớn (lớn hơn $3e8$). 
- Thuật toán hiện tại vẫn có thể giảm đi một nửa thời gian. Thay vì duyệt hết cặp chuỗi chẵn rồi đến cặp chuỗi lẻ, ta có thể duyệt 1 lần cho cặp chuỗi chẵn nhưng cũng cùng lúc duyệt cặp chuỗi lẻ.
- Xét ví dụ với input $S$ là $abcdefg$, muốn tìm chuỗi chung giữa $a$ và $gfedcb$ (cặp chẵn) thì ta phải duyệt lần lượt ký tự của $a$ với $gfedcb$ hay nói cách khác ta phải so sánh $a$ với các ký tự của chuỗi $gfedc$ trước ký tự $b$. Mà rõ ràng nếu so sánh $a$ với $gfedc$ chính là so sánh cặp chuỗi lẻ với định nghĩa cặp chuỗi lẻ như trên. Vậy với mỗi cặp chuỗi chẵn, ta luôn có thể duyệt như 1 cặp chuỗi lẻ ngoại trừ cặp chuỗi chẵn cuối cùng so sánh $S[1 \rightarrow (n - 1)]$ với $S[n + 1]$.

# Code AC
Đoạn code tham khảo
<details>
<summary>VIEW CODE</summary>

```cpp
// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;
    vector<int> dp(S.size(), 0);
    int ans = S.size();
    int n = S.size();

    string fo="";
    string ba=S;
    reverse(all(ba));
    for (int i = 0; i < S.size(); i++){
        for (int j = 0; j < fo.size(); j++) {
            int val = 0;
            for (int k = 0; k < ba.size(); k++) {
                if (ba[k] == fo[j]) {
                    if (val + 1 > dp[k]) {
                        dp[k] = val + 1;
                    } else val = dp[k];
                } else val = max(dp[k], val);
            }
            for (int k = 0; k < ba.size(); k++) {
                if (k == ba.size() - 1) ans = min(ans, n - 2 * dp[k]);
                else if (k == ba.size() - 2) ans = min(ans, n - 2 * dp[k] - 1);
            }
        }
        std::fill(all(dp), 0);
        ba.pop_back();
        fo.push_back(S[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

</details>

# Ý tưởng cải tiến thuật toán
- Tác giả sử dụng mảng $dp$ để lưu độ dài dài nhất của chuỗi con chung kết thúc tại mỗi vị trí tương ứng trong mảng. Mảng $dp$ này sẽ theo dõi và cập nhật cho chuỗi sau của từng cặp chuỗi chẵn hoặc lẻ.
- Rõ ràng thuật toán trên vẫn còn quá chậm khi độ phức tạp thời gian vẫn lớn hơn $1e8$.
- Ta nhận xét, vì mỗi lần so sánh các cặp chuỗi, thì cặp chuỗi sau chỉ khác cặp chuỗi trước ở chỗ là có 1 ký tự từ chuỗi sau được chuyển sang cho chuỗi trước. Ví dụ chuỗi input là $abcdefgh$, cặp chuỗi trước gồm $abcd$ với $hgfe$ và cặp chuỗi sau đó gồm $abcde$ với $hgf$. 
- Có thể thấy chuỗi đầu của cặp chuỗi trước và sau đều có phần tiền tố $abcd$ giống nhau, tương tự chuỗi cuối của cặp chuỗi đầu và chuỗi sau đều có $hgf$ giống nhau. Vì từ $hgfe$ giảm về $hgf$ tức là giảm chiều dài của mảng $dp$ hay bỏ đi phần tử cuối cùng và trong khi đó các giá trị còn lại đều có thể giữ nguyên. Vậy mảng $dp$ có thể dùng để cập nhật bằng cách cuốn chiếu ngược mà không cần phải xoá đi và xét duyệt lại từ đầu cho mỗi cặp.

# Code cải tiến

Đoạn code tham khảo
<details>
<summary>VIEW CODE</summary>

```cpp
// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;
    vector<int> dp(S.size(), 0);
    int ans = S.size();
    int n = S.size();

    string fo=S.substr(0,1);
    string ba=S.substr(1);
    reverse(all(ba));
    for (int i = 1; i < S.size(); i++){
        if ((n - ans) / 2 > ba.size() || (n - ans) / 2 > fo.size()) break;
        int val = 0;
        int addr =- 1 ;
        for (int k = 0; k < ba.size(); k++) {
            if (ba[k] == fo[i - 1] && val + 1 > dp[k]) {
                dp[k] = val + 1;
                continue;
            } 
            if (val <= dp[k]) val = dp[k];
        }
        for (int k = 0; k < ba.size(); k++) {
            if (k == ba.size() - 1) ans = min(ans, n - 2 * dp[k]);
            else if (k == ba.size() - 2) ans = min(ans, n - 2 * dp[k] - 1);
        }
        ba.pop_back();
        fo.push_back(S[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

</details>
