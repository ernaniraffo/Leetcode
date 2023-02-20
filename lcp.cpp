#include <iostream>
#include <vector>

using namespace std;

string lcp(vector<string>& strs) {
    string prefix = strs[0];
    
    for (int i = 1; i < strs.size(); i++) {
        for (int j = 0; j < prefix.length(); j++) {
            if (j >= prefix.length()) {
                prefix.erase(j, prefix.length() - j);
                break;
            }
        }
    }

    return prefix;

}

int main(void) {
    vector<string> strs = { "flower", "flow" };
    std::cout << lcp(strs) << std::endl;
}
