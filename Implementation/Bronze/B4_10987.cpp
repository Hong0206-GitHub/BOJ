#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 문자열 입력 받기
    string str;
    cin >> str;

    // 모음 카운터 셀 변수 선언 및 초기화
    int answer = 0;

    // 문자열의 길이만큼 한 문자씩 검사하여
    // 모음일 경우 답안 증가
    for (size_t i = 0; i < str.length(); i++) 
        if (str[i] == 'a'  || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') answer++;

    // 답안 출력
    cout << answer << '\n';

    return 0;
}