// --------------------------------------------------------------
// Nicolas Corfmat
// CruzID: ncorfmat
// Assignment: pa7
// --------------------------------------------------------------

#include <iostream>
#include <string>
#include <stdexcept>

#include "Dictionary.h"

/*** Node Constructor ***/

Dictionary::Node::Node(keyType k, valType v) {
	key = k;
	val = v;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

/*** Helper Functions ***/

void Dictionary::inOrderString(std::string& s, Node* R) const {
	if (R != nil) {
		inOrderString(s, R->left);
		s += R->key + " : " + std::to_string(R->val) + "\n";
		inOrderString(s, R->right);
	}
}

void Dictionary::preOrderString(std::string& s, Node* R) const {
	if (R != nil) {
		s += R->key + "\n";
		preOrderString(s, R->left);
		preOrderString(s, R->right);
	}
}

void Dictionary::preOrderCopy(Node* R, Node* N) {
	if (R != N) {
		setValue(R->key, R->val);
		preOrderCopy(R->left, N);
		preOrderCopy(R->right, N);
	}
}

void Dictionary::postOrderDelete(Node* R) {
	if (R != nil) {
		postOrderDelete(R->left);
		postOrderDelete(R->right);
		delete R;
	}
}

void Dictionary::transplant(Node* R, Node* N) {
	if (R->parent == nil) {
		root = N;
	} else if (R == R->parent->left) {
		R->parent->left = N;
	} else {
		R->parent->right = N;
	}

	if (N != nil) {
		N->parent = R->parent;
	}
}

Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
	while (R != nil && R->key != k) {
		if (k < R->key) {
			R = R->left;
		} else {
			R = R->right;
		}
	}

	return R;
}

Dictionary::Node* Dictionary::findMin(Node* R) {
	if (R != nil) {
		while (R->left != nil) {
			R = R->left;
		}
	}

	return R;
}

Dictionary::Node* Dictionary::findMax(Node* R) {
	if (R != nil) {
        	while (R->right != nil) {
                	R = R->right;
        	}
	}

        return R;
}

Dictionary::Node* Dictionary::findNext(Node* N) {
	if (N->right != nil) {
		return findMin(N->right);
	}

	Node* y = N->parent;

	while (y != nil && N == y->right) {
		N = y;
		y = y->parent;
	}

	return y;
}

Dictionary::Node* Dictionary::findPrev(Node* N) {
	if (N->left != nil) {
                return findMax(N->left);
        }

        Node* y = N->parent;

        while (y != nil && N == y->left) {
                N = y;
                y = y->parent;
        }

        return y;
}

/*** Constructors-Destructors ***/

Dictionary::Dictionary() {
        nil = new Node("-1", -1);
        root = nil;
        root->parent = nil;
        root->left = nil;
        root->right = nil;
        current = root;
        num_pairs = 0;
}

Dictionary::Dictionary(const Dictionary& D) {
        nil = new Node("-1", -1);
        root = nil;
        root->parent = nil;
        root->left = nil;
        root->right = nil;
        current = root;
        num_pairs = 0;

        preOrderCopy(D.root, D.nil);
}

Dictionary::~Dictionary() {
        postOrderDelete(root);
        delete nil;
}

/*** Access Functions ***/

int Dictionary::size() const {
	return num_pairs;
}

bool Dictionary::contains(keyType k) const {
	Node* N = search(root, k);

	return N != nil;
}

valType& Dictionary::getValue(keyType k) const {
	if (!contains(k)) {
		throw std::invalid_argument("Error: calling getValue() on invalid key");
	}

	Node* N = search(root, k);

	return N->val;
}

bool Dictionary::hasCurrent() const {
	return current != nil;
}

keyType Dictionary::currentKey() const {
	if (!hasCurrent()) {
                throw std::invalid_argument("Error: calling currentKey() on non-existent current iterator");
        }

	return current->key;
}

valType& Dictionary::currentVal() const {
	if (!hasCurrent()) {
                throw std::invalid_argument("Error: calling currentVal() on non-existent current iterator");
        }

	return current->val;
}

/*** Manipulation Procedures ***/

void Dictionary::clear() {
	postOrderDelete(root);
	root = nil;
	current = nil;
	num_pairs = 0;
}

void Dictionary::setValue(keyType k, valType v) {
	Node* z = new Node(k, v);
	Node* y = nil;
	Node* x = root;

	z->parent = nil;
        z->left = nil;
        z->right = nil;

	while (x != nil) {
		y = x;

		if (z->key < x->key) {
			x = x->left;
		} else {
			x = x->right;
		}
	}

	z->parent = y;

	if (y == nil) {
		root = z;
	} else if (y->key == k) {
		y->val = v;
		delete z;
		return;
	} else if (z->key < y->key) {
		y->left = z;
	} else {
		y->right = z;
	}

	num_pairs++;
}

void Dictionary::remove(keyType k) {
	if (!contains(k)) {
		throw std::invalid_argument("Error: Calling remove() on non-existent key");
	}

	Node* N = search(root, k);
	
	if (N == current) {
		current = nil;
	}

	if (N->left == nil) {
		transplant(N, N->right);
	} else if (N->right == nil) {
		transplant(N, N->left);
	} else {
		Node* y = findMin(N->right);

		if (y->parent != N) {
			transplant(y, y->right);
			y->right = N->right;
			y->right->parent = y;
		}

		transplant(N, y);

		y->left = N->left;
		y->left->parent = y;
	}

	delete N;
	num_pairs--;
}

void Dictionary::begin() {
	if (root != nil) {
		current = findMin(root);
	}
}

void Dictionary::end() {
	if (root != nil) {
		current = findMax(root);
	}
}

void Dictionary::next() {
	if (!hasCurrent()) {
                throw std::invalid_argument("Error: calling next() on non-existent current iterator");
        }
	
	current = findNext(current);
}

void Dictionary::prev() {
	if (!hasCurrent()) {
                throw std::invalid_argument("Error: calling prev() on non-existent current iterator");
        }

	current = findPrev(current);
}

/*** Other Functions ***/

std::string Dictionary::to_string() const {
	std::string s;
	inOrderString(s, root);
	return s;
}

std::string Dictionary::pre_string() const {
	std::string s;
	preOrderString(s, root);
	return s;
}

bool Dictionary::equals(const Dictionary& D) const {
	if (num_pairs != D.num_pairs) {
		return false;
	}

	std::string A = to_string();
	std::string B = D.to_string();

	return A == B;
}

/*** Overload Operators ***/

std::ostream& operator<<( std::ostream& stream, Dictionary& D ) {
	return stream << D.to_string();
}

bool operator==( const Dictionary& A, const Dictionary& B ) {
	return A.equals(B);
}

Dictionary& Dictionary::operator=( const Dictionary& D ) {
	if (this != &D) {
		Dictionary temp = D;

		std::swap(nil, temp.nil);
		std::swap(root, temp.root);
		std::swap(current, temp.current);
		std::swap(num_pairs, temp.num_pairs);
	}

	return *this;
}
