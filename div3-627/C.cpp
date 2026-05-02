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

void solve() {
    //int n; cin >> n;
    string a; cin >> a;

    int r = 0, ans = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == 'R') {
            ans = max(ans, i + 1 - r);
            r = i + 1;
        }
    }

    ans = max(ans, (int)a.size() + 1 - r);
    cout << ans << endl;
}
// RR => RR
// RLRLLR => 3
int32_t main() {
    faster();
    clock_t start = clock();

    int tc = 1;
    cin >> tc;

    while (tc--)
        solve();

    cerr << '\n';
    cerr << "Time elapsed: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}