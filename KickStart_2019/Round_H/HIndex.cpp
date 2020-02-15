
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<int, int>,
    null_type,
    greater<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        cout << "Case #" << t << ":";

        int curScore = 0;
        ordered_set papers;
        for (int i = 0; i < N; ++i) {
            int A; cin >> A;
            papers.insert({A, i});
            if (papers.order_of_key({curScore, N}) > curScore)
                ++curScore;
            cout << ' ' << curScore;
        }
        cout << endl;
    }
    return 0;
}
