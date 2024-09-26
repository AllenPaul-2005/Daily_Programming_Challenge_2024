#include <iostream>
using namespace std;

int countDivisorsBruteForce(int N)
{
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int N;
    cout << "Enter a number: ";
    cin >> N;
    cout << "Number of divisors: " << countDivisorsBruteForce(N) << endl;
    return 0;
}
