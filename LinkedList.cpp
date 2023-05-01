#include <limits>
#include <iostream>
#include "LinkedList.h"
LinkedList::LinkedList(){ //done
    head = nullptr;
}
LinkedList::LinkedList(int* array, int len){ //done
    for(int i=len;i>0;i--){
        insertPosition(1,array[i-1]);
    }

}
LinkedList::~LinkedList(){ 

}
void LinkedList::insertPosition(int pos, int newNum){ //done
    Node * newNode = new Node;
    newNode->data = newNum;
    if(pos==1){
        newNode->link=head->link;
        head->link = newNode;
    }
    else{
    Node * temp = traverse(pos-1);
    newNode->link = temp->link;
    temp->link=newNode;
    }
}
bool LinkedList::deletePosition(int pos){ //done
    Node * prev=head;
    int index;
    if(pos==1){
        Node * temp = head;
        head = head->link;
        delete temp;
        return true;
        
    }
    else{
        Node * prev = traverse(pos-1);
        if(prev->link==nullptr){
            return false;
        }
        Node * curr = prev->link;
        
        prev->link = curr->link;
        delete curr;
        return true;
    }
}

int LinkedList::get(int pos){ //done
    Node* temp = traverse(pos);
    if(temp == nullptr){
        return std::numeric_limits < int >::max();
    }
    else{
        return temp->data;
    }
}
int LinkedList::search(int target){

int index =1;
Node* currNode = head;
while (currNode != nullptr){ //done
currNode = currNode->link;
if(currNode->data==target){
    return index;
}
index++;
}
return -1;
}
void LinkedList::printList(){
    Node* currNode = head->link;
    std::cout<<"[";
while (currNode != nullptr) {
std::cout<< currNode->data;
currNode = currNode->link;
if(currNode != nullptr){
    std::cout<<" ";
}
}
std::cout<<"]"<< std::endl;
}

Node* LinkedList::traverse(int index){ //done
    int position = 0;
Node* currNode = head;
while (currNode != nullptr && position < index) {
currNode = currNode->link;
position++;
}
return currNode;
}
