#include <bits/stdc++.h>
using namespace std;

// 1. Simple DP
int HouseRobber(int arr[], int n) // sticker theif //maximum sum of two adjacent nodes
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += dp[i - 2];
        int nottake = dp[i - 1];
        dp[i] = max(take, nottake);
    }
    return dp[n - 1];
}

int nthStair(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + min(dp[i - 1], dp[i - 2]);
    }
    return dp[n];
}

// 2. DP on Grid

int numberOfPaths(int row, int col) // in 2d matrix
{
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = 1; // base condition
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i != 0 || j != 0)
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[row - 1][col - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &arr)
{
    if (arr.size() == 0)
        return 0;
    if (arr[0][0] == 1)
        return 0;
    int row = arr.size(), col = arr[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i != 0 || j != 0) && (arr[i][j] != 1))
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[row - 1][col - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    if (grid.size() == 0)
        return INT_MAX;
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i != 0 || j != 0)
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[row - 1][col - 1];
}

// stock:

// Best Time to Buy and Sell Stock I : single transaction only: largest profit
int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

// Best Time to Buy and Sell Stock II : infinite number of buy-sell: largest profit
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // n*2 => buy,sell
    dp[n][0] = dp[n][1] = 0;                          // no buy and sell if we are on last index
    for (int i = n - 1; i >= 0; i--)                  // index of array
    {
        for (int buy = 0; buy <= 1; buy++) // 0 means cannot buy,  1 means can buy
        {
            if (buy)                                                           // allowed to buy if buy==1; either buy or don't buy
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]); // buy or not buy
            else                                                               // not allowed to buy if buy==0; either sell or don't sell
                dp[i][buy] = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);  // sell or not sell
        }
    }
    return dp[0][1];
}

// Best Time to Buy and Sell Stock III : number of transactions are limited to 2: largest profit
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int t = 2; // only two transactions allowed
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(t + 1, 0)));

    for (int i = n - 1; i >= 0; i--)
    { // index
        for (int j = 0; j <= 1; j++)
        { // buy or not buy
            for (int k = 0; k <= 2; k++)
            { // number of transactions
                if (k == 0)
                    dp[i][j][k] = 0;
                else
                {
                    if (j)
                        dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], 0 + dp[i + 1][1][k]);
                    else
                        dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], 0 + dp[i + 1][0][k]);
                }
            }
        }
    }
    return dp[0][1][2];
}

// Best Time to Buy and Sell Stock IV : number of transactions are limited to k: largest profit
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    for (int i = n - 1; i >= 0; i--)
    { // array index
        for (int j = 0; j <= 1; j++)
        { // buy or not nuy
            for (int l = 0; l <= k; l++)
            { // no. of transactions
                if (l == 0)
                    dp[i][j][l] = 0;
                else
                {
                    if (j) // buy
                        dp[i][j][l] = max(-prices[i] + dp[i + 1][0][l], dp[i + 1][1][l]);
                    else // not buy
                        dp[i][j][l] = max(prices[i] + dp[i + 1][1][l - 1], dp[i + 1][0][l]);
                }
            }
        }
    }
    return dp[0][1][k];
}

// Best Time to Buy and Sell Stock II with cooldown : cannot buy immediately after sell: (use index+2)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // use n+2 ro handel i+2
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    { // index
        for (int j = 0; j <= 1; j++)
        {
            if (j)
                dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            else
                dp[i][j] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]); // here use i+2 to handel cooldown
        }
    }
    return dp[0][1];
}

// Best Time to Buy and Sell Stock II with transaction fees
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // n*2 => buy,sell
    dp[n][0] = dp[n][1] = 0;                          // no buy and sell if we are on last index
    for (int i = n - 1; i >= 0; i--)                  // index of array
    {
        for (int buy = 0; buy <= 1; buy++) // 0 means cannot buy,  1 means can buy
        {
            if (buy)                                                                // allowed to buy if buy==1; either buy or don't buy
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);      // buy or not buy
            else                                                                    // not allowed to buy if buy==0; either sell or don't sell
                dp[i][buy] = max(prices[i] + dp[i + 1][1] - fee, 0 + dp[i + 1][0]); // sell or not sell
        }
    }
    return dp[0][1];
}

