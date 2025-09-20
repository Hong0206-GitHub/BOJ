#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 배열 선언
    int arr[10];
    int sum[10];

    // 첫 원소 배열에 넣기
    cin >> arr[0];
    sum[0] = arr[0];

    // 두 번째 원소부터 합 배열까지 생성
    for (int i = 1; i < 10; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    // 100이거나 100을 넘어가는 idx 찾기
    int idx;
    for (int i = 0; i < 10; i++) {
        if (sum[i] >= 100) {
            idx = i;
            break;
        }
    }

    // 조건에 맞게 갱신
    if ((sum[idx] - 100) > (sum[idx - 1] - 100) * -1) idx--;

    cout << sum[idx] << '\n';

    return 0;
}