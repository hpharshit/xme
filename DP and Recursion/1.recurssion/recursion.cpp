#include <bits/stdc++.h>
using namespace std;

// suduko solver : backtracking
class suduko
{
public:
    static bool isValid(vector<vector<char>> board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.' && board[i][col] == c)
                return false; // check row
            if (board[row][i] != '.' && board[row][i] == c)
                return false; // check column
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' && board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false; // check 3*3 block
        }
        return true;
    }

    static bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    { // trial. Try 1 through 9
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c; // Put c for this cell

                            if (solve(board))
                                return true; // If it's the solution return true
                            else
                                board[i][j] = '.'; // Otherwise go back
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        solve(board);
    }
};

// n queens : backtracking
int board[10][10];
class queens
{
public:
    bool issafe(int row, int col, int n)
    {
        for (int i = 0; i < col; i++)
        {
            if (board[row][i])
                return false;
        }
        int i = row;
        int j = col;
        while (i >= 0 && j >= 0)
        {
            if (board[i--][j--])
                return false;
        }
        i = row;
        j = col;
        while (i < n && j >= 0)
        {
            if (board[i++][j--])
                return false;
        }
        return true;
    }
    bool solveNQ(int col, vector<vector<string>> &ans, int n)
    {
        if (col >= n)
        {
            vector<string> v;
            for (int i = 0; i < n; i++)
            {
                string s = "";
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 1)
                        s += "Q";
                    else
                        s += ".";
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return true;
        }
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            if (issafe(i, col, n))
            {
                board[i][col] = 1;
                res = solveNQ(col + 1, ans, n) || res;
                board[i][col] = 0;
            }
        }
        return res;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> index;
        solveNQ(0, index, n);

        return index;
    }
};

// unique path 3  : backtracking
int dfs(vector<vector<int>> grid, int x, int y, int zero)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
        return 0;
    if (grid[x][y] == 2)
    {
        return (zero == -1) ? 1 : 0; // reached end further than end than return 1 else 0
    }
    grid[x][y] = -1; // visited
    zero--;
    int totalPaths = dfs(grid, x + 1, y, zero) + dfs(grid, x, y + 1, zero) + dfs(grid, x - 1, y, zero) + dfs(grid, x, y - 1, zero); // calling in all four direction
    // backtrack
    grid[x][y] = 0; // mark as unvisited
    zero++;
    return totalPaths;
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int zero = 0;
    int x = 0, y = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
                zero++; // number of path to travel
            if (grid[i][j] == 1)
            { // starting point
                x = i;
                y = j;
            }
        }
    }
    return dfs(grid, x, y, zero);
}

// rat in a maze : backtracking
class ratInMaze
{
public:
    static bool isSafe(int x, int y, vector<vector<int>> m, vector<vector<int>> &visited, int n)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
            return true;
        return false;
    }

    static void solve(int x, int y, vector<vector<int>> m, int n, vector<string> &ans, vector<vector<int>> &visited, string path)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }
        int newx;
        int newy;

        // marking in visited
        visited[x][y] = 1;

        // going down
        newx = x + 1;
        newy = y;
        if (isSafe(newx, newy, m, visited, n))
        {
            path.push_back('D');
            solve(newx, newy, m, n, ans, visited, path);
            path.pop_back(); // backtrack
        }

        // going up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, m, visited, n))
        {
            path.push_back('U');
            solve(newx, newy, m, n, ans, visited, path);
            path.pop_back(); // backtrack
        }

        // going right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, m, visited, n))
        {
            path.push_back('R');
            solve(newx, newy, m, n, ans, visited, path);
            path.pop_back(); // backtrack
        }

        // going left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, m, visited, n))
        {
            path.push_back('L');
            solve(newx, newy, m, n, ans, visited, path);
            path.pop_back(); // backtrack
        }

        // backtracking for another path
        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;

        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = 0;
        solve(0, 0, m, n, ans, visited, "");
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// see the solution in dp
class triangleWithMinCostToReachEnd
{

public:
    // recursion
    // going 0 to n-1 : generally we go from n-1 to 0 in recursion
    static int solve(vector<vector<int>> &triangle, int i, int j)
    {
        if (i == triangle.size() - 1)
            return triangle[i][j];
        int down = triangle[i][j] + solve(triangle, i + 1, j);
        int diagonal = triangle[i][j] + solve(triangle, i + 1, j + 1);
        return min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return solve(triangle, 0, 0);
    }
};

