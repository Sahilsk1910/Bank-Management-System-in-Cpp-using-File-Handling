#include<iostream>
#include<stdio.h>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

/**
 * In this FileFunctions.h header file i have implemented functions 
 * related File Manipulation for this Bank Management System Project
 * 
 */


/**
 * @desc - In this getAccountID function it will fetch and return 
 *         value of Account ID from binary file BankCodes_Data.bin
 * 
 * @returnss - {Number} Return value of Account ID from binary file BankCodes_Data.bin
 * 
 */
template<class T>
T getAccountID(){
    T account;
    ifstream temp("BankCodes_Data.bin", ios::binary);
    temp.read((char *)&account, sizeof(account));
    temp.close();
    return account;
}


/**
 * @desc - In this getCustomerID function it will fetch and return 
 *         value of Customer ID from binary file BankCodes_Data.bin
 * 
 * @returnss - {Number} Return value of Customer ID from binary file BankCodes_Data.bin
 * 
 */
template<class T>
T getCustomerID(){
    T customer;
    ifstream temp("BankCodes_Data.bin", ios::binary);
    temp.seekg(sizeof(long long),ios::beg);
    temp.read((char *)&customer, sizeof(customer));
    temp.close();
    return customer;
}


/**
 * @desc - In this getTransactionID function it will fetch and return
 *         value of Transaction ID from binary file BankCodes_Data.bin
 * 
 * @returnss - {Number} Return value of Transaction ID from binary file BankCodes_Data.bin
 * 
 */
template<class T>
T getTransactionID(){
    T transaction;
    ifstream temp("BankCodes_Data.bin", ios::binary);
    temp.seekg(-sizeof(transaction),ios::end);
    temp.read((char *)&transaction, sizeof(transaction));
    temp.close();
    return transaction;
}


/**
 * @desc - In this setBankCodes function it will update the values of
 *         Account ID, Customer ID & Transaction ID in binary file
 *         at the end of the Main Program
 * 
 * @params - {Number} account
 * @params - {Number} customer
 * @params - {Number} transaction
 * 
 */
void setBankCodes(long long account, int customer, long long transaction){
    ofstream temp("BankCodes_Data.bin", ios::binary);
    temp.write((char *)&account, sizeof(account));
    temp.write((char *)&customer, sizeof(customer));
    temp.write((char *)&transaction, sizeof(transaction));
    temp.close();
}


/**
 * @desc - In this createAcc function it will have an obj as an Parameter
 *         It will Append objs that is passed as Parameter in the binary file
 *         Account_data.bin which will have info related to Customer and their accounts
 * 
 * @params - {Object} obj
 * 
 */
template<class T>
void createAcc(T obj){
    ofstream temp("Account_data.bin", ios::binary | ios::app);
    temp.write((char *)&obj, sizeof(obj));
    temp.close();
}


/**
 * @desc - In this readAll function it will print the info of
 *         All the Customers and their Accounts which are present
 *         in Account_data.bin binary file
 * 
 */
template<class T>
void readAll(){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        obj.info();
    }
    temp.close();
}


/**
 * @desc - In this readLast function it will print the info of
 *         Last Customer and their Account which is present
 *         at the end of Account_data.bin binary file
 * 
 */
template<class T>
void readLast(){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    temp.seekg(-sizeof(obj), ios::end);
    while(temp.read((char *)&obj, sizeof(obj))){
        obj.info();
    }
    temp.close();
}


/**
 * @desc - In this search function it will have Account number as Parameter and it will return bool
 *         value search function will search for provided account number in the Account_Data.bin file and
 *         if it is present in the file it will print Account info and return true else it will return false
 * 
 * @params - {Number} accountNum
 * @returnss - {Boolean} Return True or False
 * 
 */
template<class T>
bool search(long long accountNum){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            obj.info();
            temp.close();
            return true;
        }
    }
    temp.close();
    return false;
}


/**
 * @desc - In this del function it will have Account Number as Parameter and it will
 *         search for that Account Number in Account_Data.bin file and will remove that
 *         account from the binary file
 * 
 * @params - {Number} accountNum
 * 
 */
template<class T>
void del(long long accountNum){
    ifstream file("Account_data.bin", ios::binary);
    ofstream temp("temp.bin", ios::binary);
    T obj;
    while(file.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()!=accountNum){
            temp.write((char *)&obj, sizeof(obj));
        }
    }
    file.close();
    temp.close();

    remove("Account_data.bin");
    rename("temp.bin", "Account_data.bin");
}


/**
 * @desc - In this updateName function it will have Account Number and newName as Parameters and it will
 *         find the customer related to that Account Number and will update that Customer's
 *         Name in Account_data.bin file with the Name provided in string Parameter
 * 
 * @params - {Number} accountNum
 * @params - {String} name
 * 
 */
template<class T>
void updateName(long long accountNum, string name){
    fstream temp("Account_data.bin", ios::in | ios::out | ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            obj.setCustomerName(name);
            temp.seekp((unsigned long long)temp.tellg()-sizeof(obj), ios::beg);
            temp.write((char *)&obj, sizeof(obj));
            break;
        }
    }
    temp.close();
}


/**
 * @desc - In this updateNumber function it will have Account Number and newPhoneNo as Parameters and it will
 *         find the customer related to that Account Number and will update that Customer's
 *         Phone Number in Account_data.bin file with the Phone Number provided in the Parameter
 * 
 * @params - {Number} accountNum
 * @params - {Number} phoneno
 * 
 */
template<class T>
void updateNumber(long long accountNum, unsigned long long phoneno){
    fstream temp("Account_data.bin", ios::in | ios::out | ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            obj.setPhoneNo(phoneno);
            temp.seekp((unsigned long long)temp.tellg()-sizeof(obj), ios::beg);
            temp.write((char *)&obj, sizeof(obj));
            break;
        }
    }
    temp.close();
}


