#include "BSTree.h"


BSTree::BSTree():root_(NULL) {
}

BSTree::BSTree(const BSTree & rbt){
	if (rbt.root_==NULL){
		return;
	}
	this->root_ = NULL;
	vector<Customer> info;
	BFSearch(rbt.root_,info);
	vector<Customer>::iterator iter;
	Customer tmp;
	for(iter=info.begin();iter!=info.end();iter++ ){
		tmp = *iter;
		insert(tmp.GetLastName(),tmp.GetFirstInitial(),tmp.GetAcctBalance());
	}
}

BSTree::~BSTree() {
	destroyTree(root_);
}

void BSTree::destroyTree(Node* &root){
	if (root == NULL){
		return;
	}
	destroyTree(root->left_);
	destroyTree(root->right_);
	delete root;
}

void BSTree::BFSearch(Node *root,vector<Customer> &info){
	queue<Node*> q;
	q.push(root);
	Node* curr;
	while(!q.empty()){
		curr = q.front();
		info.push_back(curr->current_);
		q.pop();
		if (!IsLeftEmpty(curr)){
			q.push(curr->left_);
		}
		if(!IsRightEmpty(curr)){
			q.push(curr->right_);
		}
	}
}

bool BSTree::insert(string x, char y, int z) {
	Node* item = new Node(x,y,z);
	if (!item){
		return false;
	}	
	if (root_ == NULL)	{
		root_ = item;
		return true;
	}
	Node* tmp = root_;
	while (tmp){
		if (item->current_<tmp->current_){
			if (IsLeftEmpty(tmp)){
				tmp->left_ = item;
				item->parent_ = tmp;
				break;
			}
			else{				
				tmp = tmp->left_;
			}
		}
		else{
			if (IsRightEmpty(tmp)){
				tmp->right_ = item;
				item->parent_ = tmp;
				break;
			}
			else{
				tmp = tmp->right_;				
			}
		}
	}
	return true;
}

Node* BSTree::GetPredecessor(const Node* n){
	Node* tmp;
	Node* curr = n->left_;
	while (curr){
		tmp = curr;
		curr = curr->right_;
	}
	return tmp;
}

Node* BSTree::GetSuccessor(const Node* n){
	Node* tmp;
	Node* curr = n->right_;
	while (curr){
		tmp = curr;
		curr = curr->left_;
	}
	return tmp;
}

void BSTree::Swap(Node* &a,Node* &b){
	a->left_ = b->left_;
	a->right_ = b->right_;
	b->left_->parent_ = a;
	b->right_->parent_ = a;
}

void BSTree::rmNodeNochild(Node* & a,Node* & b){
	if (a!=root_){		
		if(a->current_ < b->current_){
			b->left_ = NULL;
		}
		else{
			b->right_ = NULL;
		}
	}
	else{
		root_ = NULL;
	}
	delete a;
}

void BSTree::rmNodeOnechild(Node* & a,Node* & b){
	Node* t;
	if (a->left_ == NULL && a->right_ != NULL){
		t = a->right_;
	}
	else{
		t = a->left_;
	}
	if(a != root_){
		if (t->current_ < b->current_){
			b->left_ = t;
			b->left_->parent_ = b;
		}
		else{
			b->right_ = t;
			b->right_->parent_ = b;
		}
	}
	else{
		root_ = t;
		t->parent_ = NULL;
	}
	delete a;
}

bool BSTree::remove(string x, char y) {
	if (!search(x,y)){
		return false;		
	}
	Customer item = Customer(x,y,0);
	Node* curr = root_;
	Node* tmp;
	while(curr){
		if(item == curr->GetCustomer()){
			// case for no children.
			if (curr->left_==NULL && curr->right_==NULL){
				if(curr!=root_){
					tmp = curr->parent_;
					rmNodeNochild(curr,tmp);					
				}
				else{
					tmp = root_;
					rmNodeNochild(curr,tmp);	
				}
				
				return true;
			}
			//case for one child
			else if(curr->left_ == NULL || curr->right_ == NULL){
				if(curr!=root_){
					tmp = curr->parent_;
					rmNodeOnechild(curr,tmp);					
				}
				else{
					tmp = root_;
					rmNodeOnechild(curr,tmp);	
				}
				return true;
			}
			// case for 2 children
			else{
				Node* pre = GetPredecessor(curr);
				Node* suc = GetSuccessor(curr);
				if(pre->left_ == NULL && pre->right_ == NULL){
					Customer c = pre->GetCustomer();
					tmp = pre->parent_;
					rmNodeNochild(pre,tmp);
					curr->GetCustomer() = c;
					return true;
				}
				else if(suc->left_ == NULL && suc->right_ == NULL){
					Customer c = suc->GetCustomer();
					tmp = suc->parent_;
					rmNodeNochild(suc,tmp);
					curr->GetCustomer() = c;
					return true;
				}
				else{
					Customer c = pre->GetCustomer();
					tmp = pre->parent_;
					rmNodeOnechild(pre,tmp);
					curr->GetCustomer() = c;
					return true;
				}
				return false;
			}
		}
		else if (item < curr->GetCustomer()){
			curr = curr->left_;
		}
		else{
			curr = curr->right_;
		}
	}
	return true;
}
bool BSTree::search(string x, char y) {
	Customer item = Customer(x,y,0);
	Node* tmp = root_;
	while(tmp){
		if(item == tmp->GetCustomer()){
			return true;
		}
		else if (item < tmp->GetCustomer()){
			tmp = tmp->left_;
		}
		else{
			tmp = tmp->right_;
		}
	}
	return false;
}
vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
	vector<Customer> v;
	vectorPush(root_,v);
	Customer min = Customer(x,y,0);
	Customer max = Customer(z,a,0);
	vector<Customer>::iterator viter = v.begin();
	// while(*viter < min){
	// 	v.erase(viter);		
	// }
	for(viter = v.begin();viter != v.end();viter++){
		if(*viter < min || *viter > max){
			v.erase(viter);
			viter--;
		}
	}
	
	// while(*viter > max){
	// 	v.erase(viter);	
	// }
	return v;
}
void BSTree::vectorPush(Node* &n, vector<Customer> &v){
	if (n == NULL){
		return;
	}
	vectorPush(n->left_,v);
	v.push_back(n->current_);
	vectorPush(n->right_,v);
}
void BSTree::inOrderPrint() {
	print(root_);
}
void BSTree::print(Node* &root) const{
	if (root == NULL){
		return;
	}
	print(root->left_);
	cout << root->current_ << endl;
	print(root->right_);
}
bool BSTree::IsLeftEmpty( const Node* n ) const{
	if(n->left_ == NULL){
		return true;
	}
	return false;
}
bool BSTree::IsRightEmpty( const Node* n ) const{
	if(n->right_ == NULL){
		return true;
	}
	return false;
}
bool BSTree::pushNode(Node n){
	if (insert(n.GetLast(),n.GetFirst(),n.GetAcct())){
		return true;
	}
	return false;
}
