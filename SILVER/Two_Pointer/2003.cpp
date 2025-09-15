#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 수열 개수 입력
    int n;
    cin >> n;

    // 합 m
    int m;
    cin >> m;

    // 수열 내용 배열에 입력
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 경우의 수
    int count = 0;
    // 시작 인덱스, 종료 인덱스 선언
    int start = 0, end = 0;
    // 구간 합 저장할 변수
    int sum = arr[end];

    while (end < n) {
        // 구간 합이 m과 같아진 경우
        // count 증가, start 오른쪽으로 한 칸 이동
        // sum 갱신
        if (sum == m) {
            count++;
            sum += arr[++end];
        }

        // 구간 합이 m보다 큰 경우
        // 범위를 줄여야 하므로, start 인덱스 오른쪽으로 한 칸 이동
        // sum 갱신
        else if (sum > m) {
            sum -= arr[start++];
        }

        // 구간 합이 m보다 작은 경우
        // 범위를 늘려야하므로, end 인덱스 오른쪽으로 한 칸 이동
        // sum 갱신
        else {
            sum += arr[++end];
        }
    }

    // 결과 출력
    cout << count << '\n';

    // 동적 할당 해제
    delete[] arr;

    return 0;
}
