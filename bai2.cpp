#include<iostream>
using namespace std;
class Node{
	private:
		int data;
		Node*next;
	public:
	Node(int value): data(value), next(NULL){
	}
	Node*getNext(){
		return next;
	}
	int getData(){
		return data;
	}
	//pthuc cap nhat node tiep theo trong ds
	void setNext(Node* n){
		next= n;//gan con tro next tro toi node n
	}
	//pthuc cap nhat giatri nguyen trg node
	void setData(int value){
		data=value;//gan giatri moi value cho data
	}
};
class LinkedList{
	private:
		Node*head;
		Node*tail;
	public:	
	LinkedList(): head(NULL),tail(NULL){
	}
	void addHead(int value){
		Node*newNode = new Node(value);
		if(head == NULL){
			head = tail = newNode;
		}
		else{
			newNode->setNext(head);
			head = newNode;
		}
	}
	void addTail(int value){
		Node*newNode = new Node(value);
		if(head == NULL){
			head = tail = newNode;
		}
		else{
			tail->setNext(newNode);
			tail = newNode;
		}
	}
	void printList(){
		for(Node*p = head; p != NULL; p = p->getNext()){
			cout << p->getData() << " ";
		}
		cout << endl;
	}
};
int main(){
  Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    node1->setNext(node2);
    node2->setNext(node3);
     node3->setNext(node4);
    node4->setNext(NULL);
    for(Node*p=node1;p!=NULL;p=p->getNext()){
    	cout<<p->getData()<<" ";
	}
	cout << endl;
	int sum=0;
	for(Node*p=node1;p!=NULL;p=p->getNext()){
		sum+= p->getData();
	}
	cout << sum<<endl;;
}