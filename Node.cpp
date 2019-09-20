#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <process.h>
#include <time.h>

using namespace std;

#ifndef NODE_CPP
#define NODE_CPP
class Node{
	private:
		string value;
		Node* next_node;
	public:
		Node(){}
		
		Node(string value){
			this->value=value;
			next_node=NULL;
		}
		
		string getValue(){
			return value;
		}
		
		void setValue(string value){
			this->value=value;
		}
		
		Node* getNext(){
			return next_node;	
		}
		
		void setNext(Node* new_next_node){
			next_node=new_next_node;
		}
		
		void print(){
			cout<<"Resultado: "<<value<<endl;
		}
		
		~Node(){}
};
#endif
