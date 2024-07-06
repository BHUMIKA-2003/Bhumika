#include <string> 
#include <cstdlib> 
#include<iostream>
#include <ctime>
using namespace std;
 
void main_menu();
 
int main()
{
    string name;
    int amt; 
    int betAmount; 
    int g;
    int comp; 
    char options;
 
    cout << "\n____________________________________________________________________________";
    cout << "\n\t\t\t\tNUMBER GUESSING GAME\n";
    cout << "____________________________________________________________________________\n\n";
 
    cout << "Please Enter Your Name: ";
    getline(cin, name);
 
    cout << "Please Deposit amount to play game: ";
    cin >> amt;
    
    do
    {
        system("cls");
        main_menu();
        cout << "\n\nYour current balance is Rs " << amt << "\n";
        do
        {
            cout <<name<<" enter money to bet : Rs";
            cin >> betAmount;
            if(betAmount > amt)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(betAmount > amt);
 
        do
        {
            cout << "Choose a number from 1 to 10 :";
            cin >> g;
            if(g <= 0 || g > 10)
                cout << "Please check again. The number should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(g <= 0 || g > 10);
 
        comp = rand()%10 + 1; 
    
        if(comp == g)
        {
            cout << "\n\nGood Luck! You won Rs" << betAmount * 10;
            amt = amt + betAmount * 10;
        }
        else
        {
            cout << "Better Luck Next Time! You lost Rs "<< betAmount <<"\n";
            amt = amt - betAmount;
        }
 
        cout << "\nThe winning number was : " << comp <<"\n";
        cout << "\n"<<name<<", You have Rs " << amt << "\n";
        if(amt == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\nDo you want to play again (y/n)? ";		
        cin >> options;
    }while(options =='Y'|| options=='y');
    
    cout << "\n";
    cout << "\nThanks for playing game. Your balance amount is Rs " << amt << "\n";
    cout << "___________________________________________________________________";
 
    return 0;
}
 
void main_menu()
{
    system("cls");
    cout << "\n";
    cout << "\t\tInstuctions\n";
    cout << "_____________________________________________________________________________\n";
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times the money you bet\n";
    cout << "\t3. If you bet the wrong number you will lose your betting amount\n";
    cout << "_____________________________________________________________________________\n";
}