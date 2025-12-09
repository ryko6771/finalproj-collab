//final project Beck, Kian, and Ryan


#include<iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;
int count=0;
int maxSize = 200;
struct Date {

    int day;      // 1-31

    int month;    // 1-12

    int year;     // 1900-2100

};
struct Transaction {

    string type;            // "Deposit", "Withdrawal", "Transfer"

    float amount;           // Transaction amount

    Date date;              // Transaction date

    string description;     // Transaction description

    string balanceAfter;    // Balance after transaction

};
struct Account {

    int accountNumber;           // Unique auto-generated account number (starts at 100001)

    string accountHolderName;    // Account holder's full name

    string accountType;          // "Savings", "Checking", "Business"

    float balance;               // Current balance

    Date dateOpened;             // Account opening date

    string email;                // Email address (validated)

    string phoneNumber;          // 10-digit phone number (validated)

    string address;              // Mailing address

    bool isActive;               // Active (true) or Closed (false)

    Transaction transactions[50]; // Array of transactions (max 50)

    int transactionCount;        // Number of transactions (0-50)

    float interestRate;          // Interest rate percentage

    string pin;                  // 4-digit PIN
// will make multiple accounts
};

void MmenuFunction(); // main menu function
void menu1Function(); // opening new acc menu(1)
void menu2Function();
int menu3Function();
int menu4Function();
int menu5Function();
int menu6Function();
int menu7Function();
void toggleAccountstatus(Account arr[], int count, int accountNum);
bool addAccount(Account arr[], int &count, int maxSize){ //my question, why bool, what is it used for, i know we need to use it, yet i dont know how, im not sure why count is a reference, is this just to make an account if there is too many accounts?
    //first lets find the iterative acc num system, and then how to add the inputted account struct into the array to store.
    if (count>maxSize){
        return false;
    }

    int accChoice;
    Account newAccount;
    newAccount.accountNumber = 100000+count;
    cout << "\n===== Open New Account =====\n\nSystem Generated Account Number: " << newAccount.accountNumber <<"\n\n\n";
    cout << "Enter Account Holder Name: ";
    cin >> newAccount.accountHolderName;
    cout << "\nSelect Account Type:\n1. Savings\n2. Checking\n3. Business\n\nEnter Choice(1-3): ";
    cin >> accChoice;
    while (accChoice>3 || accChoice<1){
        cout << "Error. Please enter valid choice: ";
        cin >> accChoice;
    }
    if (accChoice == 1){
        newAccount.accountType = "Savings";
        newAccount.interestRate = 2.5;
    }else if (accChoice == 2){
        newAccount.accountType = "Checking";
        newAccount.interestRate = 0.5;
    }else{
        newAccount.accountType = "Business";
        newAccount.interestRate = 1.5;
    }
    cout << "\n\n\nEnter Email: "; //validation of email **this will help with future verification tasks
    cin >> newAccount.email;
    
    for (int i=0; i<newAccount.email.length();i++){//runs a iteration and checks every letter in the input for a match
        int x=0;
        if (newAccount.email[i]=='@'){ //starting by looking for '@'
            for(int j=0; i<newAccount.email.length();j++){ //if '@' is found, then it will loop to search for '.'
                if (newAccount.email[j]=='.'){
                    cout << "\n✓ Valid email format" <<endl; //format validated
                    x++;
                    break; //loop is terminated
                }else if(newAccount.email.length()<4){
                    while(newAccount.email.length()<4){//loop to prevent any smaller emails than 4 char
                        cout << "Email is too short. Please have at least 4 characters(including '@' and '.': ";
                        cin >> newAccount.email;
                    }
                    i=0;
                    j=0;
                    break;
                }else if(newAccount.email[j]!='.'&&j<newAccount.email.length()-1){ //this line of code is to make sure the code does not stop even if it finds a not-matching character at the beginning of the loop. As long as it is not checking the last character, it will keep going by:
                    continue; //this is what allows the skip in iteration
                }else if(j==newAccount.email.length()-1&&newAccount.email[j]!='.'){ //basically checking by the end of loop, when the loop has gone through the entire email, if it still hasn't found the character '.', it will cout the following:
                    cout <<"Invalid. Please include BOTH '@' and '.': ";
                    cin >> newAccount.email;
                    if(newAccount.email.length()<4){
                        while(newAccount.email.length()<4){//loop to prevent any smaller emails than 4 char
                            cout << "Email is too short. Please have at least 4 characters(including '@' and '.': ";
                            cin >> newAccount.email;
                        }
                        i=0;
                    }
                    i=0;//not putting this will cause a bug to accept only a '.' instead of both '@' and '.' because since this part of the code is only accessible if the user inputs something with '@', the code would no longer look for it, so when we ask them to reenter the email, they can omit the '@' and the code would allow it to pass as valid, when it is not.
                    j=0;//restarting the loop, still only looking for '.' since it passed looking for the '@' test
                    //this sends the code back to the original loop that searches for both '@' and '.'
                    break;
                }
            }//for loop with j bracket
            if (x==1){//this prevents the loop from carrying on if it does find the valid format, there needs to be another break so that the outer loop can break, or else it will keep going even if i get it right lol.
                break;
            }
        }else if(newAccount.email[i]!='@'&&i<newAccount.email.length()-1){ //let's say the code did not find '@' on the first iteration, then it would come here. This test will repeat as long as the iteration hasn't reached the last character of the email input.
            continue; // explained previously.
        }else if(i==newAccount.email.length()-1&&newAccount.email[i]!='@'){ //same function as the last one above, except it is still looking for '@'. Now that it reached the end of the iteration and it still hasn't found '@', will restart the entire loop.
            cout << "Invalid. Please include BOTH '@' and '.': ";
            cin >> newAccount.email;
            if(newAccount.email.length()<4){
                while(newAccount.email.length()<4){//loop to prevent any smaller emails than 4 char
                    cout << "Email is too short. Please have at least 4 characters(including '@' and '.': ";
                    cin >> newAccount.email;
                }
                i=0;
            }
            i=0;
        }
    }//for loop i
}


    cout << "\nEnter Phone Number: ";
