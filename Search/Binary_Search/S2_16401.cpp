#include <iostream>

using namespace std;

// 최대 과자 길이 구하는 함수 선언
int search(int *arr, int start, int end, int N, int M);
long long check(int *arr, int mid, int N, int M);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 조카 수 배열 길이 입력 받기
    int M, N;
    cin >> M >> N;

    // 과자길이 집어넣을 배열 선언
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // 최대값 찾기
    int max = -1;
    for (int i = 0; i < N; ++i) {
        if (max < arr[i]) max = arr[i];
    }

    // 답안 출력
    cout << (search(arr, 1, max, N, M)) << '\n';

    delete[] arr;

    return 0;
}

// 최대 과자 길이 구하기
int search(int *arr, int start, int end, int N, int M) {
    int answer;
    while (start <= end) {
        int mid = (start + end) / 2;
        long long temp = check(arr, mid, N, M);

        // 총합이 사촌 동생 수 이상이면, start 포인터를 오른쪽으로
        // 한칸 이동 시켜 최대값 탐색
        if (temp >= M) {
            answer = mid;
            start = mid + 1;
        } else end = mid - 1;
    }

    return answer;
}

// 과자길이 / 길이의 총합 반환 함수
long long check(int *arr, int mid, int N, int M) {
    // cnt는 조건 비교시 사용할 변수
    long long cnt = 0;
    // 과자길이 / 길이의 총합 반환
    for(int i = 0; i < N; ++i) {
        cnt += arr[i] / mid;
        if (cnt >= M) return cnt;
    }
    return cnt;
}