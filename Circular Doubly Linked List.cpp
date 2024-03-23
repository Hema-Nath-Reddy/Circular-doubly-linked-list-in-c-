#include<iostream>
using namespace std;
struct node{
	node* next;
	int data;
	node* prev;
};
class CircularDoublyLinkedList{
	node* head=NULL;
	node* tail=NULL;
	public:
		void insertbeg(int data){
			node* newnode=new node();
			newnode->data=data;
			if(head==NULL){
				head=tail=newnode;
				newnode->next=newnode;
				newnode->prev=newnode;
			}else{
				newnode->next=head;
				newnode->prev=tail;
				tail->next=newnode;
				head->prev=newnode;
				head=newnode;
			}
			cout<<data<<" has been inserted at the beginning of the list successfully."<<endl;
		}
		void insertmiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->next==NULL){
				cout<<"Enter 1 or 3 based on the position you want to insert in the list."<<endl;
			}else{
				int index;
				cout<<"Enter index: ";
				cin>>index;
				if(index>count()||index<0){
					cout<<"Invalid index."<<endl;
				}else{
					cout<<"Enter data: ";
					int data;
					cin>>data;
					if(index==0){
						insertbeg(data);
					}else if(index==count()){
						insertend(data);
					}else{
						int c=1;
						node* temp=head;
						while(c!=index){
							c++;
							temp=temp->next;
						}
						node* temp2;
						node* newnode=new node();
						newnode->data=data;
						temp2=temp->next;
						temp->next=newnode;
						newnode->prev=temp;
						newnode->next=temp2;
						temp2->prev=newnode;
						cout<<data<<" has been inserted at index "<<index<<" successfully."<<endl;
					}			
				}
			}
		}
		void insertend(int data){
			node* newnode=new node();
			newnode->data=data;
			if(head==NULL){
				head=tail=newnode;
				newnode->next=newnode;
				newnode->prev=newnode;
			}else{
				tail->next=newnode;
				newnode->prev=tail;
				newnode->next=head;
				head->prev=newnode;
				tail=newnode;
			}
			cout<<data<<" has been inserted at the end of the list successfully."<<endl;
		}
		void deletebeg(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else {
				node* temp=head;
				if(head->next==NULL){
					head=tail=NULL;
				}else{
					head=head->next;
					head->prev=tail;
					tail->next=head;
				}
				
				cout<<temp->data<<" has been successfully deleted from the beginning of the list."<<endl;
				delete temp;
			}
		}
		void deletemiddle(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->next==NULL){
				deletebeg();
			}else{
				int index;
				cout<<"Enter index: ";
				cin>>index;
				if(index>count()||index<0){
					cout<<"Invalid index."<<endl;
				}else{
					if(index==0){
						deletebeg();
					}else if(index==count()){
						deletend();
					}else{
						int c=0;
						node* temp=head;
						node* temp2=NULL;
						while(c!=index){
							c++;
							temp2=temp;
							temp=temp->next;
						}
						node* temp3=temp->next;
						temp2->next=temp3;
						temp3->prev=temp2;
						cout<<temp->data<<" has been successfuly deleted from index "<<index<<"."<<endl;
						delete temp;	
					}
				}
			}
		}
		void deletend(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else if(head->next==NULL){
				node* temp=head;
				head=tail=NULL;
				cout<<temp->data<<" has been successfuly deleted from the end of the list."<<endl;
				delete temp;
			}
			else{
				node* temp=tail->prev;
				node* temp2=tail;
				temp->next=head;
				head->prev=temp;
				cout<<temp2->data<<" has been successfuly deleted from the end of the list."<<endl;
				delete temp2;
				tail=temp;
			}
			
		}
		void displayhead(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=head;
				cout<<"The elements of the list are: "<<endl;
				do{
					cout<<temp->data<<endl;
					temp=temp->next;
				}while(temp!=head);
			}
		}
		void displaytail(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				node* temp=tail;
				cout<<"The elements of the list are: "<<endl;
				do{
					cout<<temp->data<<endl;
					temp=temp->prev;
				}while(temp!=tail);
			}
		}
		int count(){
			if(head==NULL){
				return 0;
			}else if(head->next==NULL){
				return 1;
			}else{
				int c=0;
				node* temp=head;
				do{
					c++;
					temp=temp->next;
				}while(temp!=head);
				return c;
			}
		}
		void search(){
			if(head==NULL){
				cout<<"Empty list."<<endl;
			}else{
				int element;
				cout<<"Enter the element: ";
				cin>>element;
				node* temp=head;
				int c=0;
				bool found=false;
				do{		
					if(temp->data==element){
						found=true;
						break;
					}
					c++;
					temp=temp->next;
				}while(temp!=head);
				if(found){
					cout<<element<<" is present at index: "<<c<<endl;
				}else{
					cout<<element<<" is nor present in the list."<<endl;
				}
			}	
		}
};
int main(){
	CircularDoublyLinkedList c;
	int choice;
	do{
		cout<<endl<<"1. Insert an element in the beginning."<<endl;
		cout<<"2. Insert an element in the middle."<<endl;
		cout<<"3. Insert an element in the end."<<endl;
		cout<<"4. Delete an element in the beginning."<<endl;
		cout<<"5. Delete an element in the middle."<<endl;
		cout<<"6. Delete an element in the end."<<endl;
		cout<<"7. Display the list(from head)."<<endl;
		cout<<"8. Display the list(from tail)."<<endl;
		cout<<"9. Count the number of the nodes in the list."<<endl;
		cout<<"10. Search for an element in the list."<<endl;
		cout<<"11. Exit."<<endl<<endl;
		int element;
		cout<<"Choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter data: ";
				int data;
				cin>>data;
				c.insertbeg(data);
				break;
			case 2:
				c.insertmiddle();
				break;
			case 3:
				int Data;
				cout<<"Enter data: ";
				cin>>Data;
				c.insertend(Data);
				break;
			case 4:
				c.deletebeg();
				break;
			case 5:
				c.deletemiddle();
				break;
			case 6:
				c.deletend();
				break;
			case 7:
				c.displayhead();
				break;
			case 8:
				c.displaytail();
				break;
			case 9:
				cout<<"The number of nodes in the list are: "<<c.count()<<endl;
				break;
			case 10:
				c.search();
				break;
			case 11:
				cout<<"Exited."<<endl;
				break;
			default:
				cout<<"Enter a choice from 1-11."<<endl;
				break;
		}
	}while(choice!=11);
	return 0;
}