// path sum:

int triangleMinSumToReachBottom(vector<vector<int>> &triangle)
{
    // leetcode 120
    // going from  n-1 to 0 : generally we go from 0 to n-1 in tabulation
    int row = triangle.size();
    int col = triangle[row - 1].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    // storing last row in the dp as it will be common for all solution
    for (int j = 0; j < col; j++)
    {
        dp[row - 1][j] = triangle[row - 1][j];
    }

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = triangle[i].size() - 1; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// Minimum Falling Path Sum
int minFallingPathSum(vector<vector<int>> &matrix)
{
    // leetcode 931
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    // coping last row as it will be included for all paths
    for (int i = 0; i < col; i++)
    {
        dp[row - 1][i] = matrix[row - 1][i];
    }
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int down = INT_MAX, left = INT_MAX, right = INT_MAX;

            down = matrix[i][j] + dp[i + 1][j];
            if (j > 0)
                left = matrix[i][j] + dp[i + 1][j - 1];
            if (j < col - 1)
                right = matrix[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, min(left, right));
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < col; i++)
    {
        ans = min(ans, dp[0][i]);
    }
    return ans;
}

// Maximum Falling Path Sum
int maximumFallingPathSum(int N, vector<vector<int>> Matrix)
{
    // gfg : Maximum path sum in matrix
    int row = N;
    int col = N;
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < col; i++)
        dp[row - 1][i] = Matrix[row - 1][i];
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int down = INT_MIN, left = INT_MIN, right = INT_MIN;
            down = Matrix[i][j] + dp[i + 1][j];
            if (j > 0)
                left = Matrix[i][j] + dp[i + 1][j - 1];
            if (j < col - 1)
                right = Matrix[i][j] + dp[i + 1][j + 1];
            dp[i][j] = max(down, max(right, left));
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < col; i++)
        ans = max(ans, dp[0][i]);
    return ans;
}

// maximum cheery you can pickup from 0,0 to n-1,n-1 : down,right movements allowed
int cherryPickupOneDirection(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1e8));
    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        if (grid[0][i] >= 0)
        {
            sum += grid[0][i];
            dp[0][i] = sum;
        }
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] >= 0)
            {
                int down = INT_MIN, right = INT_MIN;
                down = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    right = grid[i][j] + dp[i][j - 1];
                dp[i][j] = max(down, right);
            }
        }
    }
    return (dp[row - 1][col - 1] > 0) ? dp[row - 1][col - 1] : 0;
}

// maximum cheery you can pickup from n-1,n-1 to 0,0 : up, left movements allowed
int cherryPickupOneDirection(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1e8));
    int sum = 0;
    for (int i = col - 1; i >= 0; i--)
    {
        if (grid[row - 1][i] >= 0)
        {
            sum += grid[row - 1][i];
            dp[row - 1][i] = sum;
        }
    }
    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] >= 0)
            {
                int left = INT_MIN, up = INT_MIN;
                up = grid[i][j] + dp[i + 1][j];
                if (j < col - 1)
                    left = grid[i][j] + dp[i][j + 1];
                dp[i][j] = max(up, left);
            }
        }
    }
    return (dp[row - 1][col - 1] > 0) ? dp[row - 1][col - 1] : 0;
}

