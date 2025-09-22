#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

    // // 속도 증가
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    // M, N 입력 받기
    int M, N;
    cin >> M >> N;

    // 초기 배열 초기화
    int *arr = new int[N + 1];
    for (int i = 2; i <= N; ++i) arr[i] = i;

    // 에라토스테네스의 체 사용
    for (int i = 2; i <= sqrt(N); ++i) {
        if (arr[i] == 0) continue;
        for (int j = i * i; j <= N; j += i) arr[j] = 0;
    }
    
    // 답안 출력
    for (int i = M; i <= N; ++i)
        if (arr[i] != 0) cout << arr[i] << '\n';

    // 동적 할당 해제
    delete[] arr;

    return 0;
}