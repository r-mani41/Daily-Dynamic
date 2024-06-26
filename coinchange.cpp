#include <iostream>
#include <vector>
using namespace std;

// naive recursion

// ProjectIP

int coinchange(int coins[], int n, int amount)
{
    if (amount == 0)
        return 1;
    else if (amount < 0)
        return 0;

    if (n == 0)
        return 0;

    if (amount < coins[n - 1])
    {
        return coinchange(coins, n - 1, amount);
    }
    else
    {
        return coinchange(coins, n, amount - coins[n - 1]) + coinchange(coins, n - 1, amount);
    }
}

// memoization
int coinchange(int coins[], int n, int amount, vector<vector<int>> &memo)
{
    if (memo[n][amount] != -1)
        return memo[n][amount];

    if (amount == 0)
        return 1;
    else if (amount < 0)
        return 0;

    if (n == 0)
        return 0;

    if (amount < coins[n - 1])
    {
        memo[n][amount] = coinchange(coins, n - 1, amount, memo);
    }
    else
    {
        memo[n][amount] = coinchange(coins, n, amount - coins[n - 1], memo) + coinchange(coins, n - 1, amount, memo);
    }
    return memo[n][amount];
}
int main()
{
    int coins[] = {2, 5, 3, 6};
    int n = 4;
    int amount = 10;
    vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));

    cout << coinchange(coins, n, amount, memo) << endl;
    cout << coinchange(coins, n, amount);
}