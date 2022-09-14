#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

/**
 * @desc - checkMonth function is used to return Sr. number of month
 *         that is given as the Parameter of the function
 * 
 * @params - {String} Month
 * @returnss - {Number} Sr. number of Month
 * 
 */
int checkMonth(string month){
    const char *months = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC,";

    char find[4];
    strcpy(find,month.c_str());
    strupr(find);

    char *foundAt = strstr(months, find);
    if (foundAt != NULL)
    {
        if (foundAt[3] == ',')
        {
            int monthNum = (((foundAt - months) / 4) + 1);
            return monthNum;
        }
    }
    return 0;
}

/**
 * @desc - durationTime function is used to return the difference of number of months
 *         between the two dates mentioned as Parameters of the function
 * 
 * @params - {Number} transDate-(date of last transaction)
 * @params - {Number} currDate-(Date entered by user)
 * @params - {Number} transMonth-(Sr. number of last transaction month)
 * @params - {Number} currMonth-(Sr. number of month entered by user)
 * @params - {Number} transYear-(year of last transaction)
 * @params - {Number} currYear-(Year entered by user)
 * @returnss - {Number} Duration between last transaction date and date entered by user
 * 
 */
int durationTime(int transDate, int currDate, int transMonth, int currMonth, int transYear, int currYear){
    int yearDiff = currYear - transYear;
    int monthDiff = ((12*yearDiff)-transMonth)+currMonth;
    int count=0;
    if(monthDiff>=1){
        count = monthDiff;
        if(currDate>=transDate){
            return count;
        }
        else{
            count--;
            return count;
        }
    }
    else{
        count = 0;
        return count;
    }
}