#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


    int maxDistance(vector<vector<int>>& arrays) {
        int mincur = arrays[0][0], maxcur = arrays[0].back(), maxdiff = 0;
        int n = arrays.size();
        for (int i = 1; i < n; i++) {
            maxdiff = max(maxdiff, abs(arrays[i].back() - mincur));
            maxdiff = max(maxdiff, abs(arrays[i][0] - maxcur));
            mincur = min(mincur, arrays[i][0]);
            maxcur = max(maxcur, arrays[i].back());
        }

        return maxdiff;
    }


int main() {
    int n; 
    cin >> n;

    vector<vector<int>> arrays(n);

    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        arrays[i].resize(size);
        for (int j = 0; j < size; j++) {
            cin >> arrays[i][j];
        }
    }

    int result = maxDistance(arrays);
    cout << result;

    return 0;
}
