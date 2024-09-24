#include <iostream>
using namespace std;

// Function to compute the GCD (Greatest Common Divisor) using Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the LCM using the GCD
int lcmOptimal(int N, int M)
{
    return (N * M) / gcd(N, M);
}

int main()
{
    int N = 4, M = 6;
    cout << "LCM (Optimal) of " << N << " and " << M << " is: " << lcmOptimal(N, M) << endl;
    return 0;
}
