#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            cnt = 0;
            continue;
        }
        cnt & 1 ? s[i] = tolower(s[i]) : s[i] = toupper(s[i]);
        cnt++;
    }

    return s;
}