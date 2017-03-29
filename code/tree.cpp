#include <iostream>
#include <string>

using namespace std;

class Node; // important!!!

class BinaryTree{
	public:
		BinaryTree();
		~BinaryTree();
		void Insert( int i );
		void PreOrderPrint( Node* root ) const;
		Node* GetRoot() const;
	private:
		Node* root_; 		
		void Insert( Node* root,int i );
		bool IsLeftEmpty( const Node* n ) const;
		bool IsRightEmpty( const Node* n ) const;
};

class Node {
	friend class BinaryTree;
	public:
		Node();
		Node( int i );
	private:
		int data_;
		Node* parent_;
		Node* left_;
		Node* right_;
};

BinaryTree::BinaryTree():root_(NULL){}

BinaryTree::~BinaryTree(){}

bool BinaryTree::IsLeftEmpty( const Node* n )  const{
	if( n->left_ == NULL ){
		return true;
	}
	return false;
}

bool BinaryTree::IsRightEmpty( const Node* n )  const{
	if( n->right_ == NULL ){
		return true;
	}
	return false;
}

void BinaryTree::Insert( int i ){
	Insert( root_,i );
}
void BinaryTree::Insert( Node* root,int i ){

	Node* node = new Node;
	node->data_ = i;
	if( root == NULL ){
		//cout << "1" << endl;
		root = node;
		return;
	}
	//cout << "2" << endl;
	if( !IsLeftEmpty( root ) && !IsRightEmpty( root ) ){
		return;
	}
	if( IsLeftEmpty( root ) ){
		root->left_ = node;
		return;
	}
	if( IsRightEmpty( root_ ) ){
		root->right_ = node;
		return;
	}
	Insert( root->left_ ,i );
	Insert( root->right_ ,i );

}

void BinaryTree::PreOrderPrint( Node* root ) const{
	if( root == NULL){
		return;
	}
	cout << root->data_ << endl;
	if( !IsLeftEmpty( root ) && !IsRightEmpty( root ) ){
		return;
	}
	PreOrderPrint( root->left_ );
	PreOrderPrint( root->right_ );
}

 Node* BinaryTree::GetRoot() const{
 	return root_;
 }

Node::Node():parent_(NULL),left_(NULL),right_(NULL),data_(0){}

Node::Node( int i ){
	parent_ = NULL;
	left_ = NULL;
	right_ = NULL;
	data_ = i;
}

int main( void ){
	BinaryTree bt;
	for( int i = 0; i <= 2; i++ ){
		bt.Insert( i );
	}
	bt.PreOrderPrint( bt.GetRoot() );
	return 0;
}