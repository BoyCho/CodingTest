#include <iostream>
#include <math.h>

using namespace std;

long long lcm(long double max, long double min) {
    double n = 1;
    while(1){
        if (max * n == 0) return max;
        n++;
    }
}

long long solution(int w, int h) {
    long long answer = (long long)w * (long long)h;
    long double _w, _h;
    long double gradient;

    h >= w ? (_w = w, _h = h) : (_w = h, _h = w);
    gradient = _h / _w;

    answer -= _w * ceil(gradient);
    
    return answer;
}

int main() {
    cout << solution(2,5);
}

// 숫자 사용 시 자료형 조심