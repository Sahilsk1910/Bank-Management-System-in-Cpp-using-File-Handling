#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include"FileFunctions.h"
using namespace std;

/**
 * @desc - getAccountID function is explained in in the FileFunction.h file
 * 
 */
static long long AccountID = getAccountID<long long>();

/**
 * @desc - Account Class deals with all the Parameters related
 *         to Customer's Bank Account it has several Parameters
 *         and functions
 * 
 * @params - {Number} AccountNo-(Account Number of Account Holder)
 * @params - {Char Array} AccountStatus-(Active)
 * @params - {Char Array} AccountType-(Current,Saving,Joint)
 * @params - {Number} Amount-(Amount in the Account)
 * @params - {Number} Interest-(Intrest on Account acc. to last Transaction)
 * 
 */
class Account{
    protected:
    long long AccountNo;
    char AccountStatus[7];
    char AccountType[8];
    unsigned long long Amount;
    float Interest;

    public:
    /**
     * @desc - Empty Constructor
     * 
     */
    Account(){}

    /**
     * @desc - Parameterized Constructor
     * 
     */
    Account(string accStatus, string accType, unsigned long long amount){
        AccountID++;
        AccountNo = AccountID;
        strcpy(AccountStatus, accStatus.c_str());
        strcpy(AccountType, accType.c_str());
        Amount = amount;
        Interest = 0;
    }

    /**
     * @desc - getAccountNo function will return Account Number
     * 
     * @returnss - {Number} Return value of AccountNo
     * 
     */
    long long getAccountNo(){
        return AccountNo;
    }

    /**
     * @desc - getAccountStatus function will return Account Status
     * 
     * @returnss - {Char Pointer} Return pointer to AccountStatus
     * 
     */
    char* getAccountStatus(){
        return AccountStatus;
    }

    /**
     * @desc - getAccountType function will return Account Type
     * 
     * @returnss - {Char Pointer} Return pointer to AccountType
     * 
     */
    char* getAccountType(){
        return AccountType;
    }

    /**
     * @desc - getAmount function will return Amount
     * 
     * @returnss - {Number} Return value to Amount
     * 
     */
    unsigned long long getAmount(){
        return Amount;
    }

    /**
     * @desc - setAmount function will set value of Amount
     * 
     * @params - {Number} newAmount
     * 
     */
    void setAmount(unsigned long long newAmount){
        Amount = newAmount;
    }

    /**
     * @desc - getInterest function will return Interest
     * 
     * @returnss - {Number} Return value to Interest
     * 
     */
    float getInterest(){
        return Interest;
    }

    /**
     * @desc - setInterest function will set value of Interest
     * 
     * @params - {Number} newInterest
     * 
     */
    void setInterest(float newInterest){
        Interest = newInterest;
    }
};
