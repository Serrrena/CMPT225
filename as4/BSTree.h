#ifndef BSTREE_H_
#define BSTREE_H_
#include "Customer.h"
#include "Node.h"
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

class Node;  // why why why need!

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);
	bool pushNode(Node n);
	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();
	
private:
	Node* root_;
	void print(Node* &root) const;
	bool IsLeftEmpty( const Node* n ) const;
	bool IsRightEmpty( const Node* n ) const;
	Node* GetPredecessor( const Node* n);
	Node* GetSuccessor(const Node* n);
	void Swap(Node* &a,Node* &b);
	void rmNodeNochild(Node* & a,Node* & b);
	void rmNodeOnechild(Node* & a,Node* & b);
	void vectorPush(Node* &n,vector<Customer> &v);
	void destroyTree(Node* &root);
	void BFSearch(Node *root,vector<Customer> &info);
};

#endif /* BSTREE_H_ */
