#include <iostream>
#include <stdlib.h>
#include <format>

using namespace std;

void showMenu();
void showCoinMenu();
double getMoney();
double Payment(double price);
bool IsEnought(double price);
void showMaintanceMenu();

void ServiceProcess(int pincode);
void ClearConsole();
bool CheckPINCODE(int pin);
void ShowServiceMenu();
int AddCups();
void Withdrow();

int cupCount = 7;
double userBalance = 0.0;
double boxBalance = 0.0;

const int PIN = 1234;
const double CAPPUCINO_PRICE = 2.0;
const double LATTE_PRICE = 3.0;
const double ECPRESSO_PRICE = 1.5;

int main()
{
    int choice = 0;       

    while (true) 
    {
        showMaintanceMenu();

        if (boxBalance == 0)
        {
            userBalance = 0.0;
        }

        showMenu();

        cout << "Your choice? ";
        cin >> choice;

        if (choice == 1)
        {
            getMoney();
            cout << endl << userBalance << " BYN is deposited" << endl;
            boxBalance += userBalance;
            system("pause");
        }
        else if (choice == 2 && IsEnought(CAPPUCINO_PRICE) == true) {
            userBalance = Payment(CAPPUCINO_PRICE);
            cout << "Ok, take your cappuccino" << endl;
            cupCount--;
            system("pause");
        }
        else if (choice == 3 && IsEnought(LATTE_PRICE) == true) {
            userBalance = Payment(LATTE_PRICE);
            cout << "Ok, take your latte" << endl;
            cupCount--;
            system("pause");
        }
        else if (choice == 4 && IsEnought(ECPRESSO_PRICE) == true) {
            userBalance = Payment(ECPRESSO_PRICE);
            cout << "Ok, take your espresso" << endl;
            cupCount--;
            system("pause");
            continue;
        }
        else if (choice == 5)
        {
            ServiceProcess(PIN);
        }
        else {
            cout << "\nWrong choice. Input [1..5], please\n" << endl;
            system("pause");
        }
        
        ClearConsole(); 
    }
    return 0;
}
void showMaintanceMenu()
{
    int choice = 0; 
    while (cupCount == 0)
    {
        cout << "ON MAINTENANCE" << endl;
        cout << "1) Service" << endl;
        cout << "Your choice?" << endl;
        cin >> choice;
        if (choice == 1)
        {
            ServiceProcess(PIN);
        }           
        else
            cout << "ON MAINTENANCE" << endl;
        system("pause");
        ClearConsole();
    }
}
void showMenu()
{
    cout << endl;
    cout << "=================================" << endl;
    cout << "Balance: " << userBalance << endl;
    cout << "1) Insert coin" << endl;
    cout << "2) Cappuccino - " << CAPPUCINO_PRICE << " BYN" << endl;
    cout << "3) Latte - " << LATTE_PRICE << " BYN" << endl;
    cout << "4) Espresso - " << ECPRESSO_PRICE << " BYN" << endl;
    cout << "5) Service" << endl;
    cout << "=================================" << endl;
}

void showCoinMenu()
{
    cout << endl;
    cout << "=================================" << endl;
    cout << "Balance: " << userBalance << endl;
    cout << "1) 10 kopeks" << endl;
    cout << "2) 20 kopeks" << endl;
    cout << "3) 50 kopeks" << endl;
    cout << "4) 1 ruble" << endl;
    cout << "5) 2 rubles" << endl;
    cout << "6) Back to Coffee selection" << endl;
    cout << "=================================" << endl;
}

double getMoney()
{
    int choice = 0;

    while (true)
    {
        ClearConsole();

        showCoinMenu();

        cout << "Insert coin: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            userBalance += 0.1;
        }
        else if (choice == 2)
        {
            userBalance += 0.2;
        }
        else if (choice == 3)
        {
            userBalance += 0.5;
        }
        else if (choice == 4)
        {
            userBalance += 1.0;
        }
        else if (choice == 5)
        {
            userBalance += 2.0;
        }
        else if (choice == 6)
        {
            return userBalance;
        }
        else {
            cout << "\nWrong choice. Input [1..6], please\n";
            system("pause");
        }
    }
}
bool IsEnought(double price) {
    if (userBalance < price)
    {
        cout << "Lack of funds in the balance sheet." << endl;
        return false;
    }
    else
        return true;
}

double Payment(double price)
{
    return  userBalance - price;
}

void ServiceProcess(int pincode)
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                    ShowServiceMenu();

                    cout << "Insert your choice: ";
                    cin >> servicemanChoise;

                    if (cin.fail() || servicemanChoise < 1 || servicemanChoise > 3)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nWrong Input.\n";
                        system("pause");
                        continue;
                    }

                    switch (servicemanChoise)
                    {
                    case 1:
                        cupCount += AddCups();
                        break;
                    case 2:
                        Withdrow();
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

void ShowServiceMenu()
{
    printf("Balance %.2f BYN\n", boxBalance);
    cout << "Cups: " << cupCount << endl;

    cout << "1) Add cups\n";
    cout << "2) Withdrawal\n";
    cout << "3) Back to Coffee selection\n\n";
}

void Withdrow()
{
    printf("Extracted money from the machine: %.2f BYN\n", boxBalance);
    system("pause");
    boxBalance = 0.0;
}

int AddCups()
{
    ClearConsole();
    int cupNumber = 0;
    cout << "1) Input cups number: ";
    cin >> cupNumber;

    if (cupNumber > 700 || cupNumber < 0)
    {
        cout << "Invalid input.\nMust be in [1 - 700] \n\n";
        system("pause");
        return 0;
    }
    return cupNumber;
}