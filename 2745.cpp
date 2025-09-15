#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    cin >> num;
    
    int n;
    cin >> n;

    long long sum = 0;

    for (int i = 0; i < num.size(); ++i) {
        // 알파벳인 경우
        if (num[i] >= 'A' && num[i] <= 'Z') {
            sum += (num[i] - 'A' + 10) * pow(n, num.size() - 1 - i);
        }
        
        else {
            sum += (num[i] - '0') * pow(n, num.size() - 1 - i);
        }
    }

    cout << sum << '\n';
    
    return 0;
}