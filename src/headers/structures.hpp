/*
 * Header for the common structures used within the code.
 *
 * Made by David Xchel Morales Hurtado
 */
#ifndef STRUCTS
#define STRUCTS

#include <cstdlib>
#include <iostream>
#include <string>

template <typename T>
class LLNode;
template <typename T>
class LinkedList;

template <typename T>
class LLNode{
    /* LinkedList Node class with pointer to next node and a value. */
    T *value;
    LLNode<T> *next;

public:
    LLNode(T *value=NULL, LLNode<T> *next=NULL);
    ~LLNode();
    LLNode<T> *get_next();
    void set_next(LLNode<T> *next);
    T *get_value();
    void set_value(T *next);
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
    LLNode<T> *iter();
    std::string str();
};
#endif
