#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include"Operations.h"
using namespace std;

int main(){
    cout << "\n\n\t\t" << "----------- Welcome to the Bank -----------";
    int choice;
    bool check = true;
    Operations O1;
    do{
        cout << "\n\n\t\t" << "1. Open an account";
        cout << "\n\n\t\t" << "2. Display All accounts";
        cout << "\n\n\t\t" << "3. Delete account";
        cout << "\n\n\t\t" << "4. Transaction";
        cout << "\n\n\t\t" << "5. Last entry info";
        cout << "\n\n\t\t" << "6. Check account";
        cout << "\n\n\t\t" << "7. Update Infomation";
        cout << "\n\n\t\t" << "8. Account Info";
        cout << "\n\n\t\t" << "9. Interest";
        cout << "\n\n\t\t" << "10. Exit";
        cout << "\n\n\t\t" << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            cout << "\n\n\t\t" << "Open an account";
            O1.createAccount();
            break;

            case 2:
            cout << "\n\n\t\t" << "Display All accounts";
            O1.displayAllInfo();
            break;

            case 3:
            cout << "\n\n\t\t" << "Delete account";
            O1.deleteAccount();
            break;

            case 4:
            cout << "\n\n\t\t" << "Transaction";
            O1.transaction();
            break;

            case 5:
            cout << "\n\n\t\t" << "Last entry info";
            O1.lastAccountInfo();
            break;

            case 6:
            cout << "\n\n\t\t" << "Check account";
            O1.checkAccount();
            break;

            case 7:
            cout << "\n\n\t\t" << "Update Infomation";
            O1.updateInfo();
            break;

            case 8:
            cout << "\n\n\t\t" << "Account Infomation";
            O1.accountAllInfo();
            break;

            case 9:
            cout << "\n\n\t\t" << "Interest";
            O1.interestInfo();
            break;

            case 10:
            O1.updateBankCodes();
            cout << "\n\n\t\t" << "----------- Thank You for Visiting Have a Nice Day -----------" << "\n\n";
            check = false;
            break;

            default:
            cout << "\n\n\t\t" << "Invalid Choice Choose a Correct Option.";
            break;
        }
    }while(check);
    return 0;
}