// maximum cheery you can pickup from (0,0 to n-1,n-1) + (n-1,n-1 to 0,0)  : pick 1 cherry only one time in either direction
// : down,right movements allowed
int cherryPickupTwoDirection(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));

    // base condition
    for (int j1 = 0; j1 < col; j1++)
    {
        for (int j2 = 0; j2 < col; j2++)
        {
            if (j1 == j2)
                dp[row - 1][j1][j2] = grid[row - 1][j1];
            else
                dp[row - 1][j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
        }
    }

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < col; j1++)
        {
            for (int j2 = 0; j2 < col; j2++)
            {
                int maxi = -1e8;
                for (int a = -1; a <= 1; a++)
                {
                    for (int b = -1; b <= 1; b++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + a >= 0 && j1 + a < col && j2 + b >= 0 && j2 + b < col)
                            value += dp[i + 1][j1 + a][j2 + b];
                        else
                            value += -1e8; // adding big negative value to ignore it

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][col - 1]; // robot 1 at(0,0) , robot 2 at(0,col-1)
}

// Maximum fall with 2 starting point: 3d matrix : leetcode 1463
int cherryPickup(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));

    // base condition
    for (int j1 = 0; j1 < col; j1++)
    {
        for (int j2 = 0; j2 < col; j2++)
        {
            if (j1 == j2)
                dp[row - 1][j1][j2] = grid[row - 1][j1];
            else
                dp[row - 1][j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
        }
    }

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < col; j1++)
        {
            for (int j2 = 0; j2 < col; j2++)
            {
                int maxi = -1e8;
                for (int a = -1; a <= 1; a++)
                {
                    for (int b = -1; b <= 1; b++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + a >= 0 && j1 + a < col && j2 + b >= 0 && j2 + b < col)
                            value += dp[i + 1][j1 + a][j2 + b];
                        else
                            value += -1e8; // adding big negative value to ignore it

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][col - 1]; // robot 1 at(0,0) , robot 2 at(0,col-1)
}

// 3. DP on Subsequence / Subset

// 0/1 knapsack:
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

// 0/1 knapsack with duplicate value

// coin change with infinte supply of coins
long long int coinChange(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // dp[i][j-coins[i-1]]  because we have infinite supply
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}

// minimum coins required in coin change with infinite supply of coins
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX - 1; // if size of array is 0 then there is no way to form 'amount'
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], 0 + dp[i - 1][j]);
            else
                dp[i][j] = 0 + dp[i - 1][j];
        }
    }
    return (dp[n][amount] == INT_MAX - 1) ? -1 : dp[n][amount];
}

//  rod cut basic
int cutRod(int price[], int n)
{
    int length[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    int dp[n + 1][n + 1]; // dp[size+1][n+1]    here size==n
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            // can choose same length multiple times so dp[i][j - length[i - 1]]
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][n];
}

// rod cut with cutting position specified and cost of cutting is the length of sticks to cut (minimum cost to cut all cuts[] leetcode 1547   (Minimum Cost to Cut a Stick))
int solve(int start, int end, vector<int> cuts, int cuts_start, int cuts_end, vector<vector<int>> &dp)
{
    if (cuts_start > cuts_end)
        return 0;
    if (dp[cuts_start][cuts_end] != -1)
        return dp[cuts_start][cuts_end];
    int ans = INT_MAX;
    for (int i = cuts_start; i <= cuts_end; i++)
    {
        int left = solve(start, cuts[i], cuts, cuts_start, i - 1, dp); // calculate fro i-1
        int cost = end - start;                                        // ith cost : cost=length to cut
        int right = solve(cuts[i], end, cuts, i + 1, cuts_end, dp);    // calculate for i+1
        ans = min(ans, left + cost + right);
    }
    return dp[cuts_start][cuts_end] = ans;
}
int minCost(int n, vector<int> &cuts)
{
    vector<vector<int>> dp(101, vector<int>(101, -1));
    sort(cuts.begin(), cuts.end());
    return solve(0, n, cuts, 0, cuts.size() - 1, dp);
}

// array:

// subset with sum k: true or false
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1, false));
    // base condition
    for (int i = 0; i < arr.size() + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i < arr.size() + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            // tabulation(dp) is opposite of memoization(recursion)
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]; // take || not take
            else
                dp[i][j] = dp[i - 1][j]; // not take
        }
    }
    return dp[arr.size()][sum];
}

// partition into equal subset sums
int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false; // no even partitioning possible
    int target = sum / 2;
    vector<vector<bool>> dp(N + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][target];
}

