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
    const T *index(int index);
    void insert(T *value, int index=-1);
    const T *remove(int index=-1);
    void reverse();
    const LLNode<T> *iter();
    std::string str();
};
