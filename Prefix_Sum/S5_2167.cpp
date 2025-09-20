#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n, m 입력 받기
    int n, m;
    cin >> n >> m;

    // 합 배열 동적할당
    int **sum = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        sum[i] = new int [m + 1]{0};
    }

    // 입력 받음과 동시에 합 배열 생성
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int temp;
            cin >> temp;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + temp;
        }
    }

    // k입력 받기
    int k;
    cin >> k;

    // k번 반복
    while (k--) {
        long long answer;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
    
        // 2차원 구간 합 공식
        answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    
        // 답안 출력
        cout << answer << '\n';
    }

    // 동적 배열 해제
    for (int i = 0; i <= n; i++) {
        delete [] sum[i];
    } delete [] sum;
    
    return 0;
}