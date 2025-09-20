#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long answer = 0;

    // n, m 입력받기
    int n, m;
    cin >> n >> m;

    // 합 배열 동적할당
    long *prefix_sum_arr = new long[n];

    // 나머지가 같은 원소 개수 배열 동적할당
    long *same_mod_arr = new long[m]{0};
    
    // 두 번 째 줄 입력 받아 배열에 넣기
    cin >> prefix_sum_arr[0];
    for (int i = 1; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        prefix_sum_arr[i] = prefix_sum_arr[i - 1] + tmp;
    }

    for (int i = 0; i < n; i++) {
        int tmp = prefix_sum_arr[i] % m;

        if (tmp == 0) answer++;
        same_mod_arr[tmp]++;
    }

    for (int i = 0; i < m; i++) {
        if (same_mod_arr[i] > 1) answer = answer + (same_mod_arr[i] * (same_mod_arr[i] - 1) / 2);
    }

    cout << answer << '\n';

    // 동적할당 해제
    delete[] prefix_sum_arr;
    delete[] same_mod_arr;

    return 0;
}