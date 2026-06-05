// g++ DSA.cpp -o DSA
//./DSA

#include <iostream>
#include <queue>
using namespace std;

struct Node

{
  int data;
  Node *left;
  Node *right;

  Node(int val)

  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

class BST

{

  Node *root;
  Node *insert(Node *curr, int val)

  {

    if (curr == nullptr)

      return new Node(val);

    if (val < curr->data)

      curr->left = insert(curr->left, val);

    else if (val > curr->data)

      curr->right = insert(curr->right, val);

    return curr;
  }

  void inorder(Node *curr)

  {

    if (curr == nullptr)

      return;

    inorder(curr->left);

    cout << curr->data << " ";

    inorder(curr->right);
  }

  void preorder(Node *curr)

  {

    if (curr == nullptr)

      return;

    cout << curr->data << " ";

    preorder(curr->left);

    preorder(curr->right);
  }

  void postorder(Node *curr)

  {

    if (curr == nullptr)

      return;

    postorder(curr->left);
    postorder(curr->right);

    cout << curr->data << " ";
  }

  Node *search(Node *curr, int key)

  {

    if (curr == nullptr || curr->data == key)

      return curr;

    if (key < curr->data)

      return search(curr->left, key);

    return search(curr->right, key);
  }

  Node *findMin(Node *curr)

  {

    while (curr && curr->left != nullptr)

      curr = curr->left;

    return curr;
  }

  Node *findMax(Node *curr)

  {

    while (curr && curr->right != nullptr)

      curr = curr->right;

    return curr;
  }

  Node *deleteNode(Node *curr, int key)

  {

    if (curr == nullptr)

      return curr;

    if (key < curr->data)

      curr->left = deleteNode(curr->left, key);

    else if (key > curr->data)

      curr->right = deleteNode(curr->right, key);

    {

      if (curr->left == nullptr)

      {

        Node *temp = curr->right;

        delete curr;

        return temp;

      }

      else if (curr->right == nullptr)

      {

        Node *temp = curr->left;

        delete curr;

        return temp;
      }

      Node *temp = findMin(curr->right);

      curr->data = temp->data;

      curr->right = deleteNode(curr->right, temp->data);
    }

    return curr;
  }

  void printTree(Node *curr, string prefix, bool isLeft)

  {

    if (curr == nullptr)

      return;

    cout << prefix;

    cout << (isLeft ? "|-- " : "`-- ");

    cout << curr->data << "\n";

    if (curr->left != nullptr || curr->right != nullptr)

    {

      if (curr->left != nullptr)

        printTree(curr->left, prefix + (isLeft ? "|   " : "    "), true);

      if (curr->right != nullptr)

        printTree(curr->right, prefix + (isLeft ? "|   " : "    "), false);
    }
  }

public:
  BST()

  {

    root = nullptr;
  }

  void insert(int val)

  {

    root = insert(root, val);
  }

  void inorder()

  {

    inorder(root);
  }

  void preorder()

  {

    preorder(root);
  }

  void postorder()

  {

    postorder(root);
  }

  // Function to search for a value in the tree

  void search(int key)

  {

    Node *res = search(root, key);

    if (res)

      cout << "Found!" << endl;

    else

      cout << "Not found." << endl;
  }

  // Function to find the value in the tree

  void findMinimum()

  {

    Node *temp = findMin(root);

    if (temp)

      cout << "Min: " << temp->data << endl;
  }

  void findMaximum()

  {

    Node *temp = findMax(root);

    if (temp)

      cout << "Max: " << temp->data << endl;
  }

  void deleteValue(int key)

  {

    root = deleteNode(root, key);
  }

  void display()

  {

    if (root == nullptr)

    {

      cout << "Tree is empty.\n";

      return;
    }

    printTree(root, "", false);
  }
};

int main()

{

  BST tree;

  tree.insert(43);

  tree.insert(10);

  tree.insert(79);

  tree.insert(90);

  tree.insert(12);

  tree.insert(54);

  tree.insert(11);

  tree.insert(9);

  tree.insert(50);

  int choice, val;

  do

  {

    cout << "\n--- BST Menu ";

    cout << "1. Inorder\n";

    cout << "2. Preorder\n";

    cout << "3. Postorder\n";

    cout << "4. Search\n";

    cout << "5. Insert\n";

    cout << "6. Find Min\n";

    cout << "7. Find Max\n";

    cout << "8. Delete\n";

    cout << "9. Print Tree\n";

    cout << "10. Exit\n";

    cout << "Choice: ";

    cin >> choice;

    switch (choice)

    {

    case 1:

      cout << "Inorder: ";

      tree.inorder();

      cout << endl;

      break;

    case 2:

      cout << "Preorder: ";

      tree.preorder();

      cout << endl;

      break;

    case 3:

      cout << "Postorder: ";

      tree.postorder();

      cout << endl;

      break;

    case 4:

      cout << "Search, for: ";

      cin >> val;

      tree.search(val);

      break;

    case 5:

      cout << "Insert value: ";

      cin >> val;

      tree.insert(val);

      cout << "Added.\n";

      break;

    case 6:

      tree.findMinimum();

      break;

    case 7:

      tree.findMaximum();

      break;

    case 8:

      cout << " value: ";

      cin >> val;

      tree.deleteValue(val);

      cout << "Removed.\n";

      break;

    case 9:

      cout << "\n";

      tree.display();

      break;

    case 10:

      break;

    default:

      cout << "Invalid.\n";
    }

  } while (choice != 10);

  return 0;
}