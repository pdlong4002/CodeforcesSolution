#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
//#define int long long
#define fi first
#define se second
#define el cout << "\n"
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define DEBUG
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
    #define dbg(x)
#endif

int dp[2004][2004];
void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int>a(n);
    mem(dp, -1);

    for(auto &x : a)
        cin >> x;

    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int t = 0; t < h; t++) {
            if(dp[i][t] == -1) continue;
            int nt = 0, c = 0;
            // a[i]
            nt = (t + a[i]) % h;
            c = (nt >= l and nt <= r);
            dp[i + 1][nt] = max(dp[i + 1][nt], dp[i][t] + c);

            // a[i] - 1
            nt = (t + a[i] - 1) % h;
            c = (nt >= l and nt <= r);
            dp[i + 1][nt] = max(dp[i + 1][nt], dp[i][t] + c);
        }
    }

    int ans = 0;
    for(int t = 0; t < h; t++)
        ans = max(ans, dp[n][t]);

    cout << ans << endl;
}
// dp[i][t] : so lan tot nhat sau i lan, voi tg hien tai la t

int32_t main() {
    faster();
    clock_t start = clock();

    int tc = 1;
    //cin >> tc;

    while (tc--)
        solve();

    cerr << '\n';
    cerr << "Time elapsed: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}