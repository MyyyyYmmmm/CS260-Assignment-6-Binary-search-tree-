#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
	int key;
	BinarySearchTree *left, *right;

	// Below is the default constructor created to
	// create without data
	BinarySearchTree(): key(0), left(NULL), right(NULL)
	{
	}

	// Contructor when parameter is passed.
	BinarySearchTree(int val){
		key = val;
		left = right = NULL;
	}

	// Add function to add node in the tree
	BinarySearchTree* add(BinarySearchTree*, int);

	// remove function to remov node from the tree after searching
	BinarySearchTree* remove(BinarySearchTree*, int);

	// traversal_inorder traversal.
	void traversal_inorder(BinarySearchTree*);
};

// add function definition.
BinarySearchTree* BinarySearchTree ::add(BinarySearchTree* root, int value)
{
	if (!root)
	{
		// if root is empty that means it is the first node
		// hence add at root.
		return new BinarySearchTree(value);
	}

	// add key.
	if (value > root->key)
	{	// if value of key is greater than root then
		// add to right
		root->right = add(root->right, value);
	}
	else
	{
		// if value of key is less than root then
		// add to left
		root->left = add(root->left, value);
	}
	// return the root (tree)
	return root;
}

// function to remove from the BST
BinarySearchTree* BinarySearchTree ::remove(BinarySearchTree* root, int k)
{
    // Check if root is null (that means no tree)
    if (root == NULL)
        return root;
	// recursion to find the key (if k is less than current traverse key then look
	// into left side.
    if (root->key > k) {
        root->left = remove(root->left, k);
        return root;
    }
	// recursion to find the key (if k is greater than current traverse key then look
	// into right side.
    else if (root->key < k) {
        root->right = remove(root->right, k);
        return root;
    }

	// now the pointer is at the node which needs to be deleted.
    if (root->left == NULL) {
        BinarySearchTree* tmp = root->right;
        delete root;
        return tmp;
    }
    else if (root->right == NULL) {
        BinarySearchTree* tmp = root->left;
        delete root;
        return tmp;
    }

    // If both children exist
    else {

        BinarySearchTree* succParent = root;
        BinarySearchTree* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
         if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
         root->key = succ->key;
         delete succ;
        return root;
    }
}

// In order traversal in BST
// Recursion is used.
void BinarySearchTree ::traversal_inorder(BinarySearchTree* root)
{
	if (!root) {
		return;
	}
	traversal_inorder(root->left);
	cout << root->key << endl;
	traversal_inorder(root->right);
}

// main method to test the working of the code.
int main()
{
	BinarySearchTree bst, *root = NULL;
	root = bst.add(root, 12);
	bst.add(root, 35);
	bst.add(root, 19);
	bst.add(root, 18);
	bst.add(root, 15);
	bst.add(root, 17);
	bst.add(root, 36);

	cout<<"\nIn order Traversal of the BST after adding nodes:\n";
	bst.traversal_inorder(root);
	bst.remove(root,15);
	cout<<"\nAfter removing node value 15\n";
	bst.traversal_inorder(root);

	bst.remove(root,19);
	cout<<"\nAfter removing node value 19\n";
	bst.traversal_inorder(root);

	bst.remove(root,35);
	cout<<"\nAfter removing node value 35\n";
	bst.traversal_inorder(root);

	cout<<"\nAfter adding node value 10\n";
	bst.add(root, 10);
	bst.traversal_inorder(root);

	return 0;
}