/**
 * @desc - In this updateAddress function it will have Account Number and newAddress as Parameters and it will
 *         find the customer related to that Account Number and will update that Customer's
 *         Address in Account_data.bin file with the Address provided in the string Parameter
 * 
 * @params - {Number} accountNum
 * @params - {String} address
 * 
 */
template<class T>
void updateAddress(long long accountNum, string address){
    fstream temp("Account_data.bin", ios::in | ios::out | ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            obj.setAddress(address);
            temp.seekp((unsigned long long)temp.tellg()-sizeof(obj), ios::beg);
            temp.write((char *)&obj, sizeof(obj));
            break;
        }
    }
    temp.close();
}


/**
 * @desc - In this searchAcc function it will have Account Number as Parameter and will return bool value
 *         it will search for the Account Number in the Account_data.bin file and if the Account is present
 *         in that file it will return true else false
 * 
 * @params - {Number} accountNum
 * @returnss - {Boolean} Return True or False
 * 
 */
template<class T>
bool searchAcc(long long accountNum){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            temp.close();
            return true;
        }
    }
    temp.close();
    return false;
}


/**
 * @desc - In this checkAmount function it will have Account Number and Amount as Parameters and will return bool
 *         value basically this function is used for withdraw transactions it will check whether the specified
 *         account have enough amount for withdraw or not So it will go in Account_data.bin file and check the amount
 * 
 * @params - {Number} accountNum
 * @params - {Number} amount
 * @returnss - {Boolean} Return True or False
 * 
 */
template<class T>
bool checkAmount(long long accountNum, unsigned long long amount){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            if(obj.getObj().getAmount()>=amount){
                temp.close();
                return true;
            }
        }
    }
    temp.close();
    return false;
}


/**
 * @desc - In this createTrans function it will have an obj as an Parameter It will Append
 *         objs that is passed as Parameter in the binary file Transaction_data.bin which
 *         will have info related to Customer and their accounts and their Transactions
 * 
 * @params - {Object} obj
 * 
 */
template<class T>
void createTrans(T obj){
    ofstream temp("Transaction_data.bin", ios::binary | ios::app);
    temp.write((char *)&obj, sizeof(obj));
    temp.close();
}


/**
 * @desc - In this getCustomer function it will have Account Number as an Parameter and will
 *         return an obj it will search for specified account number in Account_data.bin file
 *         after that when account number is found obj having that account number will be returned
 * 
 * @params - {Number} accountNum
 * @returnss - {Object} Return Object from Account_data.bin file
 * 
 */
template<class T>
T getCustomer(long long accountNum){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            temp.close();
            return obj;
        }
    }
    temp.close();
    return obj;
}


/**
 * @desc - In this lastCustomer function it will return an obj it will
 *         return last Customer obj present in Account_data.bin file
 * 
 * @returnss - {Object} Return Object from Account_data.bin file
 * 
 */
template<class T>
T lastCustomer(){
    ifstream temp("Account_data.bin", ios::binary);
    T obj;
    temp.seekg(-sizeof(obj), ios::end);
    temp.read((char *)&obj, sizeof(obj));
    temp.close();
    return obj;
}


/**
 * @desc - In this lastTransaction function it will return an obj it will
 *         return last obj present in Transaction_data.bin file
 * 
 * @returnss - {Object} Return Object from Transaction_data.bin file
 * 
 */
template<class T>
T lastTransaction(){
    ifstream temp("Transaction_data.bin", ios::binary);
    T obj;
    temp.seekg(-sizeof(obj), ios::end);
    temp.read((char *)&obj, sizeof(obj));
    temp.close();
    return obj;
}


/**
 * @desc - In this updateObj function it will have Account Number and New Object as Parameters
 *         it will look for the specified account number in the Account_data.bin file and
 *         when the object is found it will update that Object with New Object
 * 
 * @params - {Number} accountNum
 * @params - {Object} newObj
 * 
 */
template<class T>
void updateObj(long long accountNum, T newObj){
    fstream temp("Account_data.bin", ios::in | ios::out | ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getObj().getAccountNo()==accountNum){
            obj = newObj;
            temp.seekp((unsigned long long)temp.tellg()-sizeof(obj), ios::beg);
            temp.write((char *)&obj, sizeof(obj));
            break;
        }
    }
    temp.close();
}


/**
 * @desc - In this printTransactions function it will have Account Number as Parameter
 *         it will look for the specified account number in the Transaction_data.bin file
 *         and when the object is found it will print object's values
 * 
 * @params - {Number} accountNum
 * 
 */
template<class T>
void printTransactions(long long accountNum){
    ifstream temp("Transaction_data.bin", ios::binary);
    T obj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getCustomerObj().getObj().getAccountNo()==accountNum){
            obj.info();
        }
    }
    temp.close();
}


/**
 * @desc - In this lastTransactions function it will have Account Number as Parameter
 *         it will look for the specified account number in the Transaction_data.bin file
 *         and it will return the Object of the last Transaction that is done from that specified account number
 * 
 * @params - {Number} accountNum
 * @returnss - {Object} Return Object from Transaction_data.bin file
 * 
 */
template<class T>
T lastTransactions(long long accountNum){
    ifstream temp("Transaction_data.bin", ios::binary);
    T obj;
    T tempObj;
    while(temp.read((char *)&obj, sizeof(obj))){
        if(obj.getCustomerObj().getObj().getAccountNo()==accountNum){
            tempObj = obj;
        }
    }
    temp.close();
    return tempObj;
}
