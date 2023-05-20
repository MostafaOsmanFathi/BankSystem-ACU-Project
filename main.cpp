#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string UserName[10000000];
string Email[10000000];
string Password[10000000];
int Balance[10000000]{0};
short  int year[10000000],month[10000000],day[10000000]; // visa validation date
 int numofAccount{0};


void cridet();
void end_program(); //it will finish the program

int Interface();    //it out the user interface and choice panel and return user choice to the switch

int Login_check();  //it return the index of the account it return x>0 if it the login is right and -1 if password is wrong and -2 if it didn't found the UserName


void creat_account();//creat a new account


bool find_Name(const string& searching_name);//search for name and return true or false if does it exist or not

void Search_for_name();//ask the user to enter a UserName and tell him if does it exist or not


void show_account(const int& index_of_the_account);//by using index of the account print the all user staff like UserName and email and visa expire data

void Deposit(const int& index_of_the_account);//add money to the account of the index that passed as parameter


void Withdraw(const int& index_of_the_account);//substarct money to the account of the index that passed as parameter

void Check_Balance(const int& index_of_the_account);// tell the user it's Balance accsese the Balance from index that is provided in the pramater list

void check_visa_validation(const int& index_of_the_account);   //cheack if the visa has expired or not

void ChangePassword(const int& index_of_the_account);//change password

///======================================================================
int main() {
        cout<<"=============== Welcome to our Bank system============="<<endl;
        cout<<"your the first user and you don't have accounts"<<endl;
        cout<<"if you want to make a new accoutt press (Y,y): ";
            char choice;cin>>choice;
            if (choice=='y'||choice=='Y'){
                    ///=== new user must have a new account===
                     creat_account();
                     ///=======================================
                    bool islocked{true};
                    int current_account_location;
                while (true){
                    cout<<"==============================="<<endl;
                    if (islocked==false){
                        switch (Interface()) {
                            case 1:   Search_for_name();    //search fucntion and tell us what if entered account UserName exsit or not
                                break;
                            case 2:    creat_account();  //creat a New account function
                                break;
                            case 3:   show_account(current_account_location);  //show account fucntion it print all accoutn detetials
                                break;
                            case 4:   Deposit(current_account_location);  //Deposit function add mony to Balance
                                break;
                            case 5:    Withdraw(current_account_location); //Withdrawal function substract mony from Balance and check if it not the taken mony is greater than the mony that do you have or not
                                break;
                            case 6:   Check_Balance(current_account_location);//Check_Balance tell us how much this account have accout
                                break;
                            case 7:     check_visa_validation(current_account_location);//check the visa is valid or not
                                break;
                            case 8:ChangePassword(current_account_location);
                                break;
                            case 9:
                                cout<<"you logged out"<<endl;
                                islocked= true;
                                break;
                            case 10:cridet(); //cridet of the crieator
                                break;
                            case 11:end_program();
                                break;
                            default: cout<<"you entered a wrong command "<<endl;
                        }

                    }else{
                        int CheckTest=Login_check();
                        if (CheckTest>=0){
                            islocked=false;
                            current_account_location=CheckTest;
                            cout<<"welcome "<<UserName[current_account_location]<<" to your account"<<endl;
                            continue;
                        }
                        else if(CheckTest==-2){
                            cout<<"UserName does not exist"<<endl;
                        }
                        else {
                            cout<<"passowrd is worng"<<endl;
                        }
                    }
                }


            }else end_program();

    return 0;
}

void creat_account(){
    cout<<"=========== Creat Account ============"<<endl;
    string UserName2, email, password;
    int balance;
    short int exp_year, exp_month, exp_day;

    cout << "Enter UserName: ";
    cin >> UserName2;

    if (find_Name(UserName2)) {
        cout << "Account already exists!" << endl;

        return;
    }else{cout<<"UserName does not exist you can use it"<<endl;}

    cout << "Enter email: ";
    cin >> email;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter visa expiration date (year month day): ";
    cin >> exp_year >> exp_month >> exp_day;

    UserName[numofAccount] = UserName2;
    Email[numofAccount] = email;
    Password[numofAccount] = password;
    Balance[numofAccount] = balance;
    year[numofAccount] = exp_year;
    month[numofAccount] = exp_month;
    day[numofAccount] = exp_day;

    numofAccount++;
    cout << "Account created successfully!" << endl;

}

bool find_Name(const string& searching_name){
        /// Samuel Malak (task 2)
    // Search for the UserName in the array.
    for (int i = 0; i < numofAccount; i++) {
        if (UserName[i] == searching_name) {
            //if the UserName is exisit return true
            return true;
        }
    }

    // The UserName was not found.
    return false;
}

void Search_for_name(){
    /// Samuel Malak (task 2)
    cout<<"=========== Search For UserName ============"<<endl;

    string searchingName;
    cout << "Enter the UserName to search for: ";
    cin >> searchingName;

    // Check if the UserName is in the list.
    bool found =find_Name(searchingName);

    // Print the result.
    if (found) {
        cout << "The UserName " << searchingName << " was found in the list." << endl;
    }
    else {
        cout << "The UserName " << searchingName << " was not found in the list." << endl;
    }
}