cin >> newAccount.phoneNumber;
    while (newAccount.phoneNumber.length()>10||newAccount.phoneNumber.length()<10){
        cout << "Invalid Number. Please input exactly ten digits: ";
        cin >> newAccount.phoneNumber;
    }
    //while statement to check phone number
    cout << "\n✓ Valid phone number\nEnter Address: ";
    cin >> newAccount.address//address from array
    cout <<"Enter 4-digit PIN: ";
    cin >> newAccount.pin;//pin from the array
    while (newAccount.pin.length()>4||newAccount.pin.length()<4){
        cout << "Invalid pin. Please enter exactly four digits: ";
        cin >> newAccount.pin;
    }
    cout << "\n✓ Valid PIN\nEnter Initial Deposit (minimum $100.00): ";
    cin >> newAccount.balance;//deposit amount input;
    while (newAccount.balance<100.00){
        cout << "Error. Please deposit $100.00 minimum: ";
        cin >> newAccount.balance;
    }

    cout <<"\n✓ Initial deposit accepted\n";
    int y=0;
    while(y=0)
     cout <<"Enter Account Opening Date (DD MM YYYY): ";
        Date createday; 
        string date;
        cin >> date;//date entry
        int scount=0;
        for (int i=0;i<date.length();i++){
            if(date[i]==' '&&i < 2){
                createday.day = stoi(date.substr(scount,i-scount));
            }else if(date[i]==' '&&i<6){
                createday.month =stoi(date.substr(scount,i-scount));
                createday.year = stoi(date.substr(i+1,date.length() - scount));
            }
            
        }
    }
    cout << "\n\n✓ Account Created Successfully!\nAccount Number: "<<newAccount.number<<"\nAccount Type: "<<accChoice<<"\nInitial Balance: "<<newAccount.balance;<<endl;
    //get Account details here //replace this with the bool function
 
    
         }

    }
    // in matlab ==> function c = addAccount( Account arr[], int &count, int maxSize )
    // returns true or false

}
    
    
    int main() {
        int choice;
        MmenuFunction();
        cout<<"Enter your choice: ";
        cin>>choice;
        // While loop to encourage user to enter number from 1-20 //
        while(choice>20 || choice<1){
            cout<<"Error. Please select a number 1-20: ";
            cin >> choice;
            if (choice == 1){
            if(addAccount(newAccount,count,maxSize)){
                count++;
            }
        }else if (choice == 2){
            menu2Function();
        }else if (choice == 3){
            cout << "three";
        }else if (choice == 4){
            cout << "four";
        }else if(choice == 5){
            cout << "five";
        }else if (choice == 6){
            cout << "six";
        }else if (choice == 7){
            cout << "seven";
        }else if (choice == 8){
            cout << "eight";
        }else if (choice == 9){
            cout << "nine";
        }else if (choice == 10){
            cout << "ten";
        }else if (choice == 11){
            cout << "eleven";
        }else if (choice == 12){
            cout << "twelve";
        }else if (choice == 13){
            cout << "thirteen";
        }else if (choice == 14){
            cout << "fourteen";
        }else if (choice == 15){
            cout << "fifteen";
        }else if (choice == 16){
            cout << "sixteen";
        }else if (choice == 17){
            cout << "seventeen";
        }else if (choice == 18){
            cout << "eighteen";
        }else if (choice == 19){
            cout << "nineteen";
        }else if (choice == 20){
            
            cout << "Exiting Program. Goodbye!" << endl;
            return 0;
        }
     }//while loop
        
        
        return 0;
}


