#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
    int sum = 0;
    map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
    };

    for (auto it = s.begin(); it != s.end(); it++) {
        if (values[*(it + 1)] > values[*it]) {
            sum += values[*(it + 1)] - values[*it];
            it++;
        } else {
            sum += values[*it];
        }
    }

    return sum;
}

int main(void) {
    string s;
    std::cout << "Input a roman numeral: ";
    cin >> s;
    int r = romanToInt(s);
    std::cout << "Value: " << r << std::endl;
    return EXIT_SUCCESS;
}