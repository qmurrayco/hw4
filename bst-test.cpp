#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    BinarySearchTree<uint16_t,uint16_t> bt;

		//testing InsertZigZigLeft
		bt.insert(std::make_pair(5, 8));
		// std::cout << "pass one" << std::endl;
		bt.insert(std::make_pair(3, 159));
		// std::cout << "pass two" << std::endl;
		bt.insert(std::make_pair(1, 9));
		// std::cout << "pass three" << std::endl;
		bt.insert(std::make_pair(10, 0x5a));
		// std::cout << "pass four" << std::endl;
		bt.insert(std::make_pair(15, 0xb));
		// std::cout << "pass five" << std::endl;
		// bt.insert(std::make_pair(2, 4));
		// std::cout << "pass six" << std::endl;
		// bt.insert(std::make_pair(4, 159));
		// std::cout << "pass seven" << std::endl;

		// bt.clear();

		// std::cout << "past clear" << std::endl;


    // bt.insert(std::make_pair('a',1));
    // bt.insert(std::make_pair('b',2));

    // cout << "Binary Search Tree contents:" << endl;
    // for(BinarySearchTree<int,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }


		// cout << "Erasing a" << endl;
		// bt.remove('a');

    // if(bt.find('a') != bt.end()) {
		// 	cout << "Found a" << endl;
    // }
    // else {
		// 	cout << "Did not find a" << endl;
    // }

		// std::cout << "Erasing b" << std::endl;
		// bt.remove('b');

    // if(bt.find('b') != bt.end()) {
		// 	cout << "Found b" << endl;
    // }
    // else {
		// 	cout << "Did not find b" << endl;
    // }

		// bt.remove('a');
		// bt.remove('b');

		//bt.clear();

    // bt.remove('b');

		// if(bt.find('b') != bt.end()){
		// 	cout << "B is still there after remove" << endl;
		// }else{
		// 	cout << "B was not found after remove" << endl;
		// }

		// bt.clear();

		// std::cout << "Beep" << std::endl;

		// if(bt.find('b') != bt.end()){
		// 	cout << "B was found after clear" << endl;
		// }

		// if(bt.find('a') != bt.end()){
		// 	cout << "A was found after clear" << endl;
		// }



    // // AVL Tree Tests
    // AVLTree<char,int> at;
    // at.insert(std::make_pair('a',1));
    // at.insert(std::make_pair('b',2));

    // cout << "\nAVLTree contents:" << endl;
    // for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(at.find('b') != at.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // at.remove('b');

    return 0;
}
