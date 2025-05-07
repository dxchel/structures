#ifndef STRUCTS
#define STRUCTS

#include <cstdlib>
#include <iostream>

template <typename T>
class LLNode{
public:
    T *value;
    LLNode<T> *next;

    LLNode(T *value=NULL, LLNode<T> *next=NULL);
};

template <typename T>
class LinkedList{
    int length;
    LLNode<T> *head;

public:
    LinkedList(T *value=NULL);
    ~LinkedList();
    T *index(int index);
    void insert(T *value, int index=-1);
    T *remove(int index=-1);
    void reverse();
    void print();
};

template <typename T>
class MNode{
    int key;
    T *value;

public:
    MNode(int key=0, T *value=NULL);
};

template <typename T>
class Map{
    int size;
    int elements;
    T *map;

public:
    Map(int size=10, int key=0, T *value=NULL);
    ~Map();
    T *get(int key);
    void set(int key, T *value);
    int* keys(void);
    MNode<T> *items(void);
    T *remove(int key);
};
#endif

