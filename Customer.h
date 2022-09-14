#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include"Account.h"
using namespace std;

/**
 * @desc - getCustomerID function is explained in in the FileFunction.h file
 * 
 */
static int CustomerNum = getCustomerID<int>();

/**
 * @desc - Customer Class deals with all the Parameters related
 *         to Customer information it has several Parameters
 *         and functions
 * 
 * @params - {Char Array} CustomerName-(Name of the Customer or Account Holder)
 * @params - {Number} CustomerID-(ID of the Customer or Account Holder)
 * @params - {Number} PhoneNo-(Phone Number of the Customer or Account Holder)
 * @params - {Char Array} Address-(Address of the Customer or Account Holder)
 * @params - {Object} accountObj-(Account Object of the Customer or Account Holder)
 *  
 */
class Customer{
    protected:
    char CustomerName[50];
    int CustomerID;
    unsigned long long PhoneNo;
    char Address[100];
    Account accountObj;

    public:
    /**
     * @desc - Empty Constructor
     * 
     */
    Customer(){}

    /**
     * @desc - Parameterized Constructor
     * 
     */
    Customer(string custName, unsigned long long custPhoneNo, string custAddress, Account a){
        strcpy(CustomerName, custName.c_str());
        CustomerNum++;
        CustomerID = CustomerNum;
        PhoneNo = custPhoneNo;
        strcpy(Address, custAddress.c_str());
        accountObj = a;
    }

    /**
     * @desc - getCustomerName function will return Customer Name
     * 
     * @returnss - {Char Pointer} Return pointer to CustomerName
     * 
     */
    char* getCustomerName(){
        return CustomerName;
    }

    /**
     * @desc - setCustomerName function will set value of Customer Name
     * 
     * @params - {String} newName
     * 
     */
    void setCustomerName(string newName){
        strcpy(CustomerName, newName.c_str());
    }

    /**
     * @desc - getCustomerID function will return Customer ID
     * 
     * @returnss - {Number} Return value of CustomerID
     * 
     */
    int getCustomerID(){
        return CustomerID;
    }

    /**
     * @desc - getPhoneNo function will return Phone Number
     * 
     * @returnss - {Number} Return value of PhoneNo
     * 
     */
    unsigned long long getPhoneNo(){
        return PhoneNo;
    }

    /**
     * @desc - setPhoneNo function will set value of Phone Number
     * 
     * @params - {Number} newNum
     * 
     */
    void setPhoneNo(unsigned long long newNum){
        PhoneNo = newNum;
    }

    /**
     * @desc - getAddress function will return Address
     * 
     * @returnss - {Char Pointer} Return pointer to Address
     * 
     */
    char* getAddress(){
        return Address;
    }

    /**
     * @desc - setAddress function will set value of Address
     * 
     * @params - {String} newAddress
     * 
     */
    void setAddress(string newAddress){
        strcpy(Address, newAddress.c_str());
    }

    /**
     * @desc - getObj function will return Object of Account
     * 
     * @returnss - {Object} Return Object of accountObj
     * 
     */
    Account getObj(){
        return accountObj;
    }

    /**
     * @desc - setObjAmount function will set value of accountObj Parameter Amount
     * 
     * @params - {Number} newAm
     * 
     */
    void setObjAmount(unsigned long long newAm){
        accountObj.setAmount(newAm);
    }

    /**
     * @desc - setObjInterest function will set value of accountObj Parameter Interest
     * 
     * @params - {Number} newInterest
     * 
     */
    void setObjInterest(float newInterest){
        accountObj.setInterest(newInterest);
    }

    /**
     * @desc - info function will print values of Customer Details
     *         & Customer's Account Details
     * 
     */
    void info(){
        cout << "\n\n\t\t" << "Name of Account Holder: " << CustomerName;
        cout << "\n\t\t" << "ID of Account Holder: " << CustomerID;
        cout << "\n\t\t" << "PhoneNo. of Account Holder: " << PhoneNo;
        cout << "\n\t\t" << "Address of Account Holder: " << Address;
        cout << "\n\t\t" << "AccountNo. of Account Holder: " << accountObj.getAccountNo();
        cout << "\n\t\t" << "Status of Account of Account Holder: " << accountObj.getAccountStatus();
        cout << "\n\t\t" << "Type of Account of Account Holder: " << accountObj.getAccountType();
        cout << "\n\t\t" << "Amount in Account of Account Holder: " << accountObj.getAmount();
        cout << "\n\t\t" << "Interest in Account of Account Holder: " << accountObj.getInterest() << "%";
    }
    
};

