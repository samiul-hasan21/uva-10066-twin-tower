#include<bits/stdc++.h>
using namespace std;

int lcs(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main() {
    int caseNum = 0;
    while (true) {
        int N1, N2;
        cin >> N1 >> N2;
        if (N1 == 0 && N2 == 0)
            break;
        caseNum++;
        vector<int> tower1(N1);
        for (int i = 0; i < N1; ++i) {
            cin >> tower1[i];
        }
        vector<int> tower2(N2);
        for (int i = 0; i < N2; ++i) {
            cin >> tower2[i];
        }
        int maxLength = lcs(tower1, tower2);
        cout << "Twin Towers #" << caseNum << endl;
        cout << "Number of Tiles : " << maxLength << endl;
        cout << endl;
    }

    return 0;
}


