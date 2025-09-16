#include <iostream>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 전체 반복 횟수 입력 받기
    int N;
    cin >> N;

    // 스택 선언
    stack<int> stk;

    // N만큼 전체 반복
    while (--N >= 0) {
        // 명령 입력 받기
        int m;
        cin >> m;

        // 각 명령에 맞게 스택 조작
        switch (m) {
            case 1:
                int x;
                cin >> x;
                stk.push(x);
                break;
            case 2:
                if (stk.empty()) cout << -1 << '\n';
                else {
                    cout << stk.top() << '\n';
                    stk.pop();
                }
                break;
            case 3:
                cout << stk.size() << '\n';
                break;
            case 4:
                if (stk.empty()) cout << 1 << '\n';
                else cout << 0 << '\n';
                break;
            case 5:
                if (stk.empty()) cout << -1 << '\n';
                else cout << stk.top() << '\n';
                break;
        }
    }


    return 0;
}