/**
 * @desc - RunnerFilesCustomer Class deals with all the operations
 *         related to Customer information it has several functions
 *         like - createAccount, displayAllInfo, deleteAccount, 
 *         lastAccountInfo, searchAccount, updateInformation
 *  
 */
class RunnerFilesCustomer{
    public:
    /**
     * @desc - Empty Constructor
     * 
     */
    RunnerFilesCustomer(){}

    /**
     * @desc - createAccount function will deal with creation of Account it
     *         will ask user for Name, Phone Number, Address, Account Type
     *         and Amount
     *  
     */
    void createAccount(){
        string name, address, accType;
        unsigned long long phoneno, amount;
        int choice;
        bool checker1=true, checker2=true, checker3=true;
        cout << "\n\n\t\t" << "Name of the Customer: ";
        cin.ignore();
        getline(cin,name);
        do{
            cout << "\n\t\t" << "Customer Phone Number: ";
            cin >> phoneno;
            if(to_string(phoneno).length()==10){
                checker3 = false;
            }
            else{
                cout << "\n\t\t" << "Entered Number is Invalid. Try again";
            }
        }while(checker3);
        cout << "\n\t\t" << "Customer Address: ";
        cin.ignore();
        getline(cin,address);
        do{
            cout << "\n\t\t" << "Types of Account: ";
            cout << "\n\t\t" << "1. Current Account";
            cout << "\n\t\t" << "2. Saving Account";
            cout << "\n\t\t" << "3. Joint Account";
            cout << "\n\n\t\t" << "Enter your Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                cout << "\n\t\t" << "Current Account";
                checker1 = false;
                accType = "Current";
                break;

                case 2:
                cout << "\n\t\t" << "Saving Account";
                checker1 = false;
                accType = "Saving";
                break;

                case 3:
                cout << "\n\t\t" << "Joint Account";
                checker1 = false;
                accType = "Joint";
                break;

                default:
                cout << "\n\t\t" << "Invalid Option. Try Again";
                break;
            }
        }while(checker1);
        cout << "\n\n\t\t" << "Minimum Amount required to Open an account: Rs. 1000";
        do{
            cout << "\n\t\t" << "Enter Amount: Rs.";
            cin >> amount;
            if(amount>=1000){
                checker2 = false;
            }
            else{
                cout << "\n\t\t" << "Entered Amount is less then Minimum Amount. Please Enter the amount again.";
            }
        }while(checker2);

        /**
         * @desc - Account Parametrized Constructor
         * 
         * @params - {String} accStatus
         * @params - {String} accType
         * @params - {Number} amount
         * 
         */
        Account A1("Active",accType,amount);

        /**
         * @desc - Customer Parametrized Constructor
         * 
         * @params - {String} name
         * @params - {Number} phoneno
         * @params - {String} address
         * @params - {Object} A1-(Account Object)
         * 
         */
        Customer C1(name,phoneno,address,A1);

