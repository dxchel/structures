/*
 * Main structures code.
 * Here lies the code for the basic structures taken into account.
 *
 * Made by David Xchel Morales Hurtado
 */
#include "headers/structures.hpp"

template <typename T>
LLNode<T>::LLNode(T *value, LLNode<T> *next)
    : value(value), next(next){};
template <typename T>
LLNode<T>::~LLNode(){
    delete this->value;
};
template <typename T>
T *LLNode<T>::get_value(){
    /* Returns a constant pointer to the value. */
    return this->value;
};
template <typename T>
LLNode<T> *LLNode<T>::get_next(){
    /* Returns a constant pointer to the next element linked. */
    return this->next;
};
template <typename T>
void LLNode<T>::set_next(LLNode<T> *next){
    /* Changes the pointer to the next element linked. */
    this->next = next;
    return;
};
template <typename T>
void LLNode<T>::set_value(T *value){
    /* Changes the pointer to the value. */
    this->value = value;
    return;
};


template <typename T>
LinkedList<T>::LinkedList(T *value)
    :length(0), head(NULL) {
    /* Initialize everything to an empty LinkedList, if a value is given use it to make a node. */
    if(!value) return;

    this->head = new LLNode<T>(value);
    this->length = 1;
};
template <typename T>
LinkedList<T>::~LinkedList(){
    /* Delete all LinkedList Nodes. */
    LLNode<T> *prev = this->head;
    LLNode<T> *next = prev;
    while(next){
        next = prev->get_next();
        delete prev;
        prev = next;
    }
};

template <typename T>
T *LinkedList<T>::index(int index){
    /*
     * Get the element value at specific Index.
     * If negative index is used it will start from the last element, being -1 the last element.
     * If the index is out of bounds, return NULL.
     */
    if(index >= this->length || index <= -this->length) return NULL;
    else index = index%this->length;
    LLNode<T> *element = this->head;
    for(int i=0; i < index; i++) element = element->get_next();
    return element->get_value();
};
template <typename T>
void LinkedList<T>::insert(T *value, int index){
    /*
     * Insert the value as the node at index, default is to insert at the end.
     * If negative index is used it will start from the last element, being -1 to insert after last element.
     * If the index is out of bounds, return and do nothing.
     */
    if(index >= this->length || index < -this->length) return;
    index = (index + this->length + 1)%(this->length + 1);
    // Keep track of previous node for linking.
    LLNode<T> *prev = NULL;
    LLNode<T> *element = this->head;
    for(int i=0; i < index; i++){
        prev = element;
        element = element->get_next();
    }
    element = new LLNode<T>(value, element);
    // Linking.
    if(prev) prev->set_next(element);
    else this->head = element;
    this->length += 1;
    return;
};
template <typename T>
T *LinkedList<T>::remove(int index){
    /*
     * Remove the node at index, default is to remove the last one.
     * If negative index is used it will start from the last element, being -1 the last element.
     * If the index is out of bounds, return NULL and do nothing.
     */
    if(!this->length || index < -this->length || index >= this->length) return NULL;
    index = (index + this->length)%this->length;
    // Keep track of previous node for linking.
    LLNode<T> *prev = NULL;
    LLNode<T> *next = this->head;
    for(int i=0; i < index; i++){
        prev = next;
        next = next->get_next();
    }
    // Linking and node deletion.
    if(prev) prev->set_next(next->get_next());
    else this->head = next->get_next();
    this->length -= 1;
    T *value = new T(*next->get_value());
    delete next;
    return value;
};
template <typename T>
void LinkedList<T>::reverse(){
    /* Reverse the whole LinkedList, using tail as head and linking from there. */
    LLNode<T> *prev = NULL;
    LLNode<T> *last = NULL;
    LLNode<T> *next = this->head;
    while(next){
        prev = next;
        next = next->get_next();
        prev->set_next(last);
        last = prev;
    }
    this->head = prev;
};
template <typename T>
LLNode<T> *LinkedList<T>::iter(){
    /* Get iterator by getting first element. */
    return this->head;
};
template <typename T>
std::string LinkedList<T>::str(){
    /* Print the LinkedList in a readable way. */
    std::string representation = "[ ";
    LLNode<T> *element = this->head;
    while(element){
        representation += std::to_string(*element->get_value()) + " ";
        element = element->get_next();
    }
    representation += "]";
    return representation;
};

