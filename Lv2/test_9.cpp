#include <vector>
#include <iostream>

using namespace std;

int area_check(vector<vector<int>> picture, vector<vector<int>> check, int i, int j, int area_n, int m, int n) {
    check[i][j] = -1;
    if (m > i + 1) {
        if (picture[i + 1][j] > 0 && check[i + 1][j] >= 0)
            area_n = area_check(picture, check, i + 1, j, ++area_n, m, n);
    }
    if (i > 0) {
        if (picture[i - 1][j] > 0 && check[i - 1][j] >= 0)
            area_n = area_check(picture, check, i - 1, j, ++area_n, m, n);
    }
    if (n > j + 1) {
        if (picture[i][j + 1] > 0 && check[i][j + 1] >= 0)
            area_n = area_check(picture, check, i, j + 1, ++area_n, m, n);
    }
    if (j > 0) {
        if (picture[i][j - 1] > 0 && check[i][j - 1] >= 0)
            area_n = area_check(picture, check, i, j - 1, ++area_n, m, n);
    }
    return area_n;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int tmp;
    vector<vector<int>> check(m, vector<int>(n));
    vector<int> answer(2);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] > 0 && check[i][j] >= 0) {
                number_of_area++;
                tmp = area_check(picture, check, i, j, 0, m, n);
                if (max_size_of_one_area < tmp)
                    max_size_of_one_area = tmp;
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    vector<int> a = solution(6, 4, { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} });
    cout << a[0] << " " << a[1];
}
/*
    칸이 진행 가능인 경우 : 함수 사용(영역+1) -> 재귀로 계속 사용
    check 이중 벡터로 색깔 있는 칸 구별
*/