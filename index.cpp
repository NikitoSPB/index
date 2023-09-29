#include <iostream>
#include <conio.h>

using namespace std;

void sizes()
{
    system("cls");
    cout << "Size of type ""int"": " << sizeof(int) << "\n"
         << "Size of type ""short int"": " << sizeof(short int) << "\n"
         << "Size of type ""long int"": " << sizeof(long int) << "\n"
         << "Size of type ""float"": " << sizeof(float) << "\n"
         << "Size of type ""double"": " << sizeof(double) << "\n"
         << "Size of type ""long double"": " << sizeof(long double) << "\n"
         << "Size of type ""char"": " << sizeof(char) << "\n"
         << "Size of type ""bool"": " << sizeof(bool) << "\n\n"
         << "Press any key";
    _getch();
    system("cls");
}

void binaryInt()
{
    system("cls");
    int intParam;
    unsigned int bites = sizeof(int) * 8, mask = 1 << bites - 1;
    cout << "Enter an int number\n";
    cin >> intParam;
    for (int i = 1; i <= bites; i++)
    {
        putchar(intParam & mask ? '1' : '0');
        intParam <<= 1;
        if (!(i % 8))
            putchar(' ');
        else if (!(i % bites - 1))
            putchar(' ');
    }
    cout << "\n\nPress any key";
    _getch();
    system("cls");
}

void binaryFloat()
{
    system("cls");
    union
    {
        int intFloatParam;
        float floatParam;
    };
    unsigned int bites = sizeof(int) * 8, mask = 1 << bites - 1;
    cout << "Enter an float number\n";
    cin >> floatParam;
    for (int i = 1; i <= bites; i++)
    {
        putchar(intFloatParam & mask ? '1' : '0');
        intFloatParam <<= 1;
        if (i == 1 || i == 2 || i == 9)
            putchar(' ');
    }
    cout << "\n\nPress any key";
    _getch();
    system("cls");
}

void binaryDouble()
{
    system("cls");
    union
    {
        int mass [2];
        double doubleParam;
    };
    unsigned int flag = 0, bites = sizeof(int) * 8, mask = 1 << bites - 1;
    cout << "Enter an double number\n";
    cin >> doubleParam;
    if (!mass[0])
        flag++;
    for (int j = 1; j >= 0; j--)
    {
        for (int i = 1; i <= bites; i++)
        {
            putchar(mass[j] & mask ? '1' : '0');
            mass[j] <<= 1;
            if (j && (i == 1 || i == 2 || i == 12))
                putchar(' ');
        }
    }
    cout << "\n\nPress any key";
    _getch();
    system("cls");
}

void menu()
{
    int itemMenu;
    cout << "What operation you want to perform? Enter a number from 1 to 5:\n"
         << "1 - Output sizes of types\n"
         << "2 - Output the binary representation of an integer\n"
         << "3 - Output the binary representation of an float\n"
         << "4 - Output the binary representation of an double\n"
         << "5 - Exit\n\n";
    cin >> itemMenu;
    switch (itemMenu)
    {
    case 1:
        sizes();
        menu();
        break;
    case 2:
        binaryInt();
        menu();
        break;
    case 3:
        binaryFloat();
        menu();
        break;
    case 4:
        binaryDouble();
        menu();
        break;
    case 5:
        exit(1);
        break;
    default:
        cout << "Error! Repeat, please.";
        _getch();
        menu();
        break;
    }
}

int main()
{
    menu();
    return 0;
}