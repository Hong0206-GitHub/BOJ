#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 2차원 벡터 선언
    // 문제에서 범위를 30 미만으로 표기 함
    vector<vector<int>> D(30, vector<int>(30));

    // 아무것도 선택하지 않는 경우와, 모든 것을 선택할 경우의 수는 1임
    for (int i = 0; i < 30; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
    }

    // 조합의 경우의 수
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }

    // 테스트 케이스 횟수 입력 받기
    int T;
    cin >> T;
    
    // 두 값 변수 선언
    int N, M;

    // 테스트 케이스만큼 반복
    while (T--) {
        // 입력 받고
        cin >> N >> M;

        // 문제에서 M개의 사이트 중 N개를 선택한다고 함
        cout << D[M][N] << '\n';
    }
    
    return 0;
}