// max falling path Sum with two starting points: cheery 2 leetcode 1463
class maxFallingWith2StartPoint
{
public:
    static int solve(int i, int j1, int j2, vector<vector<int>> &grid, int row, int col)
    {
        if (j1 < 0 || j1 > col || j2 < 0 || j2 > col)
            return -1e8;
        if (i == row)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        // -1 left, 0 down, 1 right
        int maxi = 0;
        for (int a = -1; a <= 1; a++)
        {
            for (int b = -1; b <= 1; b++)
            {
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + a, j2 + b, grid, row, col));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + a, j2 + b, grid, row, col));
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        return solve(0, 0, grid[0].size() - 1, grid, grid.size() - 1, grid[0].size() - 1);
    }
};

// subsequences such that the sum of the minimum and maximum element on it is less or equal to target.
class subsequenceWithCondition
{
public:
    static int solve(vector<int> nums, int target, int min_, int max_, int index)
    {
        if (index >= nums.size())
        {
            if (min_ + max_ <= target)
                return 1;
            return 0;
        }
        // exclude
        int l = solve(nums, target, min_, max_, index + 1);

        // include
        min_ = min(nums[index], min_);
        max_ = max(nums[index], max_);
        int r = solve(nums, target, min_, max_, index + 1);
        return l + r;
    }
    int numSubseq(vector<int> &nums, int target)
    {
        return solve(nums, target, INT_MAX, INT_MIN, 0) - 1;
    }

    /* non recursive solution
    int numSubseq(vector<int>& nums, int target) {
       int ans=0;
       int MAX=1e9 +7;
       sort(nums.begin(),nums.end());
       vector<int> powerOf2(nums.size());
       powerOf2[0]=1;  // 2^0
       for(int i=1;i<nums.size();i++){
           powerOf2[i]=(powerOf2[i-1]*2)%MAX;
       }
       int l=0,r=nums.size()-1;
       while(l<=r){
           if(nums[l]+nums[r]<=target){
               ans+=powerOf2[r-l];
               ans%=MAX;
               l++;
           }
           else {
               r--;
           }
       }
       return ans;
    }
    */
};

// Edit Distance:min operations to convert string A to string B using 3 operations: replace,remove,insert
int solve(string s1, int i, string s2, int j)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (s1[i] == s2[j])
        return 0 + solve(s1, i - 1, s2, j - 1);
    return min(1 + solve(s1, i - 1, s2, j - 1), min(1 + solve(s1, i - 1, s2, j), 1 + solve(s1, i, s2, j - 1)));
}
int minDistance(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    return solve(word1, n1 - 1, word2, n2 - 1);
}

// LIS
int solve(int i, int prev_i, vector<int> nums, int n)
{
    if (i == n)
        return 0;
    int len = 0 + solve(i + 1, prev_i, nums, n); // not take
    if (prev_i == -1 || nums[i] > nums[prev_i])
        len = max(len, 1 + solve(i + 1, i, nums, n)); // take
    return len;
}
int lengthOfLIS(vector<int> &nums)
{
    return solve(0, -1, nums, nums.size());
}

// Matrix Chain Multiplication
int mcm(int i, int j, int arr[])
{
    if (i == j)
        return 0;
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + mcm(i, k, arr) + mcm(k + 1, j, arr);
        mini = min(mini, steps);
    }
    return mini;
}
int matrixMultiplication(int N, int arr[])
{
    //  i running from 1 to N-1 and j running from N-1 to 1: se mcm striver video
    mcm(1, N - 1, arr);
}

// mcm: evaluate the expression as true or false
int mod = 1000000007;
int solve(int i, int j, int isTrue, string &exp)
{
    // Base case 1:
    if (i > j)
        return 0;
    // Base case 2:
    if (i == j)
    {
        if (isTrue == 1)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        long long lT = solve(i, ind - 1, 1, exp);
        long long lF = solve(i, ind - 1, 0, exp);
        long long rT = solve(ind + 1, j, 1, exp);
        long long rF = solve(ind + 1, j, 0, exp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod) % mod;
            else
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways;
}
int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.size();
    return solve(0, n - 1, 1, exp);
}

// mcm: palindrome partition II
bool isPalindrome(int i, int j, string s)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(int i, int n, string s)
{
    if (i == n)
        return 0;
    int min_cost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int cost = 1 + solve(j + 1, n, s);
            min_cost = min(min_cost, cost);
        }
    }
    return min_cost;
}
int minCut(string s)
{
    int n = s.length();
    return solve(0, n, s) - 1; //-1 to remove a count for partition at the end
}


// 
int main()
{

    return 0;
}