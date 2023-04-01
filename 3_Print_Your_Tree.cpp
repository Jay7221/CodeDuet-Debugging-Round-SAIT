// CodeDuet 2K23 Round 3

// You are given a basic implementation of Binary Tree, which consists of some errors (Syntactical/Logical). You need to detect those errors and correct so that, they satisfy the given input output conditions.

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
  int data;
  Node *left, *right;

  Node()
  {
    this->left = this->right = NULL;
  }

  Node(int data)
  {
    this->data = data;
    this->left = this->right = NULL;
  }

  // Function to create a node.
  Node *add(int value, Node *root)
  {
    if (root == NULL)
    {
      return new Node(value);
    }

    if (value < root->data)
    {
      root->left = add(value, root->left);
    }
    else
    {
      root->right = add(value, root->right);
    }
    return root;
  }
};

// Function to return preorder traversal of binary tree.
vector<int> preorder(Node *root)
{
  vector<int> ans;
  if (root == NULL)
  {
    return ans;
  }

  stack<Node *> stk;
  stk.push(root);

  while (!stk.empty())
  {
    Node *temp = stk.top();
    stk.pop();

    
    if (temp->right)
    {
      stk.push(temp->right);
    }
    if (temp->left)
    {
      stk.push(temp->left);
    }

    ans.push_back(temp->data);
  }

  return ans;
}

// Function to return postorder traversal of binary tree.
vector<int> postorderTraversal(Node *root)
{
  vector<int> ans;
  if (root == NULL)
  {
    return ans;
  }

  stack<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *temp = q.top();
    q.pop();
    
    if (temp->left)
    {
      q.push(temp->left);
    }
    if (temp->right)
    {
      q.push(temp->right);
    }
    ans.push_back(temp->data);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{

  Node *root = NULL;
  Node bt;

  root = bt.add(12, root);
  root = bt.add(13, root);
  root = bt.add(11, root);
  root = bt.add(10, root);
  root = bt.add(9, root);

  auto ans1 = preorder(root);
  for (auto itr : ans1)
  {
    cout << itr << " ";
  }
  cout << '\n';
  auto ans2 = postorderTraversal(root);
  for (auto itr : ans2)
  {
    cout << itr << " ";
  }
  return 0;
}
