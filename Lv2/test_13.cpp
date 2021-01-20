#include <string>
#include <vector>

using namespace std;

bool balance(string s) {
    int r = 0, l = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') r++;
        if (s[i] == ')') l++;
    }
    return r == l ? true : false;
}
bool correct(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cnt++;
        if (s[i] == ')') cnt--;

        if (cnt < 0) return false;
    }
    return true;
}
string u_sort(string s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = s[i] == ')' ? '(' :')';
    return s.substr(1, s.size() - 2);
}
string solution(string s) {
    if (s == "") return s;

    for (int i = 2; i <= s.size(); i++) {
        if (balance(s.substr(0, i))) {
            if (correct(s.substr(0, i)))
                return s.substr(0, i) + solution(s.substr(i));
            else
                return "(" + solution(s.substr(i)) + ")" + u_sort(s.substr(0, i));
        }
    }
    return s;
}