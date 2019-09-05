/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sai2468
 *
 * Created on March 18, 2019, 4:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) { 
    ifstream din;
    string inputFile;
    cout << "Enter name of input file: ";
    getline(cin,inputFile);
    din.open(inputFile);
    Stack stack1;
    string place;
    char character;
    string tag;
    bool errorFound = false;
    bool firstCarrotFound = false;
    while(din >> character && !errorFound){
        if(character=='<'){
            firstCarrotFound = true;
        }
        if(stack1.IsEmpty()&&firstCarrotFound){
        tag = tag + character;
        if(tag.find('>')==tag.length()-1){
            stack1.Push(tag);
            cout << "tag: " << tag << endl;
            tag = "";
            firstCarrotFound = false;
            stack1.Print();
        }
        }
        else if(firstCarrotFound==true){
        tag =  tag + character;
        if(tag.find('>')==tag.length()-1){
            if((tag==stack1.Top(place)&&(tag=="<br>"||tag=="<hr>"||tag=="<img>"||tag=="<input>"||tag=="<meta>"))||(tag.substr(2,tag.length()-3)==stack1.Top(place).substr(1,tag.length()-3)&&tag.length()>3)){
                cout << "tag: " << tag << endl;
//                cout << "tag's length: " << tag.length() << endl;
//                cout << stack1.Top(place) << " is popped." << endl;
                stack1.Pop(place);
//                cout << "tag: " << tag << endl;
                tag = "";
                firstCarrotFound = false;
                stack1.Print();
            }
            else if(tag.length()<=3&&tag.substr(2,1)==stack1.Top(place).substr(1,1)&&stack1.Top(place).length()<=3){
                cout << "tag: " << tag << endl;
//                cout << "I got here!!!!!!!!"  << endl;
//                cout << stack1.Top(place) << " is popped." << endl;
                stack1.Pop(place);
//                cout << "tag: " << tag << endl;
                tag = "";
                firstCarrotFound = false;
                stack1.Print();
            }
            else if((tag.find('/')==1)&&(tag.substr(2,tag.length()-3)!=stack1.Top(place).substr(1,tag.length()-3))){
                cout << "tag: " << tag << endl;
                stack1.Print();
                cout << "Error found" << endl;
                errorFound = true;
            }
            else{
                stack1.Push(tag);
                cout << "tag: " << tag << endl;
                tag = "";
                firstCarrotFound = false;
                stack1.Print();
            }
        }
        }
    }
    if(stack1.IsEmpty()){
        cout << "Congratulations, the HTML tags are balanced" << endl;
    }
    else{
        cout << "Sorry, the HTML tags are not balanced" << endl;
    }
    return 0;
}

