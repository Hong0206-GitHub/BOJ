#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    int temp;
        
    for (int i = 0; i < 5; ++i) {
        cin >> temp;
        sum += temp;
    }   
    cout << sum << '\n';
    return 0;
}