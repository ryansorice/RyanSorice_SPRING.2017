/*
 File: Character
 Author: Ryan Sorice
 Created on 15 February 2017 10:46AM
 */

#pragma once
#include <string>
using namespace std;

class Character
{
    private:
        int age;	
        string name, race;

    public:
        bool SetAge(int);
        string Greet();
        Character(string, int);
        Character(string, int, string);
        ~Character();
};