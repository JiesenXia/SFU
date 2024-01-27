#include <iostream>

class NonEmptyBSTNode {
	private:
		int val; 
		struct NonEmptyBSTNode * left;
		struct NonEmptyBSTNode * right;
	
	public:
		NonEmptyBSTNode(int new_val);
		~NonEmptyBSTNode();
		void insert(int new_val);
		void print_descending();
		bool insert_if_missing(int new_val);

		void deleteTreeFromNode(NonEmptyBSTNode* node);
		bool insertNode(NonEmptyBSTNode* node, int new_val);
		void print_descending_recursively(NonEmptyBSTNode* node);
};

NonEmptyBSTNode::NonEmptyBSTNode(int new_val) {
	
	val = new_val;
	left = nullptr;
	right = nullptr;
}

NonEmptyBSTNode::~NonEmptyBSTNode() {
	deleteTreeFromNode(left);
	deleteTreeFromNode(right);	
}


void NonEmptyBSTNode::insert(int new_val) {
	if(new_val == val) return ;  // node already exists	

	if(new_val < val) {
		if (left == nullptr) {
			left = new NonEmptyBSTNode(new_val);
		} else {
			insertNode(left, new_val);
		}
	} else {
		if (right == nullptr) {
			right = new NonEmptyBSTNode(new_val);
		} else {
			insertNode(right, new_val);
		}
	}
}

void NonEmptyBSTNode::print_descending() {
	print_descending_recursively(right);  // print the right subtree
	std::cout << val << " ";	     // print the root
	print_descending_recursively(left);   // print the left subtree
	std::cout << "\n";	
}

bool NonEmptyBSTNode::insert_if_missing(int new_val) {
	if (new_val == val) return false;
	if (new_val < val) {
		if (left == nullptr) {
			left = new NonEmptyBSTNode(new_val);
			return true;
		} else {
			return insertNode(left, new_val);
		}	
	} else {
		if (right == nullptr) {
			right = new NonEmptyBSTNode(new_val);
			return true;
		} else {
			return insertNode(right, new_val);
		}
	}

}

void NonEmptyBSTNode::deleteTreeFromNode(NonEmptyBSTNode* node) {
	if(node == nullptr) return ;
	deleteTreeFromNode(node->left);
	node->left = nullptr;
	deleteTreeFromNode(node->right);
	node->right = nullptr;
	delete node;
	
}



bool NonEmptyBSTNode::insertNode(NonEmptyBSTNode* node, int new_val) {
	NonEmptyBSTNode* new_node = new NonEmptyBSTNode(new_val);
	NonEmptyBSTNode* parent = node;
	bool isLeft = true;
	while(node != nullptr) {
		// the node already exists in the tree
		if (node->val == new_val) {
			delete new_node;
			return false;
		}

		parent = node;
		if(new_val < node->val) {
			isLeft = true;
			node = node->left;
		} else {
			isLeft = false;
			node = node->right;
		}
	}
	if(isLeft) parent->left = new_node;
	else parent->right = new_node;
	return true;
} 

void NonEmptyBSTNode::print_descending_recursively(NonEmptyBSTNode* node) {
	if (node == nullptr) {
		return ;
	}

	//print_descending_recursively(node->left);
	print_descending_recursively(node->right);
	std::cout << node->val << " ";
	print_descending_recursively(node->left);	
}


int main() {
	NonEmptyBSTNode node(0);
	node.insert(5);
	node.insert(4);
	node.insert(8);
	node.insert(7);
	node.insert(2);
	node.print_descending();
}

