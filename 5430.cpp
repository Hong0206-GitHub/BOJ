#include <iostream>
#include <deque>
// 입력 배열 손질을 위해 사용
#include <sstream>
using namespace std;

// 반전출력 함수
void print_reversed(deque<int> myDeque);

// 정상출력 함수
void print_deque(deque<int> myDeque);


int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // test-case 입력 받기
    int t;
    cin >> t;

    // 총 test-case 번 반복
    for (int test = 0; test < t; ++test) {
        
        // 적용할 함수 명령어 묶음 입력받기
        string command;
        cin >> command;

        // 배열에 들어있는 정수 n 입력받기
        int n;
        cin >> n;

        // 배열 입력 받기
        string arr_string;
        cin >> arr_string;
        
        // D 명령어가 배열의 개수 보다 크면
        // error를 출력해야함
        int d = 0;
        for (size_t i = 0; i < command.size(); ++i) {
            
            if (command[i] == 'D') {
                d++;
            }
            // 분석 중 d가 n보다 커지면 더 이상 d의 개수를 셀 필요가 없음
            if (d > n) {
                break;
            }
        }
        // d가 n보다 크면 error 출력 후 다음으로 넘어감
        if (d > n) {
            cout << "error" << '\n';
            continue;
        }

        // 입력받은 배열의 앞 뒤 대괄호 제거
        arr_string = arr_string.substr(1, arr_string.size() - 2);

        // Deque 선언
        deque<int> myDeque;

        // ,로 구분해서 int형 변환 후 덱에 순서대로 삽입
        stringstream ss(arr_string);
        string num;
        while (getline(ss, num, ',')) 
            myDeque.push_back(stoi(num));
 
        // reverse 여부 판단
        bool reverse = false;
        // 모든 함수 실행
        for (size_t i = 0; i < command.size(); ++i) {
            // command가 R인 경우 reverse 반전
            if (command[i] == 'R') {
                reverse = !reverse;
            }
            // D인 경우
            else {
                // 반전해야한다면, 뒤의 원소를 뽑아야함
                if (reverse) myDeque.pop_back();
                // 반전하지 않는다면, 앞의 원소를 뽑아야함
                else myDeque.pop_front();
            } 
        }

        // 반전해야하면 반전 출력 함수 호출
        if (reverse) print_reversed(myDeque);
        // 그렇지 않다면 일반 출력 함수 호출
        else print_deque(myDeque);
    }

    return 0;
}

// 반전출력 함수
void print_reversed(deque<int> myDeque) {

    // 덱이 비어있는 경우
    if (myDeque.empty()) {
        cout << "[]" << '\n';
        return;
    }

    int size = myDeque.size();

    cout << '[';

    for (int i = 0; i < size - 1; ++i) {
        cout << myDeque.back() << ',';
        myDeque.pop_back();
    }
    cout << myDeque.back();
    myDeque.pop_back();
    
    cout << ']' << '\n';
}

// 정상출력 함수
void print_deque(deque<int> myDeque) {
    
    
    // 덱이 비어있는 경우
    if (myDeque.empty()) {
        cout << "[]" << '\n';
        return;
    }

    int size = myDeque.size();

    cout << '[';

    for (int i = 0; i < size - 1; ++i) {
        cout << myDeque.front() << ',';
        myDeque.pop_front();
    }
    cout << myDeque.front();
    myDeque.pop_front();
    
    cout << ']' << '\n';
}