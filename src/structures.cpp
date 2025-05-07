#include "headers/structures.hpp"

template <typename T>
LLNode<T>::LLNode(T *value, LLNode<T> *next)
    : value(value), next(next){};


template <typename T>
LinkedList<T>::LinkedList(T *value)
    :length(0), head(NULL) {
    if(!value) return;

    this->head = new LLNode<T>(value);
    this->length = 1;
};
template <typename T>
LinkedList<T>::~LinkedList(){
    LLNode<T> *prev = this->head;
    LLNode<T> *next = prev;
    while(next){
        next = prev->next;
        delete prev;
        prev = next;
    }
};

template <typename T>
T *LinkedList<T>::index(int index){
    if(index >= this->length) index = this->length - 1;
    else index = index%this->length;
    LLNode<T> *element = this->head;
    for(int i=0; i < index; i++) element = element->next;
    return element->value;
};
template <typename T>
void LinkedList<T>::insert(T *value, int index){
    if(index >= this->length) index = this->length;
    if(index < -this->length*2) index = 0;
    index = (index + this->length + 1)%(this->length + 1);
    LLNode<T> *prev = NULL;
    LLNode<T> *element = this->head;
    for(int i=0; i < index; i++){
        prev = element;
        element = element->next;
    }
    element = new LLNode<T>(value, element);
    if(prev) prev->next = element;
    else this->head = element;
    this->length += 1;
    return;
};
template <typename T>
T *LinkedList<T>::remove(int index){
    if(!this->length) return NULL;
    if(index >= this->length) index = this->length - 1;
    if(index < -this->length*2) index = 0;
    index = (index + this->length)%this->length;
    LLNode<T> *prev = NULL;
    LLNode<T> *next = this->head;
    for(int i=0; i < index; i++){
        prev = next;
        next = next->next;
    }
    if(prev) prev->next = next->next;
    else this->head = next->next;
    this->length -= 1;
    T *value = next->value;
    delete next;
    return value;
};
template <typename T>
void LinkedList<T>::reverse(){
    LLNode<T> *prev = NULL;
    LLNode<T> *last = NULL;
    LLNode<T> *next = this->head;
    while(next){
        prev = next;
        next = next->next;
        prev->next = last;
        last = prev;
    }
    this->head = prev;
};
template <typename T>
void LinkedList<T>::print(){
    LLNode<T> *element = this->head;
    printf("[ ");
    while(element){
        std::cout << element->value << " ";
        element = element->next;
    }
    std::cout << "]" << std::endl;
};
