#include<iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int level;
    node(int x, int l){
        level = l;
        val = x;
        left = NULL;
        right = NULL;
    }
};

node * add_node(node * root, int x){
    if(root == NULL) root = new node(x, 1);
    else if(root->val < x){
        if(root->right == NULL){
            root->right = new node(x, root->level + 1);
        }else{
            root->right = add_node(root->right, x);
        }
    }else if(root->val > x){
        if(root->left == NULL){
            root->left = new node(x, root->level + 1); 
        }else{
            root->left = add_node(root->left, x);
        }
    }
    return root;
}

void print(node * root){
    if(root == NULL) return;
    print(root->left);
    cout << root->val << " at level: " << root->level << endl;
    print(root->right);
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

int max_level(node * root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        return root->level;
    }
    return max(max_level(root->left), max_level(root->right));
}

int main(){

    int x;

    node * root = NULL;

    while(cin >> x){
        if(x == 0){
            break;
        }
        root = add_node(root, x);
    }

    cout << max_level(root);

    return 0;
}