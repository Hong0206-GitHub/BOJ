#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 문자열 길이 입력
    int N;
    cin >> N;
    
    // 문자열 입력
    string str;
    cin >> str;

    // 모음 개수 누적할 변수 선언
    int cnt = 0;

    // 전체 문자열 순회하면서 모음인 경우
    // cnt 1 증가
    for (size_t i = 0; i < str.size(); ++i) {
        switch (str[i])
        {
        case 'a':
            cnt++;
            break;
        case 'e':
            cnt++;
            break;
        case 'i':
            cnt++;
            break;
        case 'o':
            cnt++;
            break;
        case 'u':
            cnt++;
            break;
        default:
            continue;
        }
    }

    // 답안 출력
    cout << cnt << '\n';

    return 0;
}