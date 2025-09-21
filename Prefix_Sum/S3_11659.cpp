#include <iostream>
using namespace std;

int main() {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // n 과 m 입력 받기
    int n = 0, m = 0;
    cin >> n >> m;

    // 합 배열 동적 할당 및 0으로 초기화
    long long *prefix_sum_arr = new long long[n + 1]{};
    
    // 합 배열 공식 S[i] = S[i - 1] + A[i]
    long long tmp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        prefix_sum_arr[i] = prefix_sum_arr[i - 1] + tmp; 
    }

    // 총 m번,
    // 구간 i j 값 입력받고
    // i ~ j 구간의 합 출력.
    // 합 배열에서 구간 합 공식 S[j] - S[i - 1]
    for (int k = 0; k < m; k++) {
        int i = 0, j = 0;
        cin >> i >> j;
        // 조건에 따르면 index 범위 벗어날 일 없음
        cout << prefix_sum_arr[j] - prefix_sum_arr[i - 1] << "\n";
    }

    // 동적 해제 꼭 하기!
    delete [] prefix_sum_arr;
    return 0;
}