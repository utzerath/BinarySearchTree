/* Jack Utzerath
* BST
* This my work
*/

using namespace std;

#include <string>
#include <iostream>
#include "BST.h"
#include <fstream>

int main()
{

	
	BST tree;
	
	ifstream txt("input.in");

	if (!txt) {
		cout << "File not found\n";
		exit(2);
	}

	string script;
	

	while (txt >> script)
	{
		tree.insert(script);
	}

	tree.display();
	cout << endl << endl << endl;
	cout << endl << "is the data there? ";

	cout << tree.search("Lawrenaskdjfkace");
	tree.del("zoomakldfjalk");

	cout << endl << "Height of Tree: " << tree.height();
	

	cout << endl << endl << endl << endl;
	tree.display();
	cout << endl;
	
	
}