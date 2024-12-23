#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int g = 1;

        int N;
        cin >> N;
        vector<int> A(N);

        for (int j = 0; j < N; j++) {
            cin >> A[j];
        }
        for (int j = 0; j < N - 1; j++) {
            if (A[j] > A[j + 1]) {
                g = 0;
                break;
            }
        }
        if (g == 1) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
    }

    return 0;
}