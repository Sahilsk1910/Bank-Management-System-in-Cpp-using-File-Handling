#include<iostream>
#include<stdio.h>
#include<ctime>
#include<bits/stdc++.h>
#include"Customer.h"
#include"TimeFunctions.h"
using namespace std;

/**
 * @desc - getTransactionID function is explained in in the FileFunction.h file
 * 
 */
static long long TransactionNum = getTransactionID<long long>();

/**
 * @desc - Transaction Class deals with all the Parameters related
 *         to Transaction made by Customers it has several Parameters
 *         and functions
 * 
 * @params - {Number} TransactionID-(Transaction ID of the Transaction)
 * @params - {Char Array} TransactionType-(Type of the Transaction)
 * @params - {Number} TransactionAmount-(Transaction Amount)
 * @params - {Char Array} TransactionTime-(Time of Transaction)
 * @params - {Object} customerObj-(Customer Object of the Customer or Account Holder who made Transaction)
 *  
 */
class Transaction{
    protected:
    long long TransactionID;
    char TransactionType[20];
    unsigned long long TransactionAmount;
    char TransactionTime[30];
    Customer customerObj;


    public:
    /**
     * @desc - Empty Constructor
     * 
     */
    Transaction(){}

    /**
     * @desc - Parameterized Constructor
     * 
     */
    Transaction(string transType, unsigned long long transAmount, string time, Customer c){
        TransactionNum++;
        TransactionID = TransactionNum;
        strcpy(TransactionType, transType.c_str());
        TransactionAmount = transAmount;
        strcpy(TransactionTime,time.c_str());
        customerObj = c;
    }

    /**
     * @desc - getTransactionID function will return Transaction ID
     * 
     * @returnss - {Number} Return value of TransactionID
     * 
     */
    long long getTransactionID(){
        return TransactionID;
    }

    /**
     * @desc - getTransactionTime function will return Transaction Time
     * 
     * @returnss - {Char Pointer} Return pointer to TransactionTime
     * 
     */
    char* getTransactionTime(){
        return TransactionTime;
    }

    /**
     * @desc - getCustomerObj function will return Object of Customer
     * 
     * @returnss - {Object} Return Object of customerObj
     * 
     */
    Customer getCustomerObj(){
        return customerObj;
    }

    /**
     * @desc - info function will print values of Transaction Details
     *         & Customer's Account Details
     * 
     */
    void info(){
        cout << "\n\n\t\t" << "Trasaction ID: " << TransactionID;
        cout << "\n\t\t" << "Transaction Type: " << TransactionType;
        cout << "\n\t\t" << "Transaction Amount: " << TransactionAmount;
        cout << "\n\t\t" << "Name of Account Holder: " << customerObj.getCustomerName();
        cout << "\n\t\t" << "Account no. of Account Holder: " << customerObj.getObj().getAccountNo();
        if(strcmp(TransactionType,"Withdraw")==0 || strcmp(TransactionType,"Transfer(Withdraw)")==0){
            cout << "\n\t\t" << "Amount in Account Before Transaction: " << customerObj.getObj().getAmount()+TransactionAmount;
        }
        else{
            cout << "\n\t\t" << "Amount in Account Before Transaction: " << customerObj.getObj().getAmount()-TransactionAmount;
        }
        cout << "\n\t\t" << "Amount in Account After Transaction: " << customerObj.getObj().getAmount();
        cout << "\n\t\t" << "Time of Transaction: " << TransactionTime;
    }
};

/**
 * @desc - RunnerFilesTransaction Class deals with all the operations
 *         related to Transaction information it has several functions
 *         like - generateTransaction, displayInfo, interest
 *  
 */
class RunnerFilesTransaction{
    public:
    /**
     * @desc - Empty Constructor
     * 
     */
    RunnerFilesTransaction(){}

