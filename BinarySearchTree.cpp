#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* root, int data);
bool search(Node* root, int data);
Node* getNewNode(int data);
int findMin(Node* root);
int findMax(Node* root);
int max(int x, int y);
int findHeight(Node* root);
void levelOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void inOrderTraversal(Node* root);
void postOrderTraversal(Node* root);
bool isBinarySearchTree(Node* root, int, int);
Node* deleteNode(Node* root, int data);
Node* getInorderSuccessor(Node* root, int data);
Node* findMinWithNode(Node* root);
Node* searchWithNode(Node* root, int data);

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	Node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 10);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 2);
	root = insert(root, 5);
	cout << search(root, 12) << endl;
	cout << search(root, 6) << endl;
	cout << findMin(root) << endl;
	cout << findMax(root) << endl;
	cout << findHeight(root) << endl;
	levelOrderTraversal(root);
	preOrderTraversal(root);
	cout << endl;
	inOrderTraversal(root);
	cout << endl;
	postOrderTraversal(root);
	cout << endl;
	cout << isBinarySearchTree(root, INT_MAX, INT_MIN) << endl;
	root = deleteNode(root, 12);
	inOrderTraversal(root);
	cout << endl;
	root = deleteNode(root, 8);
	inOrderTraversal(root);
	cout << endl;
	Node* successor = getInorderSuccessor(root, 4);
	cout << successor->data << endl;
	return 0;
}

Node* getNewNode(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

Node* insert(Node* root, int data) {
	if (root == NULL) {
		Node* temp = getNewNode(data);
		root = temp;
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

bool search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	if (root->data == data) {
		return true;
	}
	else if (data < root->data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}

Node* searchWithNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == data) {
		return root;
	}
	else if (data < root->data) {
		return searchWithNode(root->left, data);
	}
	else {
		return searchWithNode(root->right, data);
	}
}

int findMin(Node* root) {
	if (root == NULL) {
		return -1;
	}
	if (root->left == NULL) {
		return root->data;
	}
	return findMin(root->left);
}

Node* findMinWithNode(Node* root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left == NULL) {
		return root;
	}
	return findMinWithNode(root->left);
}

int findMax(Node* root) {
	if (root == NULL) {
		return -1;
	}
	if (root->right == NULL) {
		return root->data;
	}
	return findMax(root->right);
}

int max(int x, int y) {
	if (x >= y) {
		return x;
	}
	return y;
}

int findHeight(Node* root) {
	if (root == NULL) {
		return -1;
	}
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrderTraversal(Node* root) {
	if (root == NULL) 
		return;
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Node* temp = Q.front();
		cout << temp->data << " ";
		if (temp->left != NULL)
			Q.push(temp->left);
		if (temp->right != NULL)
			Q.push(temp->right);
		Q.pop();
	}
	cout << endl;
}

void preOrderTraversal(Node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	if (root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}

bool isBinarySearchTree(Node* root, int max, int min) {
	if (root == NULL)
		return true;
	if (root->data < max && root->data > min && isBinarySearchTree(root->left, root->data, min) && isBinarySearchTree(root->right, max, root->data))
		return true;
	return false;
	// We can use inOrderTraversal & check wether the numbers are sorted or not to verify if it's binary search tree or not
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL)
		return root;
	if (data < root->data) {
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else {
		// Case 1
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			int temp = findMin(root->right);
			root->right = deleteNode(root->right, temp);
		}
	}
	return root;
}

Node* getInorderSuccessor(Node* root, int data) {
	if (root == NULL) {
		return root;
	}
	Node* temp = searchWithNode(root, data);
	if (temp == NULL) {
		return temp;
	}
	else if (temp->right != NULL) {
		Node* temp2 = findMinWithNode(temp->right);
		return temp2;
	}
	else {
		Node* successor = NULL;
		Node* ancestor = root;
		while (temp != ancestor) {
			if (temp->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}