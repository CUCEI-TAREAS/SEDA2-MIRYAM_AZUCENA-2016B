#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "node.h"
#include "node.cpp"
 
using namespace std;
 
template <class T>
 
class List
{
    public:
        List();
        ~List();
 
        void add_head(T);
        void add_end(T);
        void add_sort(T);
        void concat(List);
        void del_all();
        void del_by_data(T);
        void del_by_position(int);
        void fill_by_user(int);
        void fill_random(int);
        void intersection(List);
        void invert();
        void load_file(string);
        void print();
        void save_file(string);
        void search(T);
        void sort();

        void quickSort();
        void quickSort(int, int);

        T getData_by_position(int);
        Node<T>* getNode_by_position(int);
        void change(Node<T>*, Node<T>*);


        Node<T> *head() const;
        void setHead(Node<T> *head);

private:
        Node<T> *m_head = nullptr;
        int m_num_nodes;
};
 
#endif // LIST_H
