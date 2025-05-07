/*
 * Header for the common structures used within the code.
 *
 * Made by David Xchel Morales Hurtado
 */
#ifndef STRUCTS
#define STRUCTS

#include <cstdlib>
#include <iostream>

template <typename T>
class LLNode{
    /* LinkedList Node class with pointer to next node and a value. */
public:
    T *value;
    LLNode<T> *next;

    LLNode(T *value=NULL, LLNode<T> *next=NULL);
    ~LLNode();
};

template <typename T>
class LinkedList{
    /* LinkedList class with pointer to head node and functions for inserting, removing, reversing and readable representation. */
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

template <typename T, typename Y>
class MNode{
    /* Map Node class with different key and value types. */
    T *key;
    Y *value;

public:
    MNode(T key=NULL, Y *value=NULL);
};

template <typename T, typename Y>
class Map{
    /* Map class with the size of the hash table, along with number of elements and the MNode map with the elements. */
    int size;
    int elements;
    MNode<T, Y> *map;

public:
    Map(int size=10, T key=NULL, Y *value=NULL);
    ~Map();
    T *get(T *key);
    void set(T *key, Y *value);
    T *keys(void);
    MNode<T, Y> *items(void);
    Y *remove(T *key);
};
#endif

