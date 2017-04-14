#include <iostream>
#include <string>

using namespace std;

class Node; // important!!!

class BinaryTree{
	public:
		BinaryTree();
		~BinaryTree();
		void Insert( int i );
		void Print();
		Node* GetRoot() const;
	private:
		Node* root_; 		
		//void Insert( Node* root,int i );
		bool IsLeftEmpty( const Node* n ) const;
		bool IsRightEmpty( const Node* n ) const;
		void PreOrderPrint( Node* &root ) const;
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
	/*Node* node = new Node(i);
	if( root_ == NULL){
		root_ = node;
		return;
	}
	Node* current = root_;

	while(1){
		if( i <= current->data_ ){

		}
	}*/

	Node* tmp = new Node(i);
	if( root_ == NULL){
		root_ = tmp;
		return;
	}
	Node* current = root_;
	while (current){
		if (i>current->data_){
			if (!IsRightEmpty(current)){
				current = current->right_;				
			}
			else{
				current->right_ = tmp;
				break;
			}
		}
		else{
			if (!IsLeftEmpty(current)){
				current = current->left_;				
			}
			else{
				current->left_ = tmp;
				break;
			}
		}
	}
}
/*void BinaryTree::Insert( Node* root,int i ){

	Node* node = new Node();
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

}*/
void BinaryTree::Print(){
	PreOrderPrint(root_);
}

void BinaryTree::PreOrderPrint( Node* &root ) const{
	if( root == NULL){
		return;
	}
	cout << root->data_ << " ";
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
	bt.Insert( 47 );
	bt.Insert( 63 );
	bt.Insert( 32 );
	bt.Insert( 19 );
	bt.Insert( 41 );
	bt.Insert( 79 );
	bt.Insert( 54 );
	bt.Insert( 10 );
	bt.Insert( 23 );
	bt.Insert( 37 );
	bt.Insert( 44 );
	bt.Insert( 53 );
	bt.Insert( 59 );
	bt.Insert( 96 );
	bt.Insert( 7 );
	bt.Insert( 12 );
	bt.Insert( 30 );
	bt.Insert( 57 );
	bt.Insert( 91 );
	bt.Insert( 97 );
	bt.Insert( 43 );
	bt.Print();
	cout << endl;

}