    /**
     * @desc - generateTransaction function will deal with the Transactions
     *         it will ask the user for Transaction Type, Account Number and
     *         Transaction Amount
     *  
     */
    void generateTransaction(){
        string transactionType;
        long long transactionAccount;
        unsigned long long transactionAmount;
        int choice;
        bool checker1 = true;
        do{
            cout << "\n\n\t\t" << "Enter the Type of Transaction: ";
            cout << "\n\t\t" << "1. Withdraw";
            cout << "\n\t\t" << "2. Deposit";
            cout << "\n\t\t" << "3. Transfer";
            cout << "\n\n\t\t" << "Enter your Choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1:
                cout << "\n\t\t" << "Withdraw Transaction";
                checker1 = false;
                transactionType = "Withdraw";
                cout << "\n\n\t\t" << "Enter Account Number: ";
                cin >> transactionAccount;
                if(searchAcc<Customer>(transactionAccount)){
                    cout << "\n\t\t" << "Enter the Amount: ";
                    cin >> transactionAmount;
                    /**
                     * @desc - checkAmount function is explained in in the FileFunction.h file
                     * 
                     * @params - {Number} transactionAccount-(Account Number)
                     * @params - {Number} transactionAmount-(Transaction Amount)
                     * 
                     */
                    if(checkAmount<Customer>(transactionAccount, transactionAmount)){
                        /**
                         * @desc - getCustomer function is explained in in the FileFunction.h file
                         * 
                         * @params - {Number} transactionAccount-(Account Number)
                         * @returnss - {Object} Customer Object
                         * 
                         */
                        Customer tempCustomer = getCustomer<Customer>(transactionAccount);
                        tempCustomer.setObjAmount(tempCustomer.getObj().getAmount()-transactionAmount);
                        /**
                         * @desc - updateObj function is explained in in the FileFunction.h file
                         * 
                         * @params - {Number} transactionAccount-(Account Number)
                         * @params - {Object} tempCustomer-(Customer Object)
                         * 
                         */
                        updateObj<Customer>(transactionAccount, tempCustomer);
                        tempCustomer = getCustomer<Customer>(transactionAccount);
                        time_t now = time(0);
                        char* dt = ctime(&now);
                        string time = dt;

                        /**
                         * @desc - Transaction Parametrized Constructor
                         * 
                         * @params - {String} transactionType
                         * @params - {Number} transactionAmount
                         * @params - {String} time
                         * @params - {Object} tempCustomer-(Customer Object)
                         * 
                         */
                        Transaction T1(transactionType, transactionAmount, time, tempCustomer);
                        /**
                         * @desc - createTrans function is explained in in the FileFunction.h file
                         * 
                         * @params - {Object} T1-(Transaction Object)
                         * 
                         */
                        createTrans<Transaction>(T1);
                    }
                    else{
                        cout << "\n\n\t\t" << "Insufficient Balance.";
                    }
                }
                else{
                    cout << "\n\n\t\t" << "Account is not present in Database";
                }
                break;

                case 2:
                cout << "\n\t\t" << "Deposit Transaction";
                checker1 = false;
                transactionType = "Deposit";
                cout << "\n\n\t\t" << "Enter Account Number: ";
                cin >> transactionAccount;
                if(searchAcc<Customer>(transactionAccount)){
                    cout << "\n\t\t" << "Enter the Amount: ";
                    cin >> transactionAmount;
                    /**
                     * @desc - getCustomer function is explained in in the FileFunction.h file
                     * 
                     * @params - {Number} transactionAccount-(Account Number)
                     * @returnss - {Object} Customer Object
                     * 
                     */
                    Customer tempCustomer = getCustomer<Customer>(transactionAccount);
                    tempCustomer.setObjAmount(tempCustomer.getObj().getAmount()+transactionAmount);
                    /**
                     * @desc - updateObj function is explained in in the FileFunction.h file
                     * 
                     * @params - {Number} transactionAccount-(Account Number)
                     * @params - {Object} tempCustomer-(Customer Object)
                     * 
                     */
                    updateObj<Customer>(transactionAccount, tempCustomer);
                    tempCustomer = getCustomer<Customer>(transactionAccount);
                    time_t now = time(0);
                    char* dt = ctime(&now);
                    string time = dt;

                    /**
                     * @desc - Transaction Parametrized Constructor
                     * 
                     * @params - {String} transactionType
                     * @params - {Number} transactionAmount
                     * @params - {String} time
                     * @params - {Object} tempCustomer-(Customer Object)
                     * 
                     */
                    Transaction T1(transactionType, transactionAmount, time, tempCustomer);
                    /**
                     * @desc - createTrans function is explained in in the FileFunction.h file
                     * 
                     * @params - {Object} T1-(Transaction Object)
                     * 
                     */
                    createTrans<Transaction>(T1);
                }
                else{
                    cout << "\n\n\t\t" << "Account is not present in Database";
                }
                break;

                case 3:
                cout << "\n\t\t" << "Transfer Transaction";
                checker1 = false;
                long long transactionAccount2;
                cout << "\n\n\t\t" << "From: ";
                cout << "\n\t\t" << "Enter Account Number: ";
                cin >> transactionAccount;
                if(searchAcc<Customer>(transactionAccount)){
                    cout << "\n\n\t\t" << "To: ";
                    cout << "\n\t\t" << "Enter Account Number: ";
                    cin >> transactionAccount2;
                    if(searchAcc<Customer>(transactionAccount2)){
                        cout << "\n\t\t" << "Enter the Amount: ";
                        cin >> transactionAmount;
                        if(checkAmount<Customer>(transactionAccount, transactionAmount)){
                            /**
                             * @desc - getCustomer function is explained in in the FileFunction.h file
                             * 
                             * @params - {Number} transactionAccount-(Account Number)
                             * @returnss - {Object} Customer Object
                             * 
                             */
                            Customer tempCustomer1 = getCustomer<Customer>(transactionAccount);
                            Customer tempCustomer2 = getCustomer<Customer>(transactionAccount2);
                            tempCustomer1.setObjAmount(tempCustomer1.getObj().getAmount()-transactionAmount);
                            tempCustomer2.setObjAmount(tempCustomer2.getObj().getAmount()+transactionAmount);
                            /**
                             * @desc - updateObj function is explained in in the FileFunction.h file
                             * 
                             * @params - {Number} transactionAccount-(Account Number)
                             * @params - {Object} tempCustomer-(Customer Object)
                             * 
                             */
                            updateObj<Customer>(transactionAccount, tempCustomer1);
                            updateObj<Customer>(transactionAccount2, tempCustomer2);
                            tempCustomer1 = getCustomer<Customer>(transactionAccount);
                            tempCustomer2 = getCustomer<Customer>(transactionAccount2);
                            time_t now = time(0);
                            char* dt = ctime(&now);
                            string time = dt;
                            /**
                             * @desc - Transaction Parametrized Constructor
                             * 
                             * @params - {String} transactionType
                             * @params - {Number} transactionAmount
                             * @params - {String} time
                             * @params - {Object} tempCustomer-(Customer Object)
                             * 
                             */
                            Transaction T1("Transfer(Withdraw)", transactionAmount, time, tempCustomer1);
                            Transaction T2("Transfer(Deposit)", transactionAmount, time, tempCustomer2);
                            /**
                             * @desc - createTrans function is explained in in the FileFunction.h file
                             * 
                             * @params - {Object} T1-(Transaction Object)
                             * 
                             */
                            createTrans<Transaction>(T1);
                            createTrans<Transaction>(T2);
                        }
                        else{
                            cout << "\n\n\t\t" << "Insufficient Balance.";
                        }
                    }
                    else{
                        cout << "\n\n\t\t" << "Account is not present in Database";
                    }
                }
                else{
                    cout << "\n\n\t\t" << "Account is not present in Database";
                }
                break;

                default:
                cout << "\n\t\t" << "Invalid Option. Try Again";
                break;
            }
        }while(checker1);
    }

    /**
     * @desc - displayInfo function is used to display all transaction information
     *         done by a Customer the program will ask Account Number input from User
     *         it will look for the Account Number in the Binary file and will print
     *         Transaction info related to that Account 
     *  
     */
    void displayInfo(){
        long long accNum;
        cout << "\n\n\t\t" << "Enter Account Number: ";
        cin >> accNum;
        /**
         * @desc - searchAcc function is explained in in the FileFunction.h file
         * 
         * @params - {Number} accNum-(Account Number)
         * 
         */
        if(searchAcc<Customer>(accNum)){
            /**
             * @desc - getCustomer function is explained in in the FileFunction.h file
             * 
             * @params - {Number} accNum-(Account Number)
             * @returnss - {Object} Customer Object
             * 
             */
            Customer tempObj = getCustomer<Customer>(accNum);
            cout << "\n\n\t\t" << "Account Information: ";
            tempObj.info();
            cout << "\n\n\t\t" << "Transaction History: ";
            /**
             * @desc - printTransactions function is explained in in the FileFunction.h file
             * 
             * @params - {Number} accNum-(Account Number)
             * 
             */
            printTransactions<Transaction>(accNum);
        }
        else{
            cout << "\n\n\t\t" << "Account is not present in Database";
        }
    }

    /**
     * @desc - interest function will calaculate the interest acc. to the date of last transaction
     *         user will be asked to input the date and if the time duration between time of transaction
     *         and user input date is more than 30 days then interest will be calculated
     *  
     */
    void interest(){
        long long accNum;
        int date, year;
        string month;
        char choice;
        cout << "\n\n\t\t" << "Enter Today's Date: ";
        cout << "\n\t\t" << "Enter Date: ";
        cin >> date;
        cout << "\n\t\t" << "Enter Month (Jan,Feb...): ";
        cin.ignore();
        getline(cin,month);
        cout << "\n\t\t" << "Enter Year: ";
        cin >> year;
        cout << "\n\n\t\t" << "Enter Account Number: ";
        cin >> accNum;
        if(searchAcc<Customer>(accNum)){
            /**
             * @desc - lastTransactions function is explained in in the FileFunction.h file
             * 
             * @params - {Number} accNum-(Account Number)
             * @returnss - {Object} Transaction Object
             * 
             */
            Transaction tempTrasaction = lastTransactions<Transaction>(accNum);
            string transactionTime = tempTrasaction.getTransactionTime();
            string transactionMonth = transactionTime.substr(4,3);
            int transDate = stoi(transactionTime.substr(8,2));
            int transYear = stoi(transactionTime.substr(20,4));
            /**
             * @desc - checkMonth function is explained in the TimeFunctions.h file
             * 
             * @params - {String} transactionMonth-(Month of last transaction)
             * @returnss - {Number} Sr. number of Month
             * 
             */
            int transMonth = checkMonth(transactionMonth);
            /**
             * @desc - checkMonth function is explained in the TimeFunctions.h file
             * 
             * @params - {String} month-(Month entered by user)
             * @returnss - {Number} Sr. number of Month
             * 
             */
            int currentMonth = checkMonth(month);
            /**
             * @desc - durationTime function is explained in the TimeFunctions.h file
             * 
             * @params - {Number} transDate-(date of last transaction)
             * @params - {Number} date-(Date entered by user)
             * @params - {Number} transMonth-(Sr. number of last transaction month)
             * @params - {Number} currentMonth-(Sr. number of month entered by user)
             * @params - {Number} transYear-(year of last transaction)
             * @params - {Number} year-(Year entered by user)
             * @returnss - {Number} Duration between last transaction date and date entered by user
             * 
             */
            int timeDuration = durationTime(transDate, date, transMonth, currentMonth, transYear, year);
            float interest = 2.5*timeDuration;
            cout << "\n\t\t" << "Calculated Interest: " << interest << "%";
            cout << "\n\n\t\t" << "Do you want to Update Interest on Account? (Y/N): ";
            cin >> choice;
            if(choice=='Y' || choice=='y'){
                /**
                 * @desc - getCustomer function is explained in in the FileFunction.h file
                 * 
                 * @params - {Number} accNum-(Account Number)
                 * @returnss - {Object} Customer Object
                 * 
                 */
                Customer tempCustomer = getCustomer<Customer>(accNum);
                tempCustomer.setObjInterest(interest);
                /**
                 * @desc - updateObj function is explained in in the FileFunction.h file
                 * 
                 * @params - {Number} transactionAccount-(Account Number)
                 * @params - {Object} tempCustomer-(Customer Object)
                 * 
                 */
                updateObj<Customer>(accNum,tempCustomer);
                cout << "\n\t\t" << "Interest Updated.";
            }
        }
        else{
            cout << "\n\n\t\t" << "Account is not present in Database";
        }
    }

};