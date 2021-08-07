#include <iostream>

using namespace std;

unsigned long long gcd(unsigned long long A, unsigned long long B)
{
    //Euclidian algorithm
    unsigned long long tmp;
    if (B > A)
    {
        tmp = A;
        A = B;
        B = tmp;
    }
    while (B)
    {
        tmp = A % B;
        A = B;
        B = tmp;
    }

    return A;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long A, B;
    cin >> A >> B;

    cout << gcd(A, B) << '\n';
    cout << A * B / gcd(A, B);

}
