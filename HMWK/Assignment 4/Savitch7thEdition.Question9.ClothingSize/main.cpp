/* File: main
 * Author: Ryan Sorice
 * Created on 12 October 2016 2:01 PM
 * Purpose: Compute users clothing size given their height, weight and age.  */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
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
    //Exit program
    return 0;
}

