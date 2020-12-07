#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    if (n > 3) {
        n--;
        while (n >= 0) {
            switch (n % 3) {
            case 0:
                answer = '1' + answer;
                break;
            case 1:
                answer = '2' + answer;
                break;
            case 2:
                answer = '4' + answer;
                break;
            }
            n /= 3;
            n--;
        }
    }
    else
        switch (n) {
        case 1:
            return "1";
        case 2:
            return "2";
        case 3:
            return "4";
        }
    return answer;
}