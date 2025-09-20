#include <iostream>
#include <climits>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n, k 입력
    int n, k;
    cin >> n >> k;

    // 동적 배열 할당
    int *arr = new int[n];

    // 원소 입력 받기
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    int size = n - (k - 1);
    int *sum = new int[size]{0};

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < k + i; ++j) {
            sum[i] += arr[j];
        }
    }

    // 최대값 탐색
    int max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (max < sum[i]) {
            max = sum[i];
        }
    }

    // 결과 출력
    cout << max << '\n';

    // 동적 배열 할당 해제
    delete [] arr;
    delete [] sum;

    return 0;
}