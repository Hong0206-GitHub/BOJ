// 임시 풀이
// 이진 탐색으로 중복 원소 시작 인덱스와
// 종료 인덱스를 알 수 있는 알고리즘 학습 예정.

#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 동적 배열 할당 입력은 -10,000,000 ~ 10,000,000 이므로
    // 20,000,001 만큼 할당
    int *arr = new int[20000001];
    for (int i = 0; i < 20000001; ++i) arr[i] = 0; // 배열의 모든 원소 0으로 초기화

    // 입력된 수가 음수일 경우가 있으므로,
    // 10,000,000을 더해서 음수 인덱스 배제
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        arr[temp + 10000000] ++; // 입력된 위치 1 증가
    }

    // 테스트 케이스 입력 받기
    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int temp;   // 출력해야할 중복 원소
        cin >> temp;
        cout << arr[temp + 10000000] << ' '; // 배열에 집어 넣을 때 10,000,000을 더해서 집어넣었으므로 접근도 더해서 함
    }

    cout << '\n';

    // 동적 할당 해제
    delete[] arr;

    return 0;
}