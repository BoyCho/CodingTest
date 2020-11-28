#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    (s.size() == 4 || s.size() == 6) ? answer = true : answer = false;
    if (answer) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '0' || '9' < s[i]) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}
/*
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }
*/