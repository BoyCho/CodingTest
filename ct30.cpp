#include <string>
#include <vector>

using namespace std;
class num {
public:
    num() {
        x = 0;
        y = 0;
    }
    num(int x_, int y_) {
        x = x_;
        y = y_;
    }
    int getX() { return x; }
    int getY() { return y; }
private:
    int x;
    int y;
};
// Euclidean distance = 실패, Manhattan distance = 성공
// 계산 시 다름

int distance(num a, num b) {
    return abs(b.getX() - a.getX()) + abs(b.getY() - a.getY());
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    num n[10] = { {3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
    num r(3, 2);
    num l(3, 0);
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            l = n[numbers[i]];
            answer += 'L';
            continue;
        }
        if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            r = n[numbers[i]];
            answer += 'R';
            continue;
        }
        if (distance(r, n[numbers[i]]) < distance(l, n[numbers[i]])) {
            r = n[numbers[i]];
            answer += 'R';
        }
        else if (distance(r, n[numbers[i]]) > distance(l, n[numbers[i]])) {
            l = n[numbers[i]];
            answer += 'L';
        }
        else {
            if (hand == "right") {
                r = n[numbers[i]];
                answer += 'R';
            }
            else {
                l = n[numbers[i]];
                answer += 'L';
            }
        }
    }
    return answer;
}