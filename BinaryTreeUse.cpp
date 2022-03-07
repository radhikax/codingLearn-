#include<iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
using namespace std;
#include<queue>
#include<climits>
#include<vector>

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
     cout<<"Enter data" <<endl;
    cin>> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() !=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< "Enter Left child of"<<front->data<<endl;
        int leftChildData;
        cin>> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

         cout<< "Enter right child of"<<front->data<<endl;
        int rightChildData;
        cin>> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
  cout<< root->data <<":";
  if(root->left !=NULL){
      cout<<"L"<<root->left->data;
  }

  if(root->right !=NULL){
      cout<<"R"<<root->right->data;
  }
  cout<<endl;
  printTree(root->left);
  printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data" <<endl;
    cin>> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int numNodes(BinaryTreeNode<int>* root){
    if(root ==NULL){
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}

int maximum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int> * root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>*root){
    if(root==NULL){
        return true;
    }
    int leftmax = maximum(root->left); ///
    int rightmin = minimum(root->right);
    bool output = (root->data > leftmax && root->data <= rightmin && isBST(root->left) && isBST(root->right));
        return output;
  
}

/*vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output= push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}*/

int main(){
   //BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
     //BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
     //BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
       //     root->left = node1;
         //   root->right = node2;
         BinaryTreeNode<int>* root = takeInputLevelWise();
            cout<< isBST(root)<<endl;
           // vector<int>* output = getRootToNodePath(root, 8);
            //for(int i=0;i< output->size();i++){
                //cout<<output[i]<<end;
         //   }
          //  delete output;
            delete root;
        




}