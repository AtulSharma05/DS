#include<bits/stdc++.h>
#include <limits> // for clearing input buffer
#include <conio.h> // for _getch()
using namespace std;
void signin_cust();
void displaySecondpage();
void blue()
{
    cout<<"\033[0;34m";
}
void purple()
{
    cout<<"\033[0;35m";
}
void red()
{
    cout<<"\033[0;31m";
}
void green()
{
    cout<<"\033[0;32m";
}
void yellow()
{
    cout<<"\033[0;33m";
}
void reset()
{
    cout<<"\033[0m";
}
void highlight()
{
    cout<<"\033[0;41m";
}

void signin()
{
    system("cls");
    cout<<endl;
    string pnum,pswd; //customer phone number
    cout<<"Enter your ID(Phone number): to SignIn:";
    yellow();
    cin>>pnum;
    reset();
    cout<<"Enter your password: to SignIn:";
    yellow();
    cin>>pswd;
    reset();
    cin.ignore();
    int i=0;
ifstream myfile("cust_file.txt");///here is the file or database which is going to be connected for checking the password

        string first_name, email, phone_no, password ,last_name;
        while (myfile >> first_name >>last_name>>email >>phone_no >> password ) {
            if ((phone_no == pnum)&&(password==pswd)) {
                first_name=first_name+" "+last_name;
                green();
                cout<<"Welcome "<<first_name<<"to the online ticket reservation."<<endl<<"What do you want to go today?";
                reset();
                i=1;
                break;
            }

        }
        if(i==0)
        {cout<<"Invalid credentials."<<endl;
            if((phone_no == pnum)&&(password!=pswd)){
            cout<<"Please enter the correct password."<<endl;}
            signin_cust();

        }

}


void signup() //newuser
{
    system("cls");
    cout<<endl;
    string cust_name,cust_mail,cust_passwd;
    int cust_phone_no;
    cout<<"Hi!Welcome to ONline ticket reservation system :)\nEnter your Full name: ";
    yellow();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,cust_name);
    reset();
    cout<<"Enter your Mail-ID: ";
    yellow();
    cin>>cust_mail;
    reset();
    cout<<"Enter Phone-num:  ";
    yellow();
    cin>>cust_phone_no;
    reset();
    cout<<"Enter Password:";
    yellow();
    cin>>cust_passwd;
    reset();

    //write in file or database
}

void signin_cust() {
    char choice;
    cout << "Incorrect phone number or password. Try again? (Y/N): ";
    cin >> choice;

    switch (choice) {
        case 'Y':
        case 'y':
            signin();
            break;
        case 'N':
        case 'n':
            cout << "Returning to main menu...\n";
            displaySecondpage();
            break;
        default:
            cout << "Invalid choice. Returning to main menu...\n";
            displaySecondpage();
            break;
    }
}
void login_customer()
{

    int signInChoice;
    bool signInValid = false;

    while (!signInValid) {
        green();
        cout<<endl;
        cout << "\t\t\t\t\t -------------------------------------------------------- \n";
        cout << "\t\t\t\t\t|    Press 1 to go to Customer Sign in                   |\n";
        cout << "\t\t\t\t\t|    Press 2 to go to Customer Sign up (New Customer)    |\n";
        cout << "\t\t\t\t\t|    Press 3 to go back                                  |\n";
        cout << "\t\t\t\t\t -------------------------------------------------------- \n\n";
        cout << "\t\t\t\t\tChoice (1/2/3):";
        reset();

        cin >> signInChoice;

        switch (signInChoice) {
            case 1:
                signin();
                signInValid = true;
                break;
            case 2:
                signup();
                signInValid = true;
                signin();
                break;
            case 3:
            displaySecondpage();
            break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a number from given choice(1/2):\n";
                break;
        }
    }
}
void displayFrontPage() {
    system("cls"); // Clear the console screen
    yellow();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "   \t\t\t\t\t --------------------------------------------- \n";
    cout << "   \t\t\t\t\t|                                             | \n";
    cout << "   \t\t\t\t\t|   ---------------------------------------   |\n";
    cout << "   \t\t\t\t\t|  |                                       |  |\n";
    cout << "   \t\t\t\t\t|  |              WELCOME TO               |  |\n";
    cout << "   \t\t\t\t\t|  |                  OTRS                 |  |\n";
    cout << "   \t\t\t\t\t|  |                                       |  |\n";
    cout << "   \t\t\t\t\t|   ---------------------------------------   |\n";
    cout << "   \t\t\t\t\t|                                             |\n";
    cout << "   \t\t\t\t\t --------------------------------------------- \n";
    cout<<endl;
    cout << "   \t\t\t\t\tPress any key to proceed to login: ";
    reset();
}

void displayLoginPage() {
    system("cls"); // Clear the console screen
}
void displaySecondpage(){
    system("cls");

    char loginChoice;
    bool validChoice = false;
while (!validChoice) {
        cout<<endl;
        green();
        cout << "\t\t\t\t\t -------------------------------------------------------- \n";
        cout << "\t\t\t\t\t|                                                        |\n";
        cout << "\t\t\t\t\t|             Enter c for Customer Login page            |\n";
        cout << "\t\t\t\t\t|                                                        |\n";
        cout << "\t\t\t\t\t -------------------------------------------------------- \n\n";
        cout << "\t\t\t\t\tChoice (c):";
        reset();
        cin >> loginChoice;
        // Check if the input is not alphabetic
        if (!isalpha(loginChoice)) {
            // Clear the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a letter from given choice(c/s):\n";
        } else {
            switch (loginChoice) {
                case 'c':
                case 'C':
                    validChoice = true;
                    displayLoginPage();
                    login_customer();
                    break;
                default:
                    cout << "Enter a letter from given choice(c/s):\n";
                    break;
            }
        }
    }
 }
 int main() {
    char choice;
    displayFrontPage();
    _getch(); // Wait for a key press
    displayLoginPage();
    displaySecondpage();

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;

}
