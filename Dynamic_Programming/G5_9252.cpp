#include <bits/stdc++.h>

using namespace std;

void LCS(vector<vector<int>> &table, string &x, string &y) {

    // DP 방식으로 구현
    for (int i = 1; i <= x.length(); i++) {
        for (int j = 1; j <= y.length(); j++) {
            // 문자가 서로 같은 경우, 이전 테이블 값에서 1증가
            if (x[i - 1] == y[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
            // 다른 경우, 두 길이의 한 칸 전 길이 중 최댓값으로 계산
            else table[i][j] = max(table[i][j - 1], table[i - 1][j]);
        }
    }
}

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 비교 문자열 입력 받기
    string x, y;
    cin >> x >> y;

    // look-up 테이블 선언
    vector<vector<int>> table(x.length() + 1, vector<int>(y.length() + 1));
    LCS(table, x, y);   // 함수 호출

    // 마지막 값이 LCS임
    cout << table[x.length()][y.length()] << '\n'; 

    return 0;
}