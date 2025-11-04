#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 탐지 문자열 배열
    char ch[4] = {'D', 'K', 'S', 'H'};

    // 탐색할 문자열
    string str;
    cin >> str;

    // 답안 저장용 변수
    int answer = 0;

    // 문자열이 적은 경우
    if (str.length() < 4) {
        cout << 0 << '\n';
        return 0;
    }

    // 전체 문자열 순회하면서
    for (size_t i = 0; i <= str.length() - 4; i++) {
        bool check = true;

        // 시작이 D인 경우만 탐색
        if (str[i] == 'D') {
            // 4개의 문자열 순서가 동일한지 확인
            for (int j = 0; j < 4; j++) {

                if (i + j >= str.length()) {
                    check = false;
                    break;
                }

                if (ch[j] != str[i + j]) {
                    check = false;
                    break;
                }
            }
            // 동일하면 답안 증가
            if (check) answer++;
        }
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}