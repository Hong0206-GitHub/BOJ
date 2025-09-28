#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 값 입력 받기
    int N;
    cin >> N;

    // 배열 채우기
    int arr[6];
    for (int i = 0; i < 6; ++i) cin >> arr[i];

    // 값 입력받기
    int T, P;
    cin >> T >> P;

    int sum = 0;

    // 답안 출력
    // 첫 번째 줄 출력 답안
    for (int i = 0; i < 6; ++i) {
        if (arr[i] % T == 0) sum += arr[i] / T;
        else sum += arr[i] / T + 1;
    }
    
    cout << sum << '\n';

    // 두 번째 줄 출력 답안
    cout << (N / P) << ' ' << (N % P) << '\n';


    return 0;
}