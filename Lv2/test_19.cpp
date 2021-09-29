#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> arr(rows, vector<int>(columns));
    vector<int> answer;
    int cnt = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            arr[i][j] = cnt++;
    }

    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0] - 1;
        int b = queries[i][1] - 1;
        int c = queries[i][2] - 1;
        int d = queries[i][3] - 1;
        int tmp = arr[a][b];
        int min = tmp;

        for (int j = a + 1; j <= c; j++) {
            if (arr[j][b] < min) min = arr[j][b];
            arr[j - 1][b] = arr[j][b];
        }
        for (int j = b + 1; j <= d; j++) {
            if (arr[c][j] < min) min = arr[c][j];
            arr[c][j - 1] = arr[c][j];
        }
        for (int j = c - 1; j >= a; j--) {
            if (arr[j][d] < min) min = arr[j][d];
            arr[j + 1][d] = arr[j][d];
        }
        for (int j = d - 1; j >= b; j--) {
            if (arr[a][j] < min) min = arr[a][j];
            arr[a][j + 1] = arr[a][j];
        }
        arr[a][b + 1] = tmp;
        answer.push_back(min);
    }
    return answer;
}