// Partition Array Into Two Arrays to Minimize Sum Difference: negative vector values
int minimumDifference(vector<int> &nums)
{
    int sum = 0, n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    if (sum <= 0)
    {
        int mi = INT_MAX;
        for (int i = 0; i < n; i++)
            mi = min(mi, nums[i]);
        for (int i = 0; i < n; i++)
            nums[i] += abs(mi);
        sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < sum / 2 + 1; i++)
    {
        if (dp[n][i])
        {
            ans = min(ans, sum - i);
        }
    }
    return ans;
}

// Count no of subsets with given difference
int countWithGivenSum(int nums[], int n, int diff)
{
    /* let two sets be s1 and s2
       s1+s2=sum
       s1-s2=target
       2*s1=sum+target
       s1=(sum+target)/2   => find no. of sets with sum equals to (sum+target)/2
    */
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    int reqSum = (diff + sum) / 2;
    // Initializing the matrix
    int dp[n + 1][sum + 1];
    // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if the value is greater than the sum
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

// Counts Subsets with Sum K
int findTargetSumWays(vector<int> &nums, int target)
{
    /* let two sets be s1 and s2
       s1+s2=sum
       s1-s2=target
       2*s1=sum+target
       s1=(sum+target)/2   => find no. of sets with sum equals to (sum+target)/2
    */
    int sum = 0;
    for (int i : nums)
        sum += i;
    sum += target;
    if (sum < 0)
        return 0;
    if (sum % 2 != 0)
        return 0; // no partition available
    sum /= 2;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++) // zero to include zero sum as well
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

// LCS:

// Longest Common Subsequence LCS and print LCS
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.size(), n2 = text2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // printing longest common subsequence
    string ans = "";
    int i = n1, j = n2;
    while (i && j)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans.push_back(text1[i - 1]);
            i--, j--; // move digonally
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--; // move up
            else if (dp[i - 1][j] <= dp[i][j - 1])
                j--; // move left
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return dp[n1][n2];
}

// print all LCS
void helper(string s, string t, int row, int col, string temp, int count, set<string> &st)
{
    if (count == 0)
    {
        st.insert(temp);
        return;
    }
    if (row >= s.length() || col > t.length())
        return;
    for (int i = row; i < s.length(); i++)
    {
        for (int j = col; j < t.length(); j++)
        {
            if (s[i] == t[j])
            {
                temp.push_back(s[i]); // take
                helper(s, t, i + 1, j + 1, temp, count - 1, st);
                temp.pop_back(); // not take
            }
        }
    }
}
vector<string> all_longest_common_subsequences(string s, string t)
{
    int n1 = s.length(), n2 = t.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    vector<string> ans;
    set<string> st;
    helper(s, t, 0, 0, "", dp[n1][n2], st);
    for (auto i : st)
    {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Number of common Subsequence LCS: child of LCS
int numberOfDistinctCommonSequence(string s, string t)
{
    int n1 = s.length(), n2 = t.length();
    vector<vector<unsigned long long>> dp(n1 + 1, vector<unsigned long long>(n2 + 1, 0));
    // base condition: when t is empty then we can create empty set
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                // if text match than either we can choose it to take and created 't' else skip it and check in rest string
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j]; // does not match then reduce size of string and search in rest string
        }
    }
    return dp[n1][n2];
}

// longest palindromic subsequence : child of LCS
int longestPalindromeSubseq(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == temp[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

// Minimum Insertion or Deletion Steps to Make a String Palindrome: string_length - longest_palindromic_subsequence
int minInsertionsOrDeletionToMakeStringPalindrome(string s)
{
    int n = s.length();
    string temp = s;
    reverse(temp.begin(), temp.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == temp[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return s.length() - dp[n][n]; // abcda -> abcddcba
}

// Minimum number of deletions and insertions to make string a as string b. 2 operations: remove,insert
int minDelInsTomakeAequalsB(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return n1 + n2 - 2 * dp[n1][n2];
}

// Edit Distance:min operations to convert string A to string B using 3 operations: replace,remove,insert
int editDistance(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0)
                dp[i][j] = j; // converting if(i<0) return j+1; to one based indexing
            if (j == 0)
                dp[i][j] = i; // converting if(j<0) return i+1; to one based indexing
        }
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            else
                dp[i][j] = min(1 + dp[i][j - 1], min(1 + dp[i - 1][j], 1 + dp[i - 1][j - 1])); // insert,delete,replace
        }
    }
    return dp[n1][n2];
}

