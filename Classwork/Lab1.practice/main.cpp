/* 
 File: main
 Author: Ryan Sorice
 Created on 15 February 2017 10:49 AM
 */

#include <iostream>
#include <string>
#include <Character.h>

using namespace std;

int main(){
	
	auto Finn=Character("Finn", 14);
	auto Jake=Character("Jake", 28);
	auto Marceline=Character("Marceline", 1000, "vampire");
	cout<<Finn.Greet()<<endl;
	cout<<Jake.Greet()<<endl;

	getchar();
	return 0;
}