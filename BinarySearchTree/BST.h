/* Jack Utzerath
* BST
* This my work
*/

using namespace std;

#include <string>
#include <iostream>

#ifndef BST_H
#define BST_H

struct Node {
	string data;
	
	struct Node* left;
	struct Node* right;
};

class BST
{

public:

	string data;
	Node* left;
	Node* right;
	struct Node* root = NULL;

	BST()
	{

	}
	void BSTdisplay(Node* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		else 
		{
			BSTdisplay(temp->left);
			cout << temp->data << "";
			BSTdisplay(temp->right);
		}
	}
	struct Node* BSTdel(struct Node* root, string key)
	{
		if (root == NULL)
		{
			return root;
		}
		if (key < root->data)
		{
			root->left = BSTdel(root->left, key);
		}
		else if (key > root->data)
		{
			root->right = BSTdel(root->right, key);
		}
		else
		{
			if (root->left == NULL && root->right == NULL)
			{
				return NULL;
	
			}
			else if (root->left == NULL)
			{
				struct Node* temp = root->right;
				delete(root);
				return temp;
			}
			else if (root->right == NULL)
			{
				struct Node* temp = root->left;
				delete(root);
				return temp;
			}
			
			struct Node* temp = minVal(root->right);
			root->data = temp->data;
			root->right = BSTdel(root->right, key);


		}
		return root;
	}



	struct Node* BSTinsert(struct Node* node, string data)
	{
		if (node == NULL)
		{
			struct Node* node = new(struct Node);
			node->data = data;
			node->left = NULL;
			node->right = NULL;
			return node;
		}

		else
		{
			if (data < node->data)
			{
				node->left = BSTinsert(node->left, data);
			}
			else if(data > node->data)
			{
				node->right = BSTinsert(node->right, data);
			}
			else
			{
				return node;
			}
			return node;
		}

		

	}

	struct Node* minVal(struct Node* node)
	{
		struct Node* current = node;
		while (current && current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}

	struct Node* maxVal(struct Node* node)
	{
		struct Node* current = node;
		while (current && current->right != NULL)
		{
			current = current->right;
		}
		return current;
	}

	int BSTheight(struct Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else 
		{
			int left = BSTheight(node->left);
			int right = BSTheight(node->right);

			if (left > right)
			{
				return left + 1;
			}
			else
			{
				return right + 1;
			}
		}
	}

	string BSTsearch(struct Node* node, string data)
	{
		while (node != NULL && node->data != data)
		{
			if (data < node->data)
			{
				node = node->left;
			}
			else if (data > node->data)
			{
				node = node->right;
			}
		}
		if (root == NULL)
		{
			return NULL;
		}
		return node->data;
	}

	string search(string data)
	{
		string yes = BSTsearch(root, data);
		return yes;
	}
	void insert(string data)
	{
		root = BSTinsert(root, data);
	}

	void display()
	{
		BSTdisplay(root);
	}

	int height()
	{
		int yes = BSTheight(root);
		return yes;
	}

	void del(string key)
	{
		BSTdel(root, key);
	}

};

#endif