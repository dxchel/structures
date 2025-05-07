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
    LinkedList<int> *list = new LinkedList<int>(new int(5));
    list->print();
    printf("Adding 2 ");
    list->insert(new int(2));
    list->print();
    printf("Adding 3 ");
    list->insert(new int(3));
    list->print();
    printf("Adding 4 ");
    list->insert(new int(4));
    list->print();
    printf("Adding 5 into 2 ");
    list->insert(new int(5), 2);
    list->print();
    printf("Adding 0 into 0 ");
    list->insert(new int(0), 0);
    list->print();
    printf("Adding 6 into 2 ");
    list->insert(new int(6), 2);
    list->print();
    printf("Adding -1 into -1 ");
    list->insert(new int(-1), -1);
    list->print();
    printf("Adding 100 into 100 ");
    list->insert(new int(100), 100);
    list->print();
    std::cout << "Here's index 4! " << *list->index(4) << std::endl;
    list->reverse();
    printf("And now reversed! ");
    list->print();
    std::cout << "Removing index 3: " << *list->remove(3) << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing index 20 (NULL): " << list->remove(20) << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index: " << *list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index (NULL): " << list->remove() << std::endl;
    list->print();
    std::cout << "Removing last index (NULL): " << list->remove() << std::endl;
    list->print();
    delete list;
    return 0;
};
