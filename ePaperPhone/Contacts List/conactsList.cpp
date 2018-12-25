//
//  main.cpp
//  Contacts List
//
//  Created by Sankalp Agrawal on 24/11/18.
//  Copyright © 2018 Sankalp Agrawal. All rights reserved.
//

#include <iostream>
#include <fstream>

typedef std::string STR;
using namespace std;

class profile{
public:
    //profile(int a, STR b): age(a), name(b){}
    STR getNameVal(){
        return name;
    }
    void setNameVal(STR b){
        name = b;
    }
    int getAgeVal(){
        return age;
    }
    void setAgeVal(int a){
        age = a;
    }
private:
    int age;
    STR name;
};

class NodeParent{
public:
    struct node{
        profile *data;
        struct node *next;
        struct node *prev;
    };
    virtual void displayData() = 0;
    
    bool addElement();
    bool deleteElement();
    
    int getData();
    int setData();
    
protected:;
private:
};



class LinkedList : public NodeParent{
public:
    LinkedList(){
        initlinkedList();
    }
    void displayData();
    void addMoreProfile(profile *p);
protected:;
private:
    int setLimit;
    void initlinkedList();
    int putData = 0;
    struct node *LLhead;
    struct node *LLtail;
    struct node *LLref;
    struct node *LLn;
};
void LinkedList::initlinkedList(){
    profile *p = new profile;
    p->setAgeVal(0);
    p->setNameVal("init");
    LLn = new node;
    LLn -> data = p;
    LLn -> next = NULL;
    LLhead = LLn;
    LLref  = LLn;
}

void LinkedList::addMoreProfile(profile *p){
    LLn = new node;
    LLn -> data = p;
    LLn -> next = NULL;
    LLhead->next = LLn;
    LLhead = LLhead->next;
}

void LinkedList::displayData(){
    while (LLref != NULL) {
        cout << LLref->data->getAgeVal() << endl;
        cout << LLref->data->getNameVal() << endl;
        LLref = LLref -> next;
    }
}


class DataManipulation : public LinkedList{
public:
    void addNewEntry(int age, STR name);
    void displayEntries();
};

void DataManipulation::addNewEntry(int age, STR name){
    profile *p = new profile;
    p->setAgeVal(age);
    p->setNameVal(name);
    addMoreProfile(p);
}
void DataManipulation::displayEntries(){
    displayData();
}

int main(int argc, const char * argv[]) {
    
    
    DataManipulation data;
    data.addNewEntry(13, "sankalp");
    data.addNewEntry(14, "ankur");
    data.addNewEntry(15, "ayush");
    data.displayEntries();
    
    
    return 0;
}