        /**
         * @desc - createAcc function is explained in in the FileFunction.h file
         * 
         * @params - {Object} C1-(Customer Object)
         * 
         */
        createAcc<Customer>(C1);

    }

    /**
     * @desc - displayAllInfo function is used to display all details
     *         of all the Customers and their Accounts
     *  
     */
    void displayAllInfo(){

        /**
         * @desc - readAll function is explained in in the FileFunction.h file
         * 
         */
        readAll<Customer>();
    }

    /**
     * @desc - deleteAccount function is used to delete all details
     *         of a Customer and Customer's account acc. to the Account Number
     *         mwntioned by the user inside the function 
     *  
     */
    void deleteAccount(){
        long long findAccount;
        cout << "\n\n\t\t" << "Enter the Account Number: ";
        cin >> findAccount;

        /**
         * @desc - del function is explained in in the FileFunction.h file
         * 
         * @params - {Number} findAccount-(Account Number)
         * 
         */
        del<Customer>(findAccount);
    }

    /**
     * @desc - lastAccountInfo function is used to fetch the
     *         details of the last account that was created
     *  
     */
    void lastAccountInfo(){

        /**
         * @desc - readLast function is explained in in the FileFunction.h file
         * 
         */
        readLast<Customer>();
    }

    /**
     * @desc - searchAccount function is used to find whether the account is present 
     *         in the Bank or not so user will provide Account Number and program 
     *         will look for the Account related to that Account Number
     *  
     */
    void searchAccount(){
        long long findAccount;
        cout << "\n\n\t\t" << "Enter the Account Number: ";
        cin >> findAccount;

        /**
         * @desc - search function is explained in in the FileFunction.h file
         * 
         * @params - {Number} findAccount-(Account Number)
         * 
         */
        if(search<Customer>(findAccount)){
            cout << "\n\n\t\t" << "Account is present in Database";
        }
        else{
            cout << "\n\n\t\t" << "Account is not present in Database";
        }
    }

    /**
     * @desc - updateInformation function is used to Update Cutomer's
     *         Information like Customer's Name, Phone number and Address
     *         program will ask the user what the user wants to update and after
     *         that it will take input from user accordingly
     *  
     */
    void updateInformation(){
        int choice;
        long long accNum;
        unsigned long long newNum;
        string newName, newAddress;
        bool checker = true, checker2 = true;
        do{
            cout << "\n\n\t\t" << "Information want to Update: ";
            cout << "\n\n\t\t" << "1. Update Account Holder Name";
            cout << "\n\t\t" << "2. Update Account Holder Phone Number";
            cout << "\n\t\t" << "3. Update Account Holder Address";
            cout << "\n\n\t\t" << "Enter your choice: ";
            cin >> choice;
            switch(choice){
                case 1:
                cout << "\n\t\t" << "Update Account Holder Name";
                cout << "\n\n\t\t" << "Enter Account Number: ";
                cin >> accNum;

                /**
                 * @desc - searchAcc function is explained in in the FileFunction.h file
                 * 
                 * @params - {Number} accNum-(Account Number)
                 * 
                 */
                if(searchAcc<Customer>(accNum)){
                    cout << "\n\t\t" << "Enter New Name: ";
                    cin.ignore();
                    getline(cin,newName);
                    /**
                     * @desc - updateNumber function is explained in in the FileFunction.h file
                     * 
                     * @params - {Number} accNum-(Account Number)
                     * @params - {String} newName-(Name)
                     * 
                     */
                    updateName<Customer>(accNum, newName);
                    checker = false;
                }
                else{
                   cout << "\n\n\t\t" << "Account is not present in Database"; 
                }
                break;

                case 2:
                cout << "\n\t\t" << "Update Account Holder Phone Number";
                cout << "\n\n\t\t" << "Enter Account Number: ";
                cin >> accNum;

                /**
                 * @desc - searchAcc function is explained in in the FileFunction.h file
                 * 
                 * @params - {Number} accNum-(Account Number)
                 * 
                 */
                if(searchAcc<Customer>(accNum)){
                    do{
                        cout << "\n\t\t" << "Enter New Phone Number: ";
                        cin >> newNum;
                        if(to_string(newNum).length()==10){
                            /**
                             * @desc - updateNumber function is explained in in the FileFunction.h file
                             * 
                             * @params - {Number} accNum-(Account Number)
                             * @params - {Number} newNum-(Phone Number)
                             * 
                             */
                            updateNumber<Customer>(accNum, newNum);
                            checker = false;
                            checker2 = false;
                        }
                        else{
                            cout << "\n\t\t" << "Entered Number is Invalid. Try again";
                        }
                    }while(checker2);
                }
                else{
                   cout << "\n\n\t\t" << "Account is not present in Database"; 
                }
                break;

                case 3:
                cout << "\n\t\t" << "Update Account Holder Address";
                cout << "\n\n\t\t" << "Enter Account Number: ";
                cin >> accNum;

                /**
                 * @desc - searchAcc function is explained in in the FileFunction.h file
                 * 
                 * @params - {Number} accNum-(Account Number)
                 * 
                 */
                if(searchAcc<Customer>(accNum)){
                    cout << "\n\t\t" << "Enter New Address: ";
                    cin.ignore();
                    getline(cin,newAddress);
                    /**
                     * @desc - updateAddress function is explained in in the FileFunction.h file
                     * 
                     * @params - {Number} accNum-(Account Number)
                     * @params - {String} newAddress-(Address)
                     * 
                     */
                    updateAddress<Customer>(accNum, newAddress);
                    checker = false;
                }
                else{
                   cout << "\n\n\t\t" << "Account is not present in Database"; 
                }
                break;

                default:
                cout << "\n\t\t" << "Invalid Option. Try Again";
                break;
            }

        }while(checker);
    }


};