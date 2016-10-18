/* File: main
 * Author: Ryan Sorice
 * Created on 16 October 2016 10:40 AM 
 * Purpose: Calculate how many servings of food(Calories) the user needs to eat to 
 *          maintain their body weight in respects to the Basal metabolic rate,
 *          the physical activity being performed and the energy needed to digest
 *          food.                                                                  */

//System libraries
#include <iostream> //Inputs and outputs
#include <cmath> //Math library for power function

using namespace std; //Namespace in system library

//Execution begins here
int main(int argc, char** argv) {
    
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

    //Exit programs
    return 0;
}

