#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 테스트 케이스 입력 받기
    int T;
    cin >> T;

    // 2차원 벡터 선언
    vector<vector<int>> D(15, vector<int>(15, 0));

    // 0층의 i호는 i명 만큼만 산다. --> 는 즉,
    // i층의 1호는 1명만 산다.
    for (int i = 0; i <= 14; i++) {
        D[0][i] = i;
        D[i][1] = 1;
    }

    // 점화식 세우기
    for (int i = 1; i <= 14; i++) {
        for (int j = 2; j <= 14; j++) {
            D[i][j] = D[i - 1][j] + D[i][j - 1];
        }
    }

    // 테스트 케이스만큼
    // 2개의 값 입력 받아서 몇 명 사는지 출력
    while (T--) {
        int a, b;
        cin >> a >> b;

        cout << D[a][b] << '\n';
    }
    return 0;
}