#include <iostream>

using namespace std;
void showMenu();
void showCoinMenu();
double getMoney(double userBalance);
double Payment(double balance, double price);

int main()
{
    cout << "Welcome to the currency exchange system!" << endl;

    int choice = 0;
    int cupCount = 3;
    double userBalance = 0.0;
    double boxBalance = 0.0;
    double money = 0.0;
    const double CAPPUCINO_PRICE = 2.0;
    const double LATTE_PRICE = 3.0;
    const double ECPRESSO_PRICE = 1.5;

    while (true) {
        if (cupCount == 0)
        {
            cout << "The machine is not working due to technical reasons" << endl;
            return 1;
        }
        cout << endl;
        cout << "Balance: " << userBalance << "BYN" << endl;
        showMenu();

        cout << "Your choice? ";
        cin >> choice;

        if (choice == 1)
        {
            userBalance = getMoney(userBalance);
            cout << userBalance << "BYN is deposited" << endl;
            boxBalance += userBalance;
        }
        else if (choice == 2) {
            userBalance = Payment(userBalance, CAPPUCINO_PRICE);
            cout << "Ok, take your cappuccino" << endl;
            cupCount--;
        }
        else if (choice == 3) {
            userBalance = Payment(userBalance, LATTE_PRICE);
            cout << "Ok, take your latte" << endl;
            cupCount--;
        }
        else if (choice == 4) {
            userBalance = Payment(userBalance, ECPRESSO_PRICE);
            cout << "Ok, take your espresso" << endl;
            cupCount--;
        }
        else if (choice == 5) {
            cout << "Zaglushka dlia Service" << endl;
        }
        else {
            cout << "Input [1..5], please" << endl;
        }
    }
    cout << "Ok";
    return 0;
}

void showMenu()
{
    cout << endl;
    cout << "1) Insert coin" << endl;
    cout << "2) Cappuccino" << endl;
    cout << "3) Latte" << endl;
    cout << "4) Espresso" << endl;
    cout << "5) Service" << endl;
}

void showCoinMenu()
{
    cout << "1) 10 kopeks" << endl;
    cout << "2) 20 kopeks" << endl;
    cout << "3) 50 kopeks" << endl;
    cout << "4) 1 ruble" << endl;
    cout << "5) 2 rubles" << endl;
    cout << "6) Back to Coffee selection" << endl;
}

double getMoney(double balance)
{
    int choice = 0;
    while (true)
    {
        cout << "Balance: " << balance << endl;
        showCoinMenu();
        cout << "Insert coin: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            balance += 0.1;
        }
        else if (choice == 2) 
        {
            balance += 0.2;
        }
        else if (choice == 3)
        {
            balance += 0.5;
        }
        else if (choice == 4)
        {
            balance += 1.0;
        }
        else if (choice == 5)
        {
            balance += 2.0;
        }
        else if (choice == 6)
        {
            return balance;
        }
        else {
            cout << "Input [1..6], please" << endl;
        }
    }
}
double Payment(double balance, double price)
{
    if (balance < price)
    {
        cout << "Insufficient money" << endl;
        return 2;
    }
    return  balance - price;
}