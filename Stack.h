/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: sai2468
 *
 * Created on March 18, 2019, 11:00 PM
 */
#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H
struct StackNode
{
   string Number;
   StackNode *Next;
};
class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   void Push(string Number);
   void Pop(string &Number);
   string Top(string &Number);
   int GetLength();
   void Print();

 private:
   StackNode *Head;
   int Length;
};

#endif /* STACK_H */

