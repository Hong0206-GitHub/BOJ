#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 해시 자료구조 사용
    unordered_set<string> hash;

    // 입력 문자열 개수들 입력 받기
    int N, M;
    cin >> N >> M;

    // 문자열 삽입
    while (N--) {
        string s;
        cin >> s;

        hash.insert(s);
    }
    
    // 답안 저장 변수
    int answer = 0;

    // 문자열 탐색
    while (M--) {
        string s;
        cin >> s;
        // 1개 이상이면 존재하는 것이고 0이 아니기 때문에 참이 되므로 answer++이 됨
        if (hash.count(s)) answer++;
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}