// wildcard matching
int wildCard(string pattern, string str)
{
    // here string pattern stores * or ?
    int n1 = pattern.length(), n2 = str.length();
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true; // both string exhausted
            else if (i == 0 && j > 0)
                dp[i][j] = false; // string 1 exhausted so cannot match string 2
            else if (i > 0 && j == 0)
            { // string 2 exhausted, can match only if all remaining characters of string1 are '*' (can match * with null)
                dp[i][j] = true;
                for (int k = 1; k <= i; k++)
                {
                    if (pattern[k - 1] != '*')
                    {
                        dp[i][j] = false;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1]; // match or pattern has ?
            else if (pattern[i - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; // pattern has * so either match(keep i move j) or leave(move i and keep j)
            else
                dp[i][j] = false; // none match
        }
    }
    return dp[n1][n2];
}

// regular expression matching
bool isMatch(string s, string p)
{
    // same as wildcard matching with a slight change
    //  string p is pattern
    int n1 = s.length(), n2 = p.length();
    vector<vector<bool>> dp(n2 + 1, vector<bool>(n1 + 1, false));
    for (int i = 0; i <= n2; i++)
    {
        for (int j = 0; j <= n1; j++)
        {
            //  base condition
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0 && j > 0)
                dp[i][j] = false;
            else if (i > 0 && j == 0)
            {
                if (p[i - 1] == '*')
                    dp[i][j] = dp[i - 2][j];
                else
                    dp[i][j] = false;
            }
            else
            {
                //  main dp code
                if (p[i - 1] == s[j - 1] || p[i - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1]; // match of pattern is '.'
                else if (p[i - 1] == '*')
                { // star appears
                    if (s[j - 1] == p[i - 2] || p[i - 2] == '.')
                        dp[i][j] = dp[i - 2][j] || dp[i][j - 1]; // mis* and mis
                    else
                        dp[i][j] = dp[i - 2][j]; // mis* and mi
                }
                else
                    dp[i][j] = false; // do not match
            }
        }
    }
    return dp[n2][n1];
}

// shortest Common Supersequence: string1.length()+string2.length()-LCS
int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return m + n - dp[m][n];
}

// print shortest Common Supersequence
string shortestCommonSupersequence(string str1, string str2)
{
    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    int i = m, j = n;
    while (i && j)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            else if (dp[i - 1][j] <= dp[i][j - 1])
            {
                ans += str2[j - 1];
                j--;
            }
        }
    }
    while (i)
    {
        ans += str1[i - 1];
        i--;
    }
    while (j)
    {
        ans += str2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Longest Repeating Subsequence
int LongestRepeatingSubsequence(string str)
{
    int n = str.length();
    string temp = str;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == temp[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

// longest common substring : child of LCS
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int ans = INT_MIN;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

// LIS : (longest increasing subsequence)

// length of LIS
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1); // minimum chain length is 1 (single string)
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i])
                dp[i] = max(dp[i], 1 + dp[prev]);
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1); // minimum chain length is 1 (single string)
    vector<int> hash(n, 0);
    int maxi = 1, last_i = 0; // to print LIS
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            last_i = i;
        }
    }

    // printing LIS
    vector<int> LIS(maxi, 0);
    LIS[0] = nums[last_i];
    int i = 1;
    while (last_i != hash[last_i])
    {
        last_i = hash[last_i];
        LIS[i++] = nums[last_i];
    }
    reverse(LIS.begin(), LIS.end());
    for (int i : LIS)
    {
        cout << i << " ";
    }
    return maxi;
}

