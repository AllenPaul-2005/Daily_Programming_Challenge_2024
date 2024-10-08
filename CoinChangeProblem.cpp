#include <iostream>
#include <vector>
#include <climits> // for INT_MAX

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    // Create a vector dp with size amount + 1, initialized to a high value (amount+1)
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // Base case: If amount is 0, no coins are needed.

    // Loop through each amount from 1 to the target amount
    for (int i = 1; i <= amount; ++i)
    {
        // For each coin, check if it can be used to make up the current amount i
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still greater than amount, it means we couldn't find a solution.
    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);

    if (result != -1)
        cout << "Minimum coins needed: " << result << endl;
    else
        cout << "No solution exists" << endl;

    return 0;
}
