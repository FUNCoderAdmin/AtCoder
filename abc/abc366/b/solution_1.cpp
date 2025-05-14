#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    int M = 0;
    for (int i = 0; i < N; i++){
        cin >> S[i];
        M = max<int>(M, S[i].size());
    }
    
    vector<string> T(M, string(N, '*'));
    for (int i = 0; i < N; i++) {
        int L = S[i].size();
        for (int j = 0; j < L; j++) {
            T[j][N - i - 1] = S[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        while (T[i].back() == '*')
            T[i].pop_back();
    }
    for (int i = 0; i < M; i++) {
        cout << T[i] << "\n";
    }
}