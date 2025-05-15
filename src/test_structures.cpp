/*
 * Code for the test cases used to check the correct functionality of the structures.
 *
 * Made by David Xchel Morales Hurtado
 */
#include "headers/test_structures.hpp"
#include "headers/structures_examples.hpp"

int test_LinkedList(){
    /* 
     * Make a series of operations on LinkedList for functionality check
     */
    printf("Creating list with 1 ");
    LinkedList<int> *list = new LinkedList<int>(new int(1));
    std::cout << list->str() << std::endl;
    printf("Adding 2 ");
    list->insert(new int(2));
    std::cout << list->str() << std::endl;
    printf("Adding 3 ");
    list->insert(new int(3));
    std::cout << list->str() << std::endl;
    printf("Adding 4 ");
    list->insert(new int(4));
    std::cout << list->str() << std::endl;
    printf("Adding 5 into 2 ");
    list->insert(new int(5), 2);
    std::cout << list->str() << std::endl;
    printf("Adding 0 into 0 ");
    list->insert(new int(0), 0);
    std::cout << list->str() << std::endl;
    printf("Adding 6 into 2 ");
    list->insert(new int(6), 2);
    std::cout << list->str() << std::endl;
    printf("Adding -1 into -1 ");
    list->insert(new int(-1), -1);
    std::cout << list->str() << std::endl;
    printf("Adding 100 into 100 ");
    list->insert(new int(100), 100);
    std::cout << list->str() << std::endl;
    list->reverse();
    std::cout << "And now reversed!" << list->str() << std::endl;
    std::cout << "Here's index 4! " << *(list->index(4)) << list->str() << std::endl;
    std::cout << "Using iterator in for loop" << std::endl;
    LLNode<int> *iter = list->iter();
    while(iter != NULL){
        std::cout << "Element " << *(iter->value) << std::endl;
        iter = iter->next;
    }
    delete iter;
    std::cout << "Removing index 3: " << *list->remove(3) << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing index 20 (NULL): " << list->remove(20) << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: " << *list->remove() << list->str() << std::endl;
    std::cout << "Removing last index: NULL" << list->remove() << list->str() << std::endl;
    delete list;
    return 0;
};
