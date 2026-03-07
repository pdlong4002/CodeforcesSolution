#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
#define int long long
#define fi first
#define se second
#define el cout << "\n"
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

#define DEBUG
#ifdef DEBUG
    #define dbg(x) cerr << #x << " = " << (x) << "\n"
#else
    #define dbg(x)
#endif

// ------- dashboard -------
//  cd SOLUTION 
//  build : build
//  run : run
//  test : run && input + output
// -------

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int>a(n);
    for(int &x : a)
        cin >> x;
    
    vector<int> L(a.begin(), a.begin() + x);
    vector<int> M(a.begin() + x, a.begin() + y);
    vector<int> R(a.begin() + y, a.end()); 

    // l + r
    vector<int>LR = L;
    LR.insert(LR.end(), all(R));

    // min value in M
    auto it = min_element(all(M));

    // copy it -> end
    // insert M.begin() to it
    // and rotate
    vector<int> MD(it, M.end());
    MD.insert(MD.end(), M.begin(), it);

    // find first pos largest *it, to insert 
    int pos = LR.size();
    for(int i = 0; i < LR.size(); i++) {
        if(LR[i] > *it) {
            pos = i;
            break;
        }
    }

    LR.insert(LR.begin() + pos, all(MD));
    for(int &x : LR)
        cout << x << ' ';
    el;
}
// 1 2 3
// 1 O 3 5 O 2 4
// 1 2 O 3 5 O 4
// 1 2 O 3 4 5 6 7 O
// 7 6 O 5 4 3 O 2 1

int32_t main()
{
    faster();
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}