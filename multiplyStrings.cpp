#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {

    int m = num1.size();
    int n = num2.size();

    vector<int> p (m+n);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < m; i += 1) {
        int carry = 0;
        int d1 = num1[i] - '0';
        for (int j = 0; j < n; j += 1) {
            int d2 = num2[j] - '0';
            int result = p[i + j] + d1 * d2 + carry;
            carry = result / 10;
            p[i + j] = result % 10;
        }
        p[i + n] = carry;
    }

    while (p.size() > 1 and p.back() == 0) {
        p.pop_back();
    }

    string answer = "";
    for (auto it = p.rbegin(); it != p.rend(); it += 1) {
        answer += to_string(*it);
    }

    return answer;
}


int main(int argc, char** argv) {
    string num1, num2;

    std::cout << "Enter num1: ";
    cin >> num1;
    std::cout << "Enter num2: ";
    cin >> num2;

    std::cout << multiply(num1, num2) << std::endl;
    return 0;
}