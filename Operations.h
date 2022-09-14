#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include"Transaction.h"
using namespace std;

/**
 * @desc - Operations Class deals with all the operation functions related to
 *         Banking like Opening an Account, Displaying all Accounts, 
 *         Deleting Account, Transactions, Updating Accounts Information,
 *         Calculating Interest, Searching for particular account and displaying
 *         all of its information like Account details Customer Details and Transaction 
 * 
 * @params - {Object} Customerobj-(RunnerFilesCustomer Object)
 * @params - {Object} Transactionobj-(RunnerFilesTransaction Object)
 *  
 */
class Operations{
    protected:
    RunnerFilesCustomer Customerobj;
    RunnerFilesTransaction Transactionobj;

    public:
    Operations(){}
    void createAccount(){
        cout << "\n\n\t\t" << "----------- Creating Account -----------";
        Customerobj.createAccount();
        cout << "\n\n\t\t" << "----------- Account is created -----------";
    }

    void displayAllInfo(){
        cout << "\n\n\t\t" << "----------- Display Accounts -----------";
        Customerobj.displayAllInfo();
        cout << "\n\n\t\t" << "----------- Displayed Accounts -----------";
    }

    void deleteAccount(){
        cout << "\n\n\t\t" << "----------- Delete Account -----------";
        Customerobj.deleteAccount();
        cout << "\n\n\t\t" << "----------- Account Deleted -----------";
    }

    void transaction(){
        cout << "\n\n\t\t" << "----------- Transaction -----------";
        Transactionobj.generateTransaction();
        cout << "\n\n\t\t" << "----------- Transaction Completed-----------";
    }

    void lastAccountInfo(){
        cout << "\n\n\t\t" << "----------- Display Last Account -----------";
        Customerobj.lastAccountInfo();
        cout << "\n\n\t\t" << "----------- Last Account Displayed -----------";
    }

    void checkAccount(){
        cout << "\n\n\t\t" << "----------- Check Account -----------";
        Customerobj.searchAccount();
        cout << "\n\n\t\t" << "----------- Account Checked -----------";

    }

    void updateInfo(){
        cout << "\n\n\t\t" << "----------- Update Information -----------";
        Customerobj.updateInformation();
        cout << "\n\n\t\t" << "----------- Information Updated -----------";
    }

    void accountAllInfo(){
        cout << "\n\n\t\t" << "----------- Display all Info of Account -----------";
        Transactionobj.displayInfo();
        cout << "\n\n\t\t" << "----------- Info Displayed -----------";
    }

    void interestInfo(){
        cout << "\n\n\t\t" << "----------- Calculate Interest -----------";
        Transactionobj.interest(); 
        cout << "\n\n\t\t" << "----------- Interest Calculated -----------";
    }

    /**
     * @desc - updateBankCodes function is used to update the BankCodes file acc. to
     *         the last account number, last customer id, last transaction id at the end of
     *         the program
     *  
     */
    void updateBankCodes(){
        Customer tempCus = lastCustomer<Customer>();
        Transaction tempTrans = lastTransaction<Transaction>();
        setBankCodes(tempCus.getObj().getAccountNo(),tempCus.getCustomerID(),tempTrans.getTransactionID());
    }


};