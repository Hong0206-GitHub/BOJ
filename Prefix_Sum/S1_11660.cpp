#include <iostream>

using namespace std;

int main() {

    // 속도증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 2차원 배열 크기와, 연산 횟수 입력 받기
    int n, m;
    cin >> n >> m;
    
    // 2차원 배열 동적할당 (합 배열)
    int **prefix_sum_arr = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        prefix_sum_arr[i] = new int[n + 1]{0};
    }

    // 입력 받아서 원본 배열 합 배열 각각 집어넣기
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= n; j++) {
            int temp;
            cin >> temp;
            // 합 배열
            prefix_sum_arr[i][j] = prefix_sum_arr[i - 1][j] + prefix_sum_arr[i][j - 1] - prefix_sum_arr[i - 1][j - 1] + temp;
       }
    // 문제 조건에 맞는 답안 출력
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = prefix_sum_arr[x2][y2] - prefix_sum_arr[x1 - 1][y2] - prefix_sum_arr[x2][y1 - 1] + prefix_sum_arr[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    // 동적할당 해제  
    for (int i = 0; i <= n; i++) delete[] prefix_sum_arr[i];
    delete[] prefix_sum_arr;

    return 0;

}