void show_account(const int& index_of_the_account){
    cout<<"=========== show Account ============"<<endl;

        /// muhammad AbdElrahaman (task 3)
        cout << "UserName: " << UserName[index_of_the_account] << endl;
        cout << "Balance: " << Balance[index_of_the_account] << endl;
        cout << "Email: " << Email[index_of_the_account] <<endl;
        cout << "visa validation date: "<<day[index_of_the_account]<<"/"<<month[index_of_the_account]<<"/"<<year[index_of_the_account];
        cout <<endl;
}


void Deposit(const int& index_of_the_account){
    ///Omar maged gomaa (task 4)
    cout<<"=========== Deposit ============"<<endl;

    int amountOfMony;
    cout<< " enter the amount of money you want to deposit :";
    cin>> amountOfMony;
    Balance [index_of_the_account] = (amountOfMony + Balance [index_of_the_account]);
    cout<< "transaction completed and now you have "<<Balance[index_of_the_account]<<"$"<<endl;

}

void Withdraw(const int& index_of_the_account){
    cout<<"========== Withdraw ============="<<endl;

    int amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount ;

    if(amount <= Balance[index_of_the_account]) {
        Balance[index_of_the_account] -= amount;
        cout << "Your current balance is: " << Balance[index_of_the_account] <<"$"<< endl;
    }
    else {
        cout << "Not enough balance." << endl;

    }


}


void Check_Balance(const int& index_of_the_account){
    ///Fady Alber (task 6)
    cout<<"======== Check Balance ============="<<endl;
    cout<<"Your current balance is: "<<Balance[index_of_the_account]<<"$"<<endl;
}
void check_visa_validation(const int& index_of_the_account){
    ///Mostafa Osman (task 7)
    cout<<"======== check visa validation ============="<<endl;
    string monthes[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    time_t now=time(nullptr);// get time current Time in sec
    string timeInString= ::ctime(&now); //make the sec Time to readable string

    int currentYear= stoi(timeInString.substr(timeInString.size()-5,4));//cut the year part from ctime string
    string month_str=timeInString.substr(4,3);//cut the month part from ctime string
    int currentDay= stoi(timeInString.substr(8,2));//cut the Day part from ctime string

    int currentMonth{0};//change the month UserName form UserName to nuber for example jan will be number 1 mar will be number 2
    for (int i = 0; i <12; ++i) {
        if (month_str==monthes[i]) { currentMonth = i + 1;break; }
    }

    //if the visa time is vialed will print that otherwise will print that visa is expaired
    if (currentYear<year[index_of_the_account]||
        currentYear==year[index_of_the_account] && currentMonth<month[index_of_the_account]||
        currentYear==year[index_of_the_account] && currentMonth==month[index_of_the_account] && currentDay<day[index_of_the_account]){
        cout<<"your visa is valiad"<<endl;
    }else{
        cout<<"Your visa is Expired"<<endl;
    }

}
void ChangePassword(const int& index_of_the_account){
    cout<<"======== ChangePassword ============="<<endl;

    cout<<"enter the old password for the user UserName "<<UserName[index_of_the_account]<<": ";
string OldPassword;cin>>OldPassword;
    if (OldPassword==Password[index_of_the_account]){
        cout<<"Correct password"<<endl;
        cout<<"Enter the New Password: ";
        string NewPassword;
        cin>>NewPassword;
        Password[index_of_the_account]=NewPassword;
        cout<<"your Password has changed successfully"<<endl;
    }else{
        cout<<"wrong password"<<endl;
    }

}
///===========================================
void end_program(){
    cout<<endl<<"thanks for using our program"<<endl;
    exit(0);
}



int Interface(){
    cout<<"======== Interface ============="<<endl;

    int choice;
    cout<<"for search for the account UserName  :(1):\n"
          "for creat a New Account :(2):\n"
          "for ShowAccount :(3):\n"
          "for Deposit :(4):\n"
          "for Withdrawal :(5):\n"
          "for showing account balance:(6):\n"
          "for checking the visa is valid or not :(7):\n"
          "for changing password:(8):\n"
          "for logout press :(9):\n"
          "for credit of the creators:(10):\n"
          "to end the program press :(11):\n"
          "enter your choice: ";
    cin>>choice;
    return choice;
}


int Login_check(){
    cout<<"=========== Login ============="<<endl;

    string LUserName, Lpassowrd;
    cout<<"enter your UserName:";cin>>LUserName;
    cout<<"enter your password:";cin>>Lpassowrd;
    if (numofAccount==0)return -2;
    else {
        for (int i = 0; i < numofAccount; ++i) {
            if (LUserName == UserName[i]) {
                if (Lpassowrd == Password[i])return i;
                else return -1;
            }
        }
        return -2;
    }
}
void cridet(){
    cout<<"========= cridet ======================"<<endl;
cout<<"Name: Mostafa Osman Fathi || ID: 42210104\n"
      "Name: Abdulrahman Reda    || ID: 42110115\n"
      "Name: Samuel Malak        || ID: 42210275\n"
      "Name: Omar Maged          || ID: 42210181\n"
      "Name: Muhammad Abdelrahamn|| ID: 42210176\n"
      "Name: Fady Alber          || ID: 42210136\n"
      "Name: Ahmed Haytham       || ID: 42210126\n"
      "Name: Nour Mahmoud        || ID: 42210327\n"
      "==========================================="<<endl;
}