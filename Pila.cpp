#include "Node.cpp"

using namespace std;

#ifndef PILA_CPP
#define PILA_CPP
class Pila{
	private:
		Node* head;
	public:
		Pila(){
			head = NULL;
		}
		
		void push(string valor){
		    if(head == NULL){
		    	head = new Node(valor);
			} else {
		        Node* temp = new Node(valor);        
		        temp->setNext(head);
		        head = temp;
		    }
		}
		
		Node* pop(){
			Node* temp = head;
			head = head->getNext();
			return temp;
		}
		
		Node* top(){
			return head;
		}
		
		bool isEmpty(){
		    if(head==NULL){
		    	return true;
			} else {
				return false;
			}
		}
		
		Node* getHead(){
		    return head;
		}
		
		~Pila(){}
};
#endif

