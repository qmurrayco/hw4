#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    bool isBalanced() const; //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2);

    // Add helper functions here
		static Node<Key, Value>* successor(Node<Key, Value>* current); //added
		void insertRecursion(const std::pair<const Key, Value> &keyValuePair, Node<Key, Value> *root);
		bool balanceRecursion(Node<Key, Value> *root, int pathVal, int lvl) const;

protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    // TODO
		current_ = ptr;
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
    // TODO
    current_ = NULL;
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
		// if(current_ == NULL || rhs.current_ == NULL){
		// 	if(current_ == NULL && rhs.current_ != NULL){return false;}
		// 	if(current_ != NULL && rhs.current_ == NULL){return false;}

		// 	return true;
		// }
    // return (current_->getKey() == (rhs.current_)->getKey()) && (current_->getValue() == (rhs.current_)->getValue());

		//is this what it wants? does this mean internals? or actual item internals?
		return (current_ == rhs.current_);
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
		// if(current_ == NULL || rhs.current_ == NULL){
		// 	if(current_ == NULL && rhs.current_ != NULL){return true;}
		// 	if(current_ != NULL && rhs.current_ == NULL){return true;}

		// 	return false;
		// }
    // return (current_->getKey() != (rhs.current_)->getKey()) && (current_->getItem() != (rhs.current_)->getItem());

		//same thing here, is this what it wants?
		return (current_ != rhs.current_);
}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
		Node<Key, Value> *success = BinarySearchTree::successor(current_);
		current_ = success;

		return *this;
}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    root_ = NULL;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
		clear();
}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);

    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{

	if(root_ == NULL){
		//tree is empty
		root_ = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, NULL);
		return;
	}

	//not empty
	//its either less than, greater than, or equal. three conditions
	//i cant think of any way to do this without recursion
	insertRecursion(keyValuePair, root_);
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::insertRecursion(const std::pair<const Key, Value> &keyValuePair, Node<Key, Value> *root)
{
	if(keyValuePair.first > root->getKey()){
		//go right
		if(root->getRight() != NULL){insertRecursion(keyValuePair, root->getRight());}
		else{
			Node<Key, Value> *newNode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, root);
			root->setRight(newNode); 
			return;
		}
	}
	else if(keyValuePair.first < root->getKey()){
		//go left
		if(root->getLeft() != NULL){insertRecursion(keyValuePair, root->getLeft());}
		else{
			Node<Key, Value> *newNode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, root);
			root->setLeft(newNode); 
			return;
		}
	}
	else{
		//must be equal..?
		root->setValue(keyValuePair.second);
	}
}

/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
    // TODO
		Node<Key, Value> *search, *child;
		search = internalFind(key);
		//doesnt exist, leave
		if(search == NULL){return;}


		//two children
		if(search->getRight() != NULL && search->getLeft() != NULL){
			Node<Key, Value> *pred, *succ;
			pred = predecessor(search);
			succ = successor(search);

			//figuring out what is the appropriate thing to swap with, predecessor or sucessor
			if(pred->getKey() < search->getLeft()->getKey()){
				//dont use pred use succ
				nodeSwap(search, succ);
			}else{
				//pred is the right choice
				nodeSwap(search, pred);
			}
		}

		//one child
		//after two children is handled we end up in one or zero children, but which?
		if(search->getRight() != NULL){
			//one child
			child = search->getRight();
		}

		else if(search->getLeft() != NULL){
			//one child
			child = search->getLeft();
		}

		else{
			//some leaf, zero children
			child = NULL;
		}

		//promote and handle ancestory
		if(search->getParent() != NULL){
			//find out what child I am 
			if(search == search->getParent()->getLeft()){
				//i am the left child, promote accordingly
				search->getParent()->setLeft(child);
			}else{
				//i am the right child, promote accordingly
				search->getParent()->setRight(child);
			}

			//null case
			if(child != NULL){
				child->setParent(search->getParent());
			}
		}

		
		else{
			//we must be at the root?
			root_ = child;
			if(child != NULL){
				root_->setParent(NULL);
			}
		}

		//clear memory, should be good to go
		delete search;

}



template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{
    // TODO
		//left child exists
		if(current->getLeft() != NULL){
			current = current->getLeft();
			while(current->getRight() != NULL){
				current = current->getRight();
			}

			return current;
		}else{
			//walk up ancestor chain until traverse to first right child
			while(current != NULL || current->getRight() == NULL){
				current = current->getParent();
			}

			if(current == NULL){return current;}
			else{return current->getRight();}
		}
}

template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key,Value>::successor(Node<Key, Value>* current)
{
	//right child exists
	Node<Key, Value> *walker = current;

	if(walker->getRight() != NULL){
		walker = walker->getRight();
		while(walker->getLeft() != NULL){
			walker = walker->getLeft();
		}

		return walker;
	}else{
		//right did not exist
		//walk up ancestor chain until traverse to first left child
		walker = walker->getParent();

		while(walker != NULL){
			if(walker->getLeft() != NULL && walker != current){return walker;}
			walker = walker->getParent();
		}

		return walker;
	}
}

/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
	while(root_ != NULL){
		remove(root_->getKey());
	}
}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    // TODO
		Node<Key, Value> *walker = root_;

		//while im not at a leaf
		while(walker->getLeft() != NULL){
			//go left
			walker = walker->getLeft();
		}

		return walker;
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    // TODO
		Node<Key, Value> *walker = root_;

		while(walker != NULL && walker->getKey() != key){
			if(key > walker->getKey()){
				walker = walker->getRight();
			}else{
				walker = walker->getLeft();
			}
		}

		return walker;
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
    // TODO
		//recursive?
		//similiar to the thing in previous section? path lengths?
		int pathVal = -1;

		if(root_ == NULL){
			return true;
		}
		Node<Key, Value> *totallyNotRoot = root_;
		return (balanceRecursion(totallyNotRoot->getLeft(), pathVal, 1) && balanceRecursion(totallyNotRoot->getRight(), pathVal, 1));
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::balanceRecursion(Node<Key, Value> *root, int pathVal, int lvl) const{
	if(root == NULL){
		return true;
	}

	if(root->getLeft() == NULL && root->getRight() == NULL){
		if(pathVal < 0){
			pathVal = lvl;
		}

		return (pathVal == lvl);
	}

	return (balanceRecursion(root->getLeft(), pathVal, lvl+1) && balanceRecursion(root->getRight(), pathVal, lvl+1));


}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
