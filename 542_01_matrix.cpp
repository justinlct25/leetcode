class Solution {
public:
    ///////////////////// this approach not work since it cant find the shortest path ////////////////////
    ///////////////////// this problem have to use Breath-First Search instead of Depth-FIrst Search ////////////////////
    // int nearestDistance(vector<vector<int>>& mat, int row, int col, int distance, vector<vector<bool>>& searched) {
    //     if (row<0||col<0||row>=mat.size()||col>=mat[0].size()||searched[row][col]) return std::numeric_limits<int>::max();
    //     searched[row][col] = true;
    //     if (mat[row][col] == 0) return distance;
    //     int min, dist;
    //     min = nearestDistance(mat, row+1, col, distance+1, searched);
    //     dist = nearestDistance(mat, row-1, col, distance+1, searched);
    //     if (dist < min) min = dist;
    //     dist = nearestDistance(mat, row, col+1, distance+1, searched);
    //     if (dist < min) min = dist;
    //     dist = nearestDistance(mat, row, col-1, distance+1, searched);
    //     if (dist < min) min = dist;
    //     return min;
    // }
    
    // vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //     vector<vector<int>> temp = mat;
    //     for (int row = 0; row < mat.size(); row++) {
    //         for (int col = 0; col < mat[0].size(); col++) {
    //             vector<vector<bool>> searched = vector<vector<bool>>(mat.size(), vector<bool>(mat[0].size(), false));
    //             if (mat[row][col] == 1) temp[row][col] = nearestDistance(mat, row, col, 0, searched);
    //         }
    //     }
    //     return temp;
    // }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool isValid(pair<int, int> cell, int row, int col) {
        if (cell.first<0 || cell.first>=row || cell.second<0 || cell.second>=col) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), orangeCount = 0, minuteCount = 0;
        queue<pair<int, int>> rottenQueue, newRottenQueue;
        for (int r = 0; r < row; r++) { // loop for generating queue of rotten orange and counting all orange
            for (int c = 0; c < col; c++) {
                if (grid[r][c] != 0) {
                    orangeCount++;
                    if (grid[r][c] == 2) rottenQueue.push({r, c});
                }
            }
        }
        const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        orangeCount -= rottenQueue.size();
        while (!rottenQueue.empty() && orangeCount > 0) {
            pair<int, int> cell = rottenQueue.front();
            rottenQueue.pop();
            for (int d = 0; d < 4; d++) {
                pair<int, int> neighbour = {cell.first + dy[d], cell.second + dx[d]};
                if (isValid(neighbour, row, col) && grid[neighbour.first][neighbour.second] == 1) {
                    grid[neighbour.first][neighbour.second] = 2;
                    newRottenQueue.push(neighbour);
                    orangeCount--;
                }
            }
            if (rottenQueue.empty() || orangeCount == 0) {
                rottenQueue = newRottenQueue;
                newRottenQueue = {};
                minuteCount++;
            } 
        }
        if (orangeCount > 0) return -1;
        return minuteCount;
    }
    }
};