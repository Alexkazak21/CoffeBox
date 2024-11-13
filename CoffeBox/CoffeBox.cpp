#include <iostream>
#include <stdlib.h>
#include <format>

using namespace std;

void showMenu();
void showCoinMenu();
double getMoney(double userBalance);
double Payment(double balance, double price);
void ServiceProcess(int pincode, double* balance, int* cups);
void ClearConsole();
bool CheckPINCODE(int pin);
void ShowServiceMenu(double* balance, int* cups);
int AddCups();
void Withdrow(double* balance);

int main()
{
    cout << "Welcome to the currency exchange system!" << endl;

    int choice = 0;
    int cupCount = 3;
    int* cupsPtr{ &cupCount };
    double userBalance = 0.0;
    double boxBalance = 0.0;
    double* boxBalancePtr = { &boxBalance };
    double money = 0.0;
    const double CAPPUCINO_PRICE = 2.0;
    const double LATTE_PRICE = 3.0;
    const double ECPRESSO_PRICE = 1.5;

    const int PIN = 1234;

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
        else if (choice == 5) 
        {
            ServiceProcess(PIN, boxBalancePtr, cupsPtr);
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

void ServiceProcess(int pincode, double* balance,int *cups)
{
    int choice = 0;
    bool switcher = true;
    while (switcher)
    {
        ClearConsole();

        cout << "Select what to do\n";
        cout << "1) Input pin\n";
        cout << "2) Back to Coffee selection\n\n";
        cout << "Your choice: ";

        cin >> choice;

        if (choice < 1 || choice > 2)
        {
            cout << "\nWrong choice.\n";
            system("pause");
            continue;
        }

        switch (choice)
        {
            case 1: 
            {
                if (!CheckPINCODE(pincode))
                {
                    while (true)
                    {
                        ClearConsole();
                        cout << "ON MAINTENANCE\n\n";
                        system("pause");
                        continue;
                    }
                }

                while (switcher)
                {
                    ClearConsole();
                    int servicemanChoise = 0;
                    ShowServiceMenu(balance, cups);

                    cout << "Insert your choice: ";
                    cin >> servicemanChoise;

                    if (servicemanChoise < 1 && servicemanChoise > 4)
                    {
                        system("pause");
                        continue;
                    }

                    switch (servicemanChoise)
                    {
                        case 1:
                            *cups += AddCups();
                            break;
                        case 2:
                            Withdrow(balance);
                            break;

                        default:
                            switcher = false;
                            break;
                    }
                }
            } 
                break;

            default: 
                switcher = false;
                break;
        }
    }
}

bool CheckPINCODE(int pin)
{
    for (int i = 0; i < 3; i++)
    {
        ClearConsole();

        int tempCode = 0;
        cout << "Insert PIN code to access coffee box." << endl;
        cin >> tempCode;

        if (tempCode == pin)
        {
            return true;
        }
    }
    
    return false;
}

void ClearConsole()
{
    system("cls");
}

void ShowServiceMenu(double* balance, int* cups)
{
    printf("Balance %.2f BYN\n", *balance);
    cout << "Cups: " << *cups << endl;

    cout << "1) Add cups\n";
    cout << "2) Withdrawal\n";
    cout << "3) Back to Coffee selection\n\n";
}

void Withdrow(double* balance)
{
    *balance = 0.0;
}

int AddCups() 
{
    ClearConsole();
    int cupNumber = 0;
    cout << "1) Input cups number: ";
    cin >> cupNumber;

    return cupNumber;
}
