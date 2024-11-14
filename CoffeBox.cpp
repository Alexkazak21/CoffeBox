include <iostream>

using namespace std;

double Factorial(int n);

int main()
{
    cout << "OK";

    int n = 0;

    cout << "Insert n:\n";
    cin >> n;
    cout << Factorial(n);
    return 0;
}
