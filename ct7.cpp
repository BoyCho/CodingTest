#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    int cnt = b;

    switch (a - 1) {
    case 12:
        cnt += 31;
    case 11:
        cnt += 30;
    case 10:
        cnt += 31;
    case 9:
        cnt += 30;
    case 8:
        cnt += 31;
    case 7:
        cnt += 31;
    case 6:
        cnt += 30;
    case 5:
        cnt += 31;
    case 4:
        cnt += 30;
    case 3:
        cnt += 31;
    case 2:
        cnt += 29;
    case 1:
        cnt += 31;
    }

    switch ((cnt-1)%7) {
    case 0:
        answer = "FRI";
        break;
    case 1:
        answer = "SAT";
        break;
    case 2:
        answer = "SUN";
        break;
    case 3:
        answer = "MON";
        break;
    case 4:
        answer = "TUE";
        break;
    case 5:
        answer = "WED";
        break;
    case 6:
        answer = "THU";
        break;
    }
    return answer;
}