/* 
   File:   main
   Author: Ryan Sorice
   Created on 17 October 2:30 PM
   Purpose:  Menu with Functions
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath> //Math library for power function

using namespace std;  //Name-space used in the System Library

//Global constants
float CNGALON=0.264179; //Gallon conversion

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Question 1"<<endl;
        cout<<"2.  Type 2  for Question 3"<<endl;
        cout<<"3.  Type 3  for Question 4"<<endl;
        cout<<"4.  Type 4  for Question 6"<<endl;
        cout<<"5.  Type 5  for Question 8"<<endl;
        cout<<"6.  Type 6  for Question 9"<<endl;
        cout<<"7.  Type 7  for Question 13"<<endl;
        cout<<"8.  Type 8  for Question 14"<<endl;
        cout<<"9.  Type 9  for Question 15"<<endl;
        cout<<"10. Type 10 for Question 16"<<endl;
        cin>>menuItm;
        //Go to the Problem
        switch(menuItm){
            case 1:problem1();break;
            case 2:problem2();break;
            case 3:problem3();break;
            case 4:problem4();break;
            case 5:problem5();break;
            case 6:problem6();break;
            case 7:problem7();break;
            case 8:problem8();break;
            case 9:problem9();break;
            case 10:problem10();
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop
    //Exit Program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 1 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem1(){
    cout<<"Inside Question 1"<<endl;
    //Declaration of variables
    char yesno='y'; //Counter for loop
    float gasLitr, //Liters of gasoline in user's car
          gallons, //Gallons of gasoline in user's car
          miles, //Miles traveled in user's car
          car1, //Car 1 mpg
          car2; //Car 2 mpg
    
     //Initial output
    cout<<"This program calculates how fuel efficient your vehicles are!\n";
    
    //Loop to repeat calculation while user says yes
    //'y' 'Y' true, else false
    while(yesno=='y'||yesno=='Y'){
        //Output; Initiation of variables
        cout<<"How many liters of gasoline is the first car consuming?\n";
        cin>>gasLitr;
        cout<<"How many miles is this car traveling?\n";
        cin>>miles;
    
        //Process values
        gallons=gasLitr*CNGALON; //Liters to gallons conversion
        car1=miles/gallons; //First car mpg
    
        //Next output to user; Processing mpg of first vehicle
        cout<<"The first car consumed "<<gallons<<" gallons of gasoline.\n";
        cout<<"It traveled at "<<car1<<" mpg.\n"<<endl;

        //Next output; Initiation of variables
        cout<<"How many liters of gasoline is the second car consuming?\n";
        cin>>gasLitr;
        cout<<"How many miles is this car traveling?\n";
        cin>>miles;

        //Process values
        gallons=gasLitr*CNGALON; //Liters to gallons conversion
        car2=miles/gallons; //Second car mpg

        //Next output to user; Processing mpg of first vehicle
        cout<<"The second car consumed "<<gallons<<" gallons of gasoline.\n";
        cout<<"It traveled at "<<car2<<" mpg.\n"<<endl;

        //If statement car 1 better fuel efficiency
        if(car1>car2){
            cout<<"Car 1 has the best fuel efficiency!\n"<<endl;
        }
        //Next if statement car 2 better fuel efficiency
        else if (car1<car2){
            cout<<"Car 2 has the best fuel efficiency!\n"<<endl;
        }
        //Final if statement car 1 same fuel efficiency as car 2
        else{
            cout<<"Wow, the cars have the same fuel efficiency!\n"<<endl;
        }
        //User initiates to continue loop or end program
        cout<<"Would you like to repeat this process? Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 3 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem2(){
    cout<<"Inside Question 3"<<endl;
    //Declaration of variables
    int nmrtr, //Numerator of fractional of individual share value
        dnmntr, //Denominator of fractional of individual share value
        shares; //Amount of shares user holds
    float whole, //Whole number of individual share value
          nfrac, //Amount of the fractional multiplied by the shares
          rmndr, //Remainder of the fractional multiplied by the shares
          wDollar; //Whole number of individual share value 
    char yesno='y'; //Variable for loop true/false
    
    //Initial output
    cout<<"This program will compute the current value of your stock!\n";
    
    //Loop to allow user to run program til user enters false
    //'y' 'Y' true, else false
    while(yesno=='y'||yesno=='Y'){
        //Output to user; Initialize variables
        cout<<"How many shares of stock do you own?\n";
        cin>>shares;
        cout<<"What is the whole dollar portion of the price of the shares?\n";
        cin>>wDollar;
        cout<<"Now enter the fractional portion of the price of the shares in eighths.\n";
        cout<<"What is the numerator of the fraction portion of the price of the shares?\n";
        cin>>nmrtr;
        cout<<"What is the denominator of the fraction portion of the price of the shares?\n";
        cin>>dnmntr;

        //Processing values
        whole=wDollar*shares;
        nfrac=(nmrtr*shares)/dnmntr; //Fraction portion that gets added to the whole
        rmndr=(nmrtr*shares)%dnmntr; //Remainder of fraction portion

        //If statement if no remainder
        if(rmndr==0){
            //Output value of stock without remainder
            cout<<"The value of your stock is $"<<whole+nfrac<<endl;
        }
        //Else if there is a remainder
        else{  
            //Output value of stock with remainder
            cout<<"The value of your stock is $"<<whole+nfrac<<" "<<rmndr<<"/"<<dnmntr<<endl;
        }
        //Output to user; initiates loop again or break
        cout<<"Do you have more shares? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 4 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem3(){
    cout<<"Inside Question 4"<<endl;
    //Declaration of variables
    float curPric, //Current price
          oldPric, //Price 1 year ago
          inflat, //Inflation rate of item
          years; //Number of years to produce inflated price
    short n=1;
    
    //Initial output/Variables initialization
    cout<<"This program will give you the inflation rate and inflated price of\n";
    cout<<"any item!\n";
    cout<<"What is the current price of your item?\n";
    cin>>curPric;
    cout<<"What was the price of your item one year ago?\n";
    cin>>oldPric;
    cout<<"How many years would you like to calculate inflation on this item?\n";
    cin>>years;
    
    //Process inputs
    inflat=(curPric-oldPric)/oldPric;
    
    //Output of inflation rate
    cout<<"The inflation rate on your item is "<<inflat*100<<"%\n";
    
    //Loop for inflation price for specified years
    for(; n<=years; n++){
        //Process and output inflation price each year
        curPric=(curPric*inflat)+curPric;
        cout<<"The price in "<<n<<" year(s) is $"<<curPric<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 6 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem4(){
    cout<<"Inside Question 6"<<endl;
    //Declaration/Initiation of variables
    short n=0, //Loop counter
          mons; //Number of months interest to be paid
    float credBal, //User's credit balance
          intRate, //Interest rate on credit balance
          accInt, //Total interest accrued after each month
          totInt=0, //Total accrued interest after all months
          totBal=0; //Total balance due with interest
          
    
    //Initial output; Variable initiation
    cout<<"This program calculates the interest due on your credit balance!\n";
    cout<<"What is your current credit balance owed?\n";
    cin>>credBal;
    cout<<"What is the interest rate on your credit balance?\n";
    cin>>intRate;
    cout<<"How many months is interest being collected?\n";
    cin>>mons;
    
    //Loop to calculate total interest and total balance for user's  months
    while(n<mons){
        //Process values
        accInt=credBal*(intRate/100); //Interest of on total balance after each month
        credBal=accInt+credBal; //Adds interest for each month to total balance
        totInt=totInt+accInt; //Adds interest to total interest after each month
        n++; //Increments n til equal to months for the loop
    }
    //Final output; total interest and total balance
    cout<<"The total interest due is $"<<totInt<<endl;
    cout<<"Your balance due, with interest, after "<<mons<<" month(s) is $"<<credBal<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 8 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem5(){
    cout<<"Inside Question 8"<<endl;
    //Declaration of variables
    char yesno='y'; //Loop variable 
    float houseP, //Total price of user's house
          downPay, //User's down payment on house
          annMort, //Annual mortgage cost
          taxSvgs, //Tax savings on cost of house
          loanBal, //Initial loan balance
          cost; //Total house cost of first year
    
    //Initial output; Variable initiation
    cout<<"This program will compute the total annual cost for the first\n";
    cout<<"year of your new home.\n";
    
    //Loop to allow user to utilize program until they say no
    //('Y' 'y' true, else false)
    while(yesno=='y'||yesno=='Y'){
        //Output; Variable initiation
        cout<<"What is the total cost of your house?\n";
        cin>>houseP;
        cout<<"Now, what was your down payment?\n";
        cin>>downPay;

        //Process variables
        loanBal=houseP-downPay; //Initial loan balance (house payment less down payment)
        annMort=(loanBal*0.03)+(loanBal*0.06); //Annual Mortgage (3% of loan balance + 6% l.b.)
        taxSvgs=(0.35*(loanBal*0.06)); //Tax savings (35% of interest paid)
        cost=annMort-taxSvgs; //Total first year cost (annual mortgage less tax savings)

        //Final output; Loop initiation/break
        cout<<"The annual cost for the first year of your new home is $"<<cost<<endl<<endl;
        cout<<"Would you like enter a new house cost and down payment?\n";
        cout<<"Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno; 
    }        
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 9 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem6(){
    cout<<"Inside Question 9"<<endl;
    //Declaration of variables
    float height, //User's height in inches
          weight, //User's weight in pounds
          hatsize, //Size of user's hat
          jktsize, //Size of user's jacket
          jktsze1, //Size of user's hat if age > 39
          waist, //Size of user's waist
          waist1, //Size of user's waist if age > 29
          age, //User's age in years
          ageRem1, //Remainder of age > 29
          ageRem2; //Remainder of age > 39
    
    //Initial output; Variable initiation
    cout<<"This program will computer your clothing size!\n";
    cout<<"What is your height in inches?\n";
    cin>>height;
    cout<<"What is your weight in pounds?\n";
    cin>>weight;
    cout<<"Now, enter your age.\n";
    cin>>age;
    
    //Process variables
    hatsize=(weight/height)*2.9; //Formula for hat size
    jktsize=(height*weight)/288.0; //Formula for jacket size
    waist=(weight/5.7); //Formula for waist size
    
    //First if age between 30 and 39 to calculate ONLY new waist size
    if(age>29&&age<40){
        ageRem1=(age-28)/2; //Calculate remainder of age to get waist size
        waist1=waist+(ageRem1*0.1); //New waist size
        //Final output
        cout<<"Your hat size is "<<hatsize<<endl;
        cout<<"Your jacket size is "<<jktsize<<" inches"<<endl;
        cout<<"Your waist is "<<waist1<<" inches"<<endl;
        
    }
    //Second if age over 39 to calculate both new waist and new jacket size
    else if(age>39){
        ageRem1=(age-28)/2; //Calculate remainder of age to get waist size
        waist1=waist+(ageRem1*0.1); //New waist size
        ageRem2=(age-30)/10; //Calculate remainder of age to get jacket size
        jktsze1=jktsize+(ageRem2*0.8); //New jacket size
        //Final output
        cout<<"Your hat size is "<<hatsize<<endl;
        cout<<"Your jacket size is "<<jktsze1<<" inches"<<endl;
        cout<<"Your waist is "<<waist1<<" inches"<<endl;
    }
    //Else if age < 30 no change to clothing sizes
    else{
        //Final output
        cout<<"Your hat size is "<<hatsize<<endl;
        cout<<"Your jacket size is "<<jktsize<<" inches"<<endl;
        cout<<"Your waist is "<<waist<<" inches"<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 13 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem7(){
    cout<<"Inside Question 13"<<endl;
    //Declaration of variables
    string  tenDig, //Tenth digit string
            sglDig, //Single digit string
            tenDig1, //Secondary Tenth digit string
            sglDig1, //Secondary Single digit string
            teens, //Ten-Nineteen string
            teens1; //Secondary Ten-Nineteen string
    short n=99; //Counter for loop
    
    //Initial output
    cout<<"Welcome to the song, 99 Bottle of Beer on the Wall!\n"<<endl;
    
    //Loop to output each phrase of 99 bottles (99->0)
    while(n>0){
        switch(n/10){ //First switch
            case 9:tenDig="Ninety";tenDig1="Eighty";break;
            case 8:tenDig="Eighty";tenDig1="Seventy";break;
            case 7:tenDig="Seventy";tenDig1="Sixty";break;
            case 6:tenDig="Sixty";tenDig1="Fifty";break;
            case 5:tenDig="Fifty";tenDig1="Forty";break;
            case 4:tenDig="Forty";tenDig1="Thirty";break;
            case 3:tenDig="Thirty";tenDig1="Twenty";break;
            case 2:tenDig="Twenty";break;
            case 0:tenDig="Ninety";break;
        }
        switch(n%10){ //Second switch
            case 9:sglDig="Nine";sglDig1="Eight";teens="Eighteen";teens1="Nineteen";break;
            case 8:sglDig="Eight";sglDig1="Seven";teens="Seventeen";teens1="Eighteen";break;
            case 7:sglDig="Seven";sglDig1="Six";teens="Sixteen";teens1="Seventeen";break;
            case 6:sglDig="Six";sglDig1="Five";teens="Fifteen";teens1="Sixteen";break;
            case 5:sglDig="Five";sglDig1="Four";teens="Fourteen";teens1="Fifteen";break;
            case 4:sglDig="Four";sglDig1="Three";teens="Thirteen";teens1="Fourteen";break;
            case 3:sglDig="Three";sglDig1="Two";teens="Twelve";teens1="Thirteen";break;
            case 2:sglDig="Two";sglDig1="One";teens="Eleven";teens1="Twelve";break;
            case 1:sglDig="One";sglDig1="Zero";teens="Ten";teens1="Eleven";break;
            case 0:sglDig="Zero";sglDig1="Nine";teens="Nineteen";teens1="Ten";break;
        }
        if(n>20&&n<100){ //Bottle count between 100 and 20
            //End of current tenth
            if(sglDig=="One"){
                cout<<tenDig<<"-"<<sglDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<"-"<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig<<" bottles of beer on the wall!\n"<<endl;
            }
            //End of current tenth--> beginning of next
            else if(sglDig=="Zero"){
                cout<<tenDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig1<<"-"<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
            //Body of current tenth
            else{
                cout<<tenDig<<"-"<<sglDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<"-"<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig<<"-"<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
        }
        else if(n>9&&n<=20){//Bottle count between 9 and 21
            //21 bottles --> 20 bottles
            if(n/10==2&&sglDig=="One"){
                cout<<tenDig<<"-"<<sglDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<"-"<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig<<" bottles of beer on the wall!\n"<<endl;
            }
            //Ends 10-19 bottles --> 9 bottles
            else if(n/10==1&&sglDig=="One"){
                cout<<teens1<<" bottles of beer on the wall,\n";
                cout<<teens1<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<teens<<" bottles of beer on the wall!\n"<<endl;
            }
            //Beginning of 19 bottles (20-->19)
            else if(n/10==2&&sglDig=="Zero"){
                cout<<tenDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<teens<<" bottles of beer on the wall!\n"<<endl;
            }
            //Beginning of final count (10-->9-0)
            else if(n/10==1&&sglDig=="Zero"){
                cout<<teens1<<" bottles of beer on the wall,\n";
                cout<<teens1<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
            //19 Bottles to 10 bottles
            else{
                cout<<teens1<<" bottles of beer on the wall,\n";
                cout<<teens1<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<teens<<" bottles of beer on the wall!\n"<<endl;
            }  
        }
        else{ //9 Bottles to 0 bottles
            //Format text "bottle/bottles for one bottle (2->1)
            if(sglDig1=="One"){
                cout<<sglDig<<" bottles of beer on the wall,\n";
                cout<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottle of beer on the wall!\n"<<endl;
            }
            //Format text "bottle/bottles for one bottle (1->0)
            else if(sglDig=="One"){
                cout<<sglDig<<" bottle of beer on the wall,\n";
                cout<<sglDig<<" bottle of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
            //9 Bottles -> 2
            else{
                cout<<sglDig<<" bottles of beer on the wall,\n";
                cout<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
        }
        n--; //Decrement loop counter
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 14 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem8(){
    cout<<"Inside Question 14"<<endl;
    //Declaration of variables
    short n=1; //Counter for servings of food needed
    float weight, //User's body weight
          bmRate, //Calories required for Basal Metabolic rate
          physAct, // Calories required for physical activity
          foodDig, //Calories required for the energy for food digestion
          calor, // Amount of calories in one serving of favorite food
          calor1, //Favorite food calorie holder
          totCal, //Total calories consumed before digestion
          mins, //Time user exercises in minutes
          intsty; //Intensity value of exercise
    
    //Initial output; variable initiation
    cout<<"This program will tell you how many servings of your favorite food\n";
    cout<<"that you will need to consume to maintain your current weight!\n";
    cout<<"What is your current weight in pounds?\n";
    cin>>weight;
    cout<<"How long will you be exercising today? (Input time in minutes)\n";
    cin>>mins;
    cout<<"What is the intensity of your exercise? (Input a positive whole number)\n";
    cin>>intsty;
    cout<<"Finally, how many calories are in one serving of your favorite food?\n";
    cin>>calor;
    
    //Process variables
    bmRate=70*(pow((weight/2.2),0.756)); //Formula for Basal Metabolic rate
    physAct=0.0385*intsty*weight*mins; //Formula for calories burned during Physical Activity
    totCal=bmRate+physAct; //Process total calories needed before food digestion
    foodDig=calor*0.1; //Energy needed to digest a serving of food
    calor1=calor; //Holds value of calorie count of person's favorite food
    
    //Loop until calorie consumption meets total calories needed
    while(calor<totCal){
        totCal=foodDig+totCal; //New total calories needed with digestion
        calor=calor1+calor; //New total calories consumed with each serving of food
        n++; //Counts each added serving needed
    }
    //Final output number of servings of food needed per day to maintain body weight
    cout<<"It will take "<<n<<" servings of your favorite food to\n";
    cout<<"maintain your current weight!\n";
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 15 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem9(){
    cout<<"Inside Question 15"<<endl;
    //Declaration of variables
    float coin, //Currency user enters
          n=0; //Holder for loop/total money entered in vending machine
    
    //Initial output
    cout<<"Get your hot and fresh, Deep-Fried Twinkies here! Only $3.50!\n"<<endl;
    
    //Loop for calculating change until enough has been entered for a twinkie
    while(n<3.5)
    {
        //Output; Variable initiation
        cout<<"Enter your coin.(1 = Dollar,0.25 = Quarter, 0.10 = Dime, 0.05 = Nickel.\n";
        cout<<"No pennies allowed!\n";
        cin>>coin;
        //Process variables
        n=n+coin; //Total amount of coins entered
        cout<<"Your current total is $"<<n<<endl; //Output current total
    }
    //Final output if user receives change
    if(n>3.5){
        cout<<"Enjoy your Deep-Fried Twinkie!\n";
        cout<<"Your change is $"<<(n-3.5)<<endl;
    }
    //Final output if no change to be received
    else{
        cout<<"Enjoy your Deep-Fried Twinkie!\n";
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Question 16 ****************************************
//Purpose:  Put function purpose here!
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void problem10(){
    cout<<"Inside Question 16"<<endl;
    //Declaration of variables
     string ampm, //Am or pm of first time
           ampm1; //Am or pm of second time
    int hrs, //Hours of first time
        hrs1, //Hours of second time
        hrs2,
        min, //Minutes of first time
        min1, //Minutes of second time
        min2,
        totMin;
    
    //Initial outputs; Variables initiated
    cout<<"This program calculates the difference, in minutes, between two set times!\n";
    cout<<"What is the hour of your initial time?\n";
    cin>>hrs;
    cout<<"What is the minute of your initial time?\n";
    cin>>min;
    cout<<"Is it am or pm? Enter 'am' or 'pm'\n";
    cin>>ampm;
    cout<<"Now, what is the hour of your ending time?\n";
    cin>>hrs1;
    cout<<"What is the minute of your ending time?\n";
    cin>>min1;
    cout<<"Is it am or pm? Enter 'am' or 'pm'\n";
    cin>>ampm1;
    
    //Process values
    if(hrs1<hrs&&ampm!=ampm1){
       
       if(min>min1){
           hrs2=(11-hrs)+hrs1;
           min2=(60-min)+min1;
       }
       else{
           hrs2=(12-hrs)+hrs1;
           min2=abs(min1-min);
       }
    }
    //Process values
    else if(hrs1<hrs&&ampm==ampm1){
       hrs2=24-(hrs-hrs1);
       min2=abs(min1-min); 
    }
    //Process values
    else if(hrs1>hrs){
        if(min>min1){
           hrs2=abs(hrs1-hrs-1);
           min2=abs(60-min)+min1; 
        }
        else{
            hrs2=abs(hrs1-hrs);
            min2=abs(min1-min);
        } 
    }
    //Process values
    else if(hrs1==hrs){
        hrs2=hrs1-hrs;
        if(min<min1){
            min2=min1-min;
        }
        else if(min>min1){
            min2=(23*60)+(min1+min);
        }
    }
    //If statement
    if(hrs2>0&&ampm==ampm1){
        totMin=min2+(hrs2*60);
        cout<<"The difference in time is "<<totMin<<" minutes.\n";
    }
    else if(hrs2>0&&ampm!=ampm1){
        totMin=min2+(hrs2*60);
        cout<<"The difference in time is "<<totMin<<" minutes.\n";
    }
    else if(hrs2==0){
        cout<<"The difference in time is "<<min2<<" minutes.\n";
    }
}