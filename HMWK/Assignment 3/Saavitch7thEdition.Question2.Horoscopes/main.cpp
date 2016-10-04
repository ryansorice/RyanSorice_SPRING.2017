/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 2 October 2016 11:42 AM
 * 
 * Purpose: Write a program that outputs a users Horoscope based on month 
 *          and date.
 */

//System libraries
#include <iostream>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Initial output
    cout<<"Welcome to the Horoscope Reader!\n";
    
    //Declaration/Initiation of variables
    short month,day;
    char yesno='y';
    
    //Loop to run horoscope as often as user would like
    while(yesno=='y'||yesno=='Y')
    {
        //Output to user;Initiation of variables
        cout<<"What is your birth month?\n";
        cin>>month;
        cout<<"Now, what is the day of your birth?\n";
        cin>>day;
        
        //First if statement to read users horoscope
        if(month==1&&(day>0&&day<20))
        {
            cout<<"Your sign reads CAPRICORN!\n";
            
            //First nested if for the cusp Sign
            if(day==19||day==18)
            {
                cout<<"Your birth date is on the cusp of another sign, AQUARIUS!\n";
            }
        }
        //Next if statement to read users horoscope
        else if(month==1&&(day>19&&day<32))
        {
            cout<<"Your sign reads AQUARIUS!\n";
            //Nested if, for the cusp Sign
            if(day==20||day==21)
            {
                cout<<"Your birth date is on the cusp of another sign, CAPRICORN!\n";
            }
        }
        //Next if statement "
        else if(month==2&&(day>0&&day<19))
        {
            cout<<"Your sign reads AQUARIUS!\n";
            //Nested if, for the cusp Sign
            if(day==17||day==18)
            {
                cout<<"Your birth date is on the cusp of another sign, PISCES!\n";
            }
        }
        //Next if statement "
        else if(month==2&&(day>18&&day<29))
        {
           cout<<"Your sign reads PISCES!\n";
           //Nested if, for the cusp Sign
           if(day==19||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, AQUARIUS!\n";
            }
        }
        //Next if statement "
        else if(month==3&&(day>0&&day<21))
        {
            cout<<"Your sign reads PISCES!\n";
            //Nested if, for the cusp Sign
            if(day==19||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, ARIES!\n";
            }
        }
        //Next if statement "
        else if(month==3&&(day>20&&day<32))
        {
            cout<<"Your sign reads ARIES!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==22)
            {
                cout<<"Your birth date is on the cusp of another sign, PISCES!\n";
            }
        }
        //Next if statement "
        else if(month==4&&(day>0&&day<20))
        {
            cout<<"Your sign reads ARIES!\n";
            //Nested if, for the cusp Sign
            if(day==19||day==18)
            {
                cout<<"Your birth date is on the cusp of another sign, TAURUS!\n";
            }
        }
        //Next if statement "
        else if(month==4&&(day>19&&day<31))
        {
            cout<<"Your sign reads TAURUS!\n";
            //Nested if, for the cusp Sign
            if(day=21||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, ARIES!\n";
            }
        }
        //Next if statement "
        else if(month==5&&(day>0&&day<21))
        {
            cout<<"Your sign reads TAURUS!\n";
            //Nested if, for the cusp Sign
            if(day==19||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, GEMINI!\n";
            }
        }
        //Next if statement "
        else if(month==5&&(day>20&&day<32))
        {
            cout<<"Your sign reads GEMINI!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==22)
            {
                cout<<"Your birth date is on the cusp of another sign, TAURUS!\n";
            }
        }
        //Next if statement "
        else if(month==6&&(day>0&&day<22))
        {
            cout<<"Your sign reads GEMINI!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, CANCER!\n";
            }
        }
        //Next if statement "
        else if(month==6&&(day>21&&day<31))
        {
            cout<<"Your sign reads CANCER!\n";
            //Nested if, for the cusp Sign
            if(day==22||day==23)
            {
                cout<<"Your birth date is on the cusp of another sign, GEMINI!\n";
            }
        }
        //Next if statement "
        else if(month==7&&(day>0&&day<23))
        {
            cout<<"Your sign reads CANCER!\n";
            //Nested if, for the cusp Sign
            if(day==22||day==21)
            {
                cout<<"Your birth date is on the cusp of another sign, LEO!\n";
            }
        }
        //Next if statement "
        else if(month==7&&(day>22&&day<32))
        {
            cout<<"Your sign reads LEO!\n";
            //Nested if, for the cusp Sign
            if(day==23||day==24)
            {
                cout<<"Your birth date is on the cusp of another sign, CANCER!\n";
            }
        }
        //Next if statement "
        else if(month==8&&(day>0&&day<23))
        {
            cout<<"Your sign reads LEO!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==22)
            {
                cout<<"Your birth date is on the cusp of another sign, VIRGO!\n";
            }
        }
        //Next if statement "
        else if(month==8&&(day>22&&day<32))
        {
            cout<<"Your sign reads VIRGO!\n";
            //Nested if, for the cusp Sign
            if(day==23||day==24)
            {
                cout<<"Your birth date is on the cusp of another sign, LEO!\n";
            }
        }
        //Next if statement "
        else if(month==9&&(day>0&&day<23))
        {
            cout<<"Your sign reads VIRGO!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==22)
            {
                cout<<"Your birth date is on the cusp of another sign, LIBRA!\n";
            }
        }
        //Next if statement "
        else if(month==9&&(day>22&&day<31))
        {
            cout<<"Your sign reads LIBRA!\n";
            //Nested if, for the cusp Sign
            if(day==23||day==24)
            {
                cout<<"Your birth date is on the cusp of another sign, VIRGO!\n";
            }
        }
        //Next if statement "
        else if(month==10&&(day>0&&day<23))
        {
            cout<<"Your sign reads LIBRA!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==22)
            {
                cout<<"Your birth date is on the cusp of another sign, SCORPIO!\n";
            }
        }
        //Next if statement "
        else if(month==10&&(day>22&&day<32))
        {
            cout<<"Your sign reads SCORPIO!\n";
            //Nested if, for the cusp Sign
            if(day==23||day==24)
            {
                cout<<"Your birth date is on the cusp of another sign, LIBRA!\n";
            }
        }
        //Next if statement "
        else if(month==11&&(day>0&&day<22))
        {
            cout<<"Your sign reads SCORPIO!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, SAGITTARIUS!\n";
            }
        }
        //Next if statement "
        else if(month==11&&(day>21&&day<31))
        {
            cout<<"Your sign reads SAGITTARIUS!\n";
            //Nested if, for the cusp Sign
            if(day==23||day==22)
            {
                cout<<"Your birth date is on the cusp of another sign, SCORPIO!\n";
            }
        }
        //Next if statement "
        else if(month==12&&(day>0&&day<22))
        {
            cout<<"Your sign reads SAGITTARIUS!\n";
            //Nested if, for the cusp Sign
            if(day==21||day==20)
            {
                cout<<"Your birth date is on the cusp of another sign, CAPRICORN!\n";
            }
        }
        //Next if statement "
        else if(month==12&&(day>21&&day<32))
        {
            cout<<"Your sign reads CAPRICORN!\n";
            //Nested if, for the cusp Sign
            if(day==22||day==23)
            {
                cout<<"Your birth date is on the cusp of another sign, SAGITTARIUS!\n";
            }
        }
        //Final if statement if user enters non-existant dates
        else if((month<1||month>12)||(day<1||day>31))
        {
            cout<<"We both know the date you entered does not exist =P!\n";
        }
        //User initiates whether to run again
        cout<<"Would you like another reading? Enter 'Y' or 'N'\n";
        cin>>yesno;
    }
    
    
    //Exits program
    return 0;
}

