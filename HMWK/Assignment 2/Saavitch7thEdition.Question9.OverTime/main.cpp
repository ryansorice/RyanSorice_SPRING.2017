/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 28 September 2016 7:10 PM
 * 
 * Purpose: Write a program that will read in the number of hours worked in a week
 *          and the number of dependents as input, and then will output the workers
 *          gross pay, each withholding amount, and the net take-home pay for the week.
 */

//System libraries
#include <iostream>
#include <iomanip>

using namespace std; //Namespace in system libraries


//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration/Initiation of variables
    short depend;//Number of dependents
    float perHour, //Salary per hour
          hours, //Hours worked in a week
          pay, //Gross pay
          netPay, //Net pay(after taxes and dues)
          ovrTime, //Dollar amount of overtime paid
          ssTax=.06, //Social Security tax rate
          fedTax=.14, //Federal Income tax rate
          statTax=.05, //State Income tax rate
          uniDues=10, //Union dues
          extraD=35; //If dependents = 3 < .
    
    //Initial output to user; variable initialization
    cout<<"How much do you make an hour?\n";
    cin>>perHour;
    cout<<"How many hours did you work this week?\n";
    cin>>hours;
    cout<<"How many dependents do you have?\n";
    cin>>depend;
    
    //First if statement processing income without dependent insurance dues
    if(depend<3)
    {
        //First nested if statement if hours worked is less or equal to 40
        if(hours<=40)
        {
            //Processing variables for new outputs
            pay=hours*perHour; //Gross pay
            ssTax=pay*ssTax; //Amount of Social Security tax due
            fedTax=pay*fedTax; //Amount of Federal Income tax due
            statTax=pay*statTax; //Amount of State Income tax due
            netPay=pay-ssTax-fedTax-statTax-uniDues; //Net pay
        
            //Final output of processed variables if hours < 40
            cout<<"Your gross pay is                     :$"<<setw(5)<<pay<<endl<<endl;
            cout<<"The social security tax you pay is    :$"<<setw(5)<<ssTax<<endl;
            cout<<"The federal income tax you pay is     :$"<<setw(5)<<fedTax<<endl;
            cout<<"The state income tax you pay is       :$"<<setw(5)<<statTax<<endl;
            cout<<"Your union dues are a flat            :$"<<setw(5)<<uniDues<<endl<<endl;
            cout<<"After taxes and dues, you take home   :$"<<setw(5)<<netPay<<endl;
        }
        //Second nested if statement if hours > 40 for overtime
        else if(hours>40)
        {
            //Processing of variables, map inputs to outputs
            pay=40*perHour; //Pay for the first 40 hours
            ovrTime=(hours-40)*(perHour*1.5); //Amount of overtime pay due
            pay=pay+ovrTime; //Total gross pay 
            ssTax=pay*ssTax; //Amount of Social Security tax due
            fedTax=pay*fedTax; //Amount of Federal Income tax due
            statTax=pay*statTax; //Amount of State Income tax due
            netPay=pay-ssTax-fedTax-statTax-uniDues; //Net pay
        
            //Final output of processed variables if hours < 40
            cout<<"Your gross pay is                     :$"<<setw(5)<<pay<<endl<<endl;
            cout<<"The social security tax you pay is    :$"<<setw(5)<<ssTax<<endl;
            cout<<"The federal income tax you pay is     :$"<<setw(5)<<fedTax<<endl;
            cout<<"The state income tax you pay is       :$"<<setw(5)<<statTax<<endl;
            cout<<"Your union dues are a flat            :$"<<setw(5)<<uniDues<<endl<<endl;
            cout<<"After taxes and dues, you take home   :$"<<setw(5)<<netPay<<endl;
        } 
    }
    
    //Second if statement processing income with dependent insurance dues
    else if(depend>=3)
    {
        //First nested if statement if hours worked is less or equal to 40
        if(hours<=40)
        {
            //Processing variables for new outputs
            pay=hours*perHour; //Gross pay
            ssTax=pay*ssTax; //Amount of Social Security tax due
            fedTax=pay*fedTax; //Amount of Federal Income tax due
            statTax=pay*statTax; //Amount of State Income tax due
            netPay=pay-ssTax-fedTax-statTax-uniDues-extraD; //Net pay
        
            //Final output of processed variables if hours < 40
            cout<<"Your gross pay is                       :$"<<setw(5)<<pay<<endl<<endl;
            cout<<"The social security tax you pay is      :$"<<setw(5)<<ssTax<<endl;
            cout<<"The federal income tax you pay is       :$"<<setw(5)<<fedTax<<endl;
            cout<<"The state income tax you pay is         :$"<<setw(5)<<statTax<<endl;
            cout<<"Your union dues are a flat              :$"<<setw(5)<<uniDues<<endl<<endl;
            cout<<"Your dependent insurance dues is a flat :$"<<setw(5)<<extraD<<endl;
            cout<<"After taxes and dues, you take home     :$"<<setw(5)<<netPay<<endl;
        }
        //Second nested if statement if hours > 40 for overtime
        else if(hours>40)
        {
            //Processing of variables, map inputs to outputs
            pay=40*perHour; //Pay for the first 40 hours
            ovrTime=(hours-40)*(perHour*1.5); //Amount of overtime pay due
            pay=pay+ovrTime; //Total gross pay 
            ssTax=pay*ssTax; //Amount of Social Security tax due
            fedTax=pay*fedTax; //Amount of Federal Income tax due
            statTax=pay*statTax; //Amount of State Income tax due
            netPay=pay-ssTax-fedTax-statTax-uniDues-extraD; //Net pay
        
            //Final output of processed variables if hours < 40
            cout<<"Your gross pay is                       :$"<<setw(5)<<pay<<endl<<endl;
            cout<<"The social security tax you pay is      :$"<<setw(5)<<ssTax<<endl;
            cout<<"The federal income tax you pay is       :$"<<setw(5)<<fedTax<<endl;
            cout<<"The state income tax you pay is         :$"<<setw(5)<<statTax<<endl;
            cout<<"Your union dues are a flat              :$"<<setw(5)<<uniDues<<endl<<endl;
            cout<<"Your dependent insurance dues is a flat :$"<<setw(5)<<extraD<<endl;
            cout<<"After taxes and dues, you take home     :$"<<setw(5)<<netPay<<endl;
        }
    }
    
    
    //Exits program
    return 0;
}

