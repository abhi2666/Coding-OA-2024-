#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        string S;
        cin >> S;

        int countOnes = count(S.begin(), S.end(), '1');

        if (countOnes <= K) {
            for (int i = 0; i < N - K; ++i) {
                cout << "0";
            }
            cout << "\n";
        } else {
            int flipped = 0;
            for (int i = 0; i < N; ++i) {
                if (S[i] == '1' && flipped < K) {
                    S[i] = '0';
                    flipped++;
                }
            }
            cout << S << "\n";
        }
    }

    return 0;
}