#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 반복 횟수 N 입력받기
    int N;
    cin >> N;

    // queue 선언
    queue<int> q;

    // N번 반복
    while (N--) {
        // 명령어 입력 받기
        string command;
        cin >> command;
        
        // 각 명령어 별로 구분하여 작업 수행
        if (command == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (command == "front") cout << (q.empty() ? -1 : q.front()) << '\n';
        else if (command == "size") cout << q.size() << '\n';
        else if (command == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            } else cout << -1 << '\n';
        }
        else if (command == "back") cout << (q.empty() ? -1 : q.back()) << '\n';
        else if (command == "empty") cout << (q.empty() ? 1 : 0) << '\n';
        else cout << "command 비교 오류" << endl;
    }

    return 0;
}