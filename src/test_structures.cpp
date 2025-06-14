/*
 * Code for the test cases used to check the correct functionality of the structures.
 *
 * Made by David Xchel Morales Hurtado
 */
#include "headers/test_structures.hpp"
#include "headers/structures_examples.hpp"

int test_LinkedList(){
    /* 
     * Make a series of operations on LinkedList for functionality check.
     */
    printf("Creating list");
    LinkedList<int> *list = new LinkedList<int>();
    std::cout << list->str() << std::endl;
    printf("Adding 1 ");
    list->insert(1);
    std::cout << list->str() << std::endl;
    printf("Adding 2 ");
    list->insert(2);
    std::cout << list->str() << std::endl;
    printf("Adding 3 ");
    list->insert(3);
    std::cout << list->str() << std::endl;
    printf("Adding 4 ");
    list->insert(4);
    std::cout << list->str() << std::endl;
    printf("Adding 5 into 2 ");
    list->insert(5, 2);
    std::cout << list->str() << std::endl;
    printf("Adding 0 into 0 ");
    list->insert(0, 0);
    std::cout << list->str() << std::endl;
    printf("Adding 6 into 2 ");
    list->insert(6, 2);
    std::cout << list->str() << std::endl;
    printf("Adding -1 into -1 ");
    list->insert(-1, -1);
    std::cout << list->str() << std::endl;
    printf("Adding 100 into 100 ");
    list->insert(100, 100);
    std::cout << list->str() << std::endl;
    list->reverse();
    std::cout << "And now reversed!" << list->str() << std::endl;
    std::cout << "Here's index 4! " << list->index(4) << list->str() << std::endl;
    std::cout << "Using iterator in for loop" << std::endl;
    LLNode<int> *iter = list->iter();
    while(iter){
        std::cout << "Element " << iter->value << std::endl;
        iter = iter->next;
    }
    delete iter;
    list->remove(3);
    std::cout << "Removing index 3: " << list->str() << std::endl;
    list->remove(-1);
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove(20);
    std::cout << "Removing index 20 (non existent): " << list->str() << std::endl;
    list->remove(0);
    std::cout << "Removing first index: " << list->str() << std::endl;
    list->remove();
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove();
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove();
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove();
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove();
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove();
    std::cout << "Removing last index: " << list->str() << std::endl;
    list->remove();
    delete list;
    return 0;
};

int test_Tree(){
    /* 
     * Make a series of operations on Tree for functionality check.
     */
    printf("Creating map \n");
    Tree<int> *tree = new Tree<int>();
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Creating tree:\n");
    printf("             5\n"
           "        2         7\n"
           "      1   3     6   9\n"
           "   -1       4      8  10\n");
    tree->insert(5);
    tree->insert(2);
    tree->insert(1);
    tree->insert(-1);
    tree->insert(3);
    tree->insert(4);
    tree->insert(7);
    tree->insert(6);
    tree->insert(9);
    tree->insert(10);
    tree->insert(8);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("Finding 7 \n");
    std::cout << (tree->find(7) ? tree->find(7)->value : 0) << std::endl;
    printf("Finding 11 \n");
    std::cout << (tree->find(11) ? tree->find(11)->value : 0) << std::endl;
    printf("Adding 10 \n");
    tree->insert(10);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("deleting 1 \n");
    tree->remove(1);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("deleting 7 \n");
    tree->remove(7);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("deleting 2 \n");
    tree->remove(2);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    printf("deleting 5 (BASE) \n");
    tree->remove(5);
    std::cout << tree->str() << " Size: " << tree->get_size() << std::endl;
    delete tree;
    return 0;
};
