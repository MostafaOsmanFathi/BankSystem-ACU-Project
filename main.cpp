#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

string *Name=new string[1];
string *Email=new string[1];
string *Password=new string[1];
int *Balnce=new int[1];
int numofAccount{0};
/**
string *Visa_Time=new string [1];
*/

///finshed function pls don't edit it or just tell (Mostafa Osman) or the leader  (Abdel Rhman)
void cridet();
void end_program();
//it will finish the program

int Interface();//it out the user interface and choice panel and return user choice to the switch

int Login_check();
//it return the index of the account it return x>0 if it the login is right and -1 if password is wrong and -2 if it didn't found the name
///=====================================================================
///================================== Needed function ==================
void creat_account();
/**ask the user for his info like name and email and password and all of these staff
 * and add the new account to the last index by num of account and don't forget to increment the numofAccount by one
 * */

void search_for_name();//ask the user to enter a name and tell him if does it exsit or not

void show_account(int index_of_the_account);//by using index of the account print the all user staff like name and email and visa expire data

void Deposit(int index_of_the_account);
/**it will go balnce of the index that in the pramterlist
 * and ask the user for the amount that he want to add and then add the mony
 * */

void Withdraw(int index_of_the_account);
/**check if the mony amount that the user want to take is greater than of the account or not
 * and if the accunt has enough mony substract the mony from it's balnce if not tell him not enough mony
 * */

void Check_Balance(int index_of_the_account);// tell the user it's balnce accsese the balnce from index that is provided in the pramater list

void check_visa_validation();   //cheack if the visa has expired or not



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
                            case 1:   search_for_name();    //search fucntion and tell us what if entered account name exsit or not
                                break;
                            case 2:    creat_account();  //creat a New account function
                                break;
                            case 3:   show_account(current_account_location);  //show account fucntion it print all accoutn detetials
                                break;
                            case 4:   Deposit(current_account_location);  //Deposit function add mony to balnce
                                break;
                            case 5:    Withdraw(current_account_location); //Withdrawal function substract mony from balnce and check if it not the taken mony is greater than the mony that do you have or not
                                break;
                            case 6:   Check_Balance(current_account_location);//Check_Balance tell us how much this account have accout
                                break;
                            case 7:check_visa_validation();//check the visa is valid or not
                                break;
                            case 8:
                            case 9:
                                islocked= false;
                                break;
                            case 10:cridet(); //cridet of the crieator
                                break;
                            case 11:end_program();
                                break;
                            default: cout<<"you entered a wrong command "<<endl;
                        }


                    }else{
                        int x=Login_check();
                        if (x>=0){
                            islocked=false;
                            current_account_location=x;
                            cout<<"welcome "<<Name[current_account_location]<<" to your account"<<endl;
                            continue;
                        }
                        else if(x==-2){
                            cout<<"Name does not exist"<<endl;
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
/**
* task 1
*/
    Name[0]="mostafa";
    Password[0]="osman";
    numofAccount++;

}

void search_for_name(){

/**
*task 2
*/

}


void show_account(int index_of_the_account){

/**
*task 3
*/

}


void Deposit(int index_of_the_account){

/**
*task 4
*/

}

void Withdraw(int index_of_the_account){

/**
*task 5
*/

}


void Check_Balance(int index_of_the_account){
/**
*task 6
*/

}
void check_visa_validation(){

/**
*task 7
*/

}
///===========================================
void end_program(){
    cout<<endl<<"thanks for using our program"<<endl;
    delete [] Name;
    delete [] Email;
    delete [] Password;
    ///delete [] Visa_Time;
    delete [] Balnce;
    exit(0);
}



int Interface(){
    int choice;
    cout<<"for search for the account Name  :(1):"<<endl;
    cout<<"for creat a New Account :(2):"<<endl;
    cout<<"for ShowAccount :(3):"<<endl;
    cout<<"for Deposit :(4):"<<endl;
    cout<<"for Withdrawal :(5):"<<endl;
    cout<<"for showing account balance:(6):"<<endl;
    cout<<"for checking the visa is valid or not :(7):"<<endl;
    cout<<"for login to another account :(8):"<<endl;
    cout<<"for logout press :(9):"<<endl;
    cout<<"for credit of the creators:(10):"<<endl;
    cout<<"to end the program press :(11):"<<endl;
    cout<<"enter your choice: ";
    cin>>choice;
    return choice;
}




int Login_check(){
    string LUserName, Lpassowrd;
    cout<<"enter your name:";cin>>LUserName;
    cout<<"enter your password:";cin>>Lpassowrd;
    if (numofAccount==0)return -2;
    else {
        for (int i = 0; i < numofAccount; ++i) {
            if (LUserName == Name[i]) {
                if (Lpassowrd == Password[i])return i;
                else return -1;
            }
        }
        return -2;
    }
}
void cridet(){
    // every one write it's name and ID here pls
    cout<<"Name: Mostafa Osman || ID:42210104"<<endl;
}