#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int n;
    cin >> n;

    // 원소 입력 배열과 누적 합 배열 동적 할당
    int *arr = new int[n]{0};
    int *sum = new int[n + 1]{0};
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];
    }

    // 테스트 케이스만큼 반복
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        // 구간 합 공식 i ~ j -> sum[j] - sum[i - 1]
        cout << sum[y] - sum[x - 1] << '\n';
    }

    // 동적 할당 해제
    delete[] arr;
    delete[] sum;

    return 0;
}