// length of longest divisible subset : LIS part
int lengthofLargestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxi = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0)
                dp[i] = max(dp[i], 1 + dp[prev]);
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
vector<int> printLargestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxi = 1, last_i = 0;
    vector<int> dp(n, 1); // minimum chain length is 1 (single string)
    vector<int> hash(n, 0);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            last_i = i;
        }
    }

    vector<int> LDS(maxi, 0);
    LDS[0] = nums[last_i];
    int i = 1;
    while (last_i != hash[last_i])
    {
        last_i = hash[last_i];
        LDS[i++] = nums[last_i];
    }
    return LDS;
}

// Longest String Chain
bool compare(string a, string b)
{
    if (a.size() != b.size() + 1)
        return false;
    // size difference must be 1
    int i = 0, j = 0;
    while (i < a.length())
    {
        if (a[i] == b[j])
            i++, j++;
        else
            i++;
    }
    if (i == a.length() && j == b.length())
        return true; // i reaches end first
    return false;
}
static bool cmp(string s, string d)
{
    return s.length() < d.length(); // sorting based on length
}
int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), cmp);
    int n = words.size();
    vector<int> dp(n, 1); // minimum chain length is 1 (single string)
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (compare(words[i], words[prev]) && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

// longest bitonic subsequence
int LongestBitonicSequence(vector<int> nums)
{
    // LIS  : increasing bitonic + decreasing bitonic -1(common peak element)

    // increasing bitonic
    int n = nums.size();
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev])
            {
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
            }
        }
    }

    // decreasing bitonic
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (nums[i] > nums[prev])
            {
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
            }
        }
    }

    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

// number of LIS
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);    // minimum chain length is 1 (single string)
    vector<int> count(n, 1); // number of ways subsequence of dp[i] can be formed
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i] && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if (nums[prev] < nums[i] && dp[i] == 1 + dp[prev])
            {                            // length repeat eg: 1,6 and 4,6
                count[i] += count[prev]; // add all ways that it forms a subsequence of equal length
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            cnt += count[i];
    }
    return cnt;
}

// 4. Matrix Chain Multiplcation:  //partition dp
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = N - 1; i >= 1; i--) // in recursion i (1 to N-1)
    {
        for (int j = i; j < N; j++)
        {
            if (i == j)
                dp[i][j] = 0; // base condition
            else
            {
                int mini = 1e9;
                for (int k = i; k <= j - 1; k++)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
    }
    return dp[1][N - 1]; // as we are running from 1 to N-1 in recursion
}

// mcm: Minimum Cost to Cut a Stick
int minCost(int n, vector<int> &cuts)
{
    // sort the cuts array to make cutting of sticks independent
    int c = cuts.size(); // original length before inserting 0 and n
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0)); //+2 for safety (k+1)
    // 0 (1 3 4 5) 7
    for (int i = c; i >= 1; i--)
    { // in recusion i(1 to N-1 (c here after inserting n))
        for (int j = 1; j <= c; j++)
        { // in recursion j(N-1 to 1 (1 because we have insertedd zero in the beginning))
            if (i > j)
                dp[i][j] = 0; // base condition
            else
            {
                int mini = INT_MAX;
                for (int k = i; k <= j; k++)
                {
                    int steps = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
    }
    return dp[1][c];
}

// mcm: ballon burst no. of coins => BACK PARTITION (start partition from end)
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // +2 to handel k+1
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue; // base condition
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int steps = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                maxi = max(maxi, steps);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

// not done
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

// not done
// mcm : minimum partition to make a string palindrome => FRONT PARTITION (start partition from BEGINNING)
int minCut(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int min_cost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            int l = i, h = j;
            bool palin = true; // check palindrome
            while (l <= h)
            {
                if (s[l] != s[h])
                    palin = false;
                l++;
                h--;
            }
            if (palin)
            {
                int cost = 1 + dp[j + 1];
                min_cost = min(min_cost, cost);
            }
        }
        dp[i] = min_cost;
    }
    return dp[0] - 1; //-1 to remove a count for partition at the end
}

// mcm: Partition Array for Maximum Sum


int main()
{
    return 0;
}