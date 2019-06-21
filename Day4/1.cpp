#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node * add_node(node * root, int x){
    if(root == NULL) root = new node(x);
    else if(root->val < x){
        if(root->right == NULL){
            root->right = new node(x);
        }else{
            root->right = add_node(root->right, x);
        }
    }else if(root->val > x){
        if(root->left == NULL){
            root->left = new node(x); 
        }else{
            root->left = add_node(root->left, x);
        }
    }
    return root;
}

void print(node * root){
    if(root == NULL) return;
    print(root->right);
    cout << root->val << " ";
    print(root->left);
}

int rightmost(node * root){
    if(root->right == NULL) return root->val;
    return rightmost(root->right);
}

node * del_node(node * root, int val){
    if(root == NULL) return root;
    if(root->val == val){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }else if(root->left != NULL && root->right == NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }else if(root->left == NULL && root->right != NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }else if(root->left != NULL && root->right != NULL){
            root->val = rightmost(root->left);
            root->left = del_node(root->left, root->val);
            return root;
        }
    }else if(root->val > val){
        root->left = del_node(root->left, val);
    }else if(root->val < val){
        root->right = del_node(root->right, val);
    }
    return root;
}

int main(){
    node * root = NULL;

    int a[] = {5, 7, 8, 2, 3, 1, -1, 10, 20, 0};

    for(int i = 0; i < 10; ++i){
        root = add_node(root, a[i]);
    }

    print(root);
    del_node(root, 8);
    del_node(root, 7);
    del_node(root, -1);
    del_node(root, 22);
    cout << endl;
    print(root);

    return 0;
}