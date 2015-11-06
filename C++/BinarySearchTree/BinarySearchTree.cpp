#include <iostream>
#include <fstream>
using namespace std;

class BinarySearchTree
{

public:
  BinarySearchTree()
  {
    root = NULL;
  }

  struct Node {
    int value; // Data in the node
    Node *left; // Left child node
    Node *right;  // Right child node

    Node(int v, Node *lt, Node *rt)
      : value (v), left (lt), right (rt){}
  };


  void insertItem(int x)
  {
    insert(x, root);
  }


  void insert (int x, Node * & node)
  {
    if (node == NULL)
    {
      node = new Node(x, NULL, NULL);
    }
    else if (x < node->value)
      insert(x, node->left);
    else if (x > node->value)
      insert(x, node->right);
    else
      ; // Do Nothing
  }

  bool IsEmpty(){ return root == NULL; }

  void Display()
  {
    //cout << root->value << " " << root->left->value << " " << root->right->value << endl;;

    cout << "PreOrderPrint: ";
    preorderPrint(root);
    cout << "\nInOrderPrint: ";
    inorderPrint(root);
    cout << "\nPostOrderPrint: ";
    postorderPrint(root);
    cout << endl;
  }

  void preorderPrint( Node *root ) {
       // Print all the items in the tree to which root points.
       // The item in the root is printed first, followed by the
       // items in the left subtree and then the items in the
       // right subtree.
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
       cout << root->value << " ";      // Print the root item.
       preorderPrint( root->left );    // Print items in left subtree.
       preorderPrint( root->right );   // Print items in right subtree.
    }
  } // end preorderPrint()

  void postorderPrint( Node *root ) {
       // Print all the items in the tree to which root points.
       // The items in the left subtree are printed first, followed
       // by the items in the right subtree and then the item in the
       // root node.
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
       postorderPrint( root->left );    // Print items in left subtree.
       postorderPrint( root->right );   // Print items in right subtree.
       cout << root->value << " ";       // Print the root item.
    }
 } // end postorderPrint()


  void inorderPrint( Node *root ) {
       // Print all the items in the tree to which root points.
       // The items in the left subtree are printed first, followed
       // by the item in the root node, followed by the items in
       // the right subtree.
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
       inorderPrint( root->left );    // Print items in left subtree.
       cout << root->value << " ";     // Print the root item.
       inorderPrint( root->right );   // Print items in right subtree.
    }
  } // end inorderPrint()

  Node *root;
};



int main(int argc, char* argv[]) {

  BinarySearchTree *Tree = new BinarySearchTree();

  // If the user didn't provide a filename command line argument,
  // print an error and exit.
  if (argc != 2)
  {
      cout << "Usage: " << argv[0] << " <Filename>" << endl;
      exit(1);
  }

  // cout << "There are " << argc << " arguments:" << endl;

  // // Loop through each argument and print its number and value
  // for (int nArg=0; nArg < argc; nArg++)
  //     cout << nArg << " " << argv[nArg] << endl;

  ifstream infile(argv[1]);
  // check to see if file opening succeeded
  if (!infile.is_open()) {
    cout << argv[1] << endl;
    cout << "Could not open file" << endl;
  }
  //read input
  int input;
  while(infile >> input) {
    Tree->insertItem(input);
  }

  Tree->Display();

  return 0;
}