void MmenuFunction() {
    cout<<"========= Bank Account Management System =========\n"<<"                    MAIN MENU\n"<<"====================================================\n\n"<<"        ACCOUNT MANAGEMENT\n"<<"1. Open New Account\n"<<"2. Display All Accounts\n"<<"3. Search Account by Number\n"<<"4. Search Account by Name\n"<<"5. Update Account Information\n"<<"6. Close Account\n"<<"7. Toggle Account Status (Active/Closed)\n\n"<<"        TRANSACTION MANAGEMENT\n"<<"8. Deposit Money\n"<<"9. Withdraw Money\n"<<"10. Transfer Money\n"<<"11. View Transaction History\n"<<"12. Show Interest\n\n"<<"        SORTING & FILTERING\n"<<"13. Sort Accounts by Balance\n"<<"14. Sort Accounts by Name\n"<<"15. Sort Accounts by Account Number\n"<<"16. Filter Accounts by Type\n"<<"17. Filter Accounts by Balance Range\n\n"<<"        DATA MANAGEMENT\n"<<"18. Save All Data\n"<<"19. Load Data from File\n"<<"20. Exit Program\n"<<"====================================================\n";
}
// my idea is that i first make if statements for all the choices skeleton first
void menu1Function() {
   

void menu2Function() {
    cout << "\n========== Display All Accounts ==========\nTotal Accounts: "<<[]<<"\n-------------------------------------------------------------------------\nAccount #    Name            Type        Balance      Status\n\n"<<[]<<"    "<<[]<<"            "<<[]<<"        "<<[]<<"      "<<"\n-------------------------------------------------------------------------\n"
}
int menu3Function(){
    int number;
    cout << "===== Search Account by Number =====\nEnter Account Number: ";
    cin >> number;
    //code that searches array matching
    //boolean
    if (){//account is matched
        cout << "\n\n\n===== Account Found =====\nAccount Number: "<<[]<<"\nAccount Holder: "<<[]<<"\nAccount Type: "<<[]<<"\nBalance: $ "<<[]<<"\nEmail: "<<[]<<"\nPhone: "<<[]<<"\nAddress: "<<[]<<"\nInterest Rate: "<<[]<<"\nDate Opened: "<< []<<"\nStatus: "<<[]<<"\nTotal Transactions: "<<[]<<endl;
    }else{
        while(acccount is not found yet) //what is the code for this? is this even possible?
            cout <<"Error, Account not found, enter again: ";
        cin //loopp thing?
        
    }
}
int menu4Function(){ //requesting a void function for the search
    string name;
    cout << "\n===== Search Account by Name =====\nEnter Account Holder Name: ";
    cin >> name;
    //boolean thingy here to criterion for search
    if(){//search results come true
        cout<<"===== Search Results =====\n";
        //make a while loop for all the results
        while(something something){
            blah blah
            cout << "Account#: "<<[]<< " | Name: "<<[]<< " | Type: "<<[]<<" | Balance: $ "<<[]<<endl;
        }
    }else{
        cout << "Account not found, try again:"//make it loop until it works
    }
    
}
int menu5Function(){ //turns out the instructions wanted a bool function for this as well, redo this.
    int number;
    int choice;
    string uemail;
    string uphone;
    string uadd;
    string upin;
    cout << "\n===== Update Account Information =====\nEnter Account Number: ";
    cin >> number;
    while (number =!the account data){
        cout<<"Account not found, please try again: ";
        cin >> number;
    }
    if(){//check to see if account exists, but lets see if we can just use the loop
        cout <<"Account Found: "<<[]<<"\n\nWhat would you like to update?\n1. Email\n2. Phone Number\n3. Address\n4. PIN\n0. Cancel\n\nEnter Choice: ";
        cin >> choice;
        while (choice > 4 || choice < 0){
            cout<<"Error. Please enter a valid number: ";
            cin >> choice;
         //THIS IS HOW YOU DO A LOOP VALIDATOR WOOHOOO come back to this
        }
        if (choice == 1){
            cout<<"Enter new email: ";
            cin >> uemail;
            //another check to see if email fits the criteria
            cout <<"✓ Email updated Successfully!\n";
        }else if(choice == 2){
            cout<<"Enter new phone number: ";
            cin >> uphone;
            //another check to see if email fits the criteria
            cout <<"✓ Phone number updated successfully!\n";
        }else if(choice == 3){
            cout<<"Enter new address: ";
            cin >> uadd;
            //another check to see if email fits the criteria
            cout <<"✓ Address updated Successfully!\n";
        }else if(choice == 4){
            cout<<"Enter new pin: ";
            cin >> upin;
            //another check to see if email fits the criteria
            cout <<"✓ PIN updated Successfully!\n";
        }else if(choice == 0){
            main();
        }

    }else{
        cout <<"Account not found, try again: ";//find the loop thing or just terminate back to main menu
    }
    main();
}
int menu6Function(){ //turns out for this, we needed a bool function given on the instructions, redo this
    int number;
    char choice;
    cout <<"\n===== Close Account =====\nEnter Account Number: ";
    cin >> number;
    while (number=!anything from the array){
        cout << "Account not found, try again: ";
        cin >> number;
    }
    cout << "\n\nAccount Found: "<<[]<<endl;
    cout << "\nAre you sure you want to close account for "<<[]<<"?(y/n): ";
    cin << choice;
    while (choice !='y'||choice!='Y'||choice!='n'||choice!='N'){
        cout<<"Invalid Answer. Please try again: ";
        cin >> choice;
    }
    if (choice == 'y'||choice == 'Y'){
        //account closing and adjusting the array stuff
        cout <<"✓ Account closed successfully!"<<endl;
    }else if(choice == 'n'||choice=='N'){
        main();
        }
    main();
}
void toggleAccountStatus(){//this is choice 7
    int number;
    char choice
    cout << "\n===== Toggle Account Status =====\nEnter Account Number: ";
    cin >> number;
    //boolean to seek valid acc number
    cout << "Account Found: "<<[]<<endl;
    cout << "Current Status: "<<[]<<endl;
    cout << "Freeze this account? (y/n): ";
    cin >> choice;
    while (choice!=='y'||choice!=='Y'||choice!=='n'||choice!=='N'){
        cout<<"Please enter a choice: ";
        cin >> choice;
    }
    if (choice == 'y'||choice == 'Y'){
        cout << "✓ Account status changed to: "<<[]<<endl;
    }else{
        cout << "Account status maintained."<<endl;
    }
    main();
}



