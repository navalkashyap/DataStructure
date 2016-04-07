/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: naval
 *
 * Created on April 3, 2016, 7:17 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

struct LLNode {
    int data1;
    LLNode* ref = NULL;
};

LLNode* traverse(LLNode* temp,int position) {
    for (int i=0; i< position; i++ ){
        temp = temp->ref;
        if (temp == NULL)
            return NULL;
    }
    return temp;
}

int push(int data, LLNode* start, int position) {
    LLNode* temp = traverse(start,position);
    if(temp == NULL) {
        return -1;
    } else {
        LLNode* startNode = new LLNode();
        startNode->data1 = data;
        startNode->ref = temp->ref;
        temp->ref = startNode;
        cout<<"Pushed "<<data<<" at position "<<position<<endl;
    }
    return 0;
}

int pull(LLNode* temp, int position) {
    temp = traverse(temp,position-1);
    int data;
    if(temp == NULL) {
        cout<<"Position requested is out of list"<<endl;
        return -1;
    } else {
        LLNode* startNode = new LLNode();
        data = temp->ref->data1;
        temp->ref = temp->ref->ref;
    }
    return data;
}

int LinkedList() {
    cout<<"Hello World\n";
    LLNode* startRef=new LLNode();
    LLNode* node1=new LLNode();
    LLNode* node2=new LLNode();
    LLNode* node3=new LLNode();
    startRef->data1=10;
    node1->data1=2;
    startRef->ref = node1;
    node2->data1=3;
    node1->ref = node2;
    node3->data1=400;
    node2->ref = node3;

    push(5,startRef,1);
    push(3,startRef,1);
    push(2,startRef,2);
   
    LLNode* temp = traverse(startRef,5);
    if(temp == NULL) {
        cout<<"Position requested is out of list"<<endl;
    } else {
        cout<<temp->data1<<endl<<temp->ref<<endl;
    }
    cout<<pull(startRef,6)<<endl;
    temp = traverse(startRef,5);
    if(temp == NULL) {
        cout<<"Position requested is out of list"<<endl;
    } else {
        cout<<temp->data1<<endl<<temp->ref<<endl;
    }
    return 0;
}
int main(int argc, char** argv) {
    LinkedList();
    return 0;
}