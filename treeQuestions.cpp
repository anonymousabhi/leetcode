#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};


TreeNode* newNode(int val);
void printLevelOrder(TreeNode* node);
int height(TreeNode* node);
void printV(vector<int> v);
void printLevelOrderZigzag(TreeNode* node);
void preOrderIterative(TreeNode* root);


TreeNode* newNode(int val){
    TreeNode* node = new TreeNode();
    node->val = val;
    node->left = node->right = NULL;
    
    return node;
}

void printV(vector<int> v){
    for(int index = 0;index<v.size();index++){
        cout<<v[index]<<"->";
    }
    cout<<endl;
}

void printMV(map<int,vector<int>> m){
    for (auto it :m)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<"->";
        cout<<endl;
    }
}

void printVReverse(vector<int> v){
    reverse(v.begin(),v.end());
    
    for(int index = 0;index<v.size();index++){
        cout<<v[index]<<" ";
    }
    cout<<endl;
}

void inorder(TreeNode* node){
    if(node == NULL){
        return;
    }    
    inorder(node->left);
    cout<<node->val<<" ";
    inorder(node->right);
}

int height(TreeNode * root){
    if(!root){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

void printLevelOrder(TreeNode* root){
    if(!root)
    return;
    queue<TreeNode*> q;
    q.push(root);
    cout<<"in the fuction"<<endl;
    
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left!= NULL){
            q.push(node->left);
        }
        if(node->right!= NULL){
            q.push(node->right);
        }
        cout<<node->val<<" ";
    }
    
    return;
}

void printLevelOrderByLevel(TreeNode* root){
    if(!root)
    return;
    
    queue<TreeNode*> q;
    vector<int> v;
    q.push(root);
    q.push(NULL);
    TreeNode* node = root;
    while(q.size()>1 || node!=NULL){
        node = q.front();
        q.pop();
        if(node == NULL){
            q.push(NULL);
            printV(v);
            v.clear();
            cout<<endl;
        }
        else{
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            v.push_back(node->val);
        }
    }
    return;
}

void printLevelOrderZigzag(TreeNode* root){
    if(!root)
    return;
    
    queue<TreeNode*> q;
    vector<int> v;
    q.push(root);
    q.push(NULL);
    TreeNode* node = root;
    bool lToR = false;
    
    while(q.size()>1 || node!=NULL){
        node = q.front();
        q.pop();
        if(node == NULL){
            q.push(NULL);
            if(lToR){
                printV(v);
            }else{
                printVReverse(v);
            }
            v.clear();
            cout<<endl;
            lToR = !lToR;
        }
        else{
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            v.push_back(node->val);
        }
    }
    return;
}

void preOrderIterative(TreeNode* root){
    if(!root)
    return;
    stack<TreeNode*> st;
    vector<int> v;
    st.push(root);
    TreeNode* node;
    
    while(!st.empty()){
        node = st.top();
        st.pop();
        
        v.push_back(node->val);
        if(node->right!=NULL){
            st.push(node->right);
        }
        if(node->left!=NULL){
            st.push(node->left);
        }
    }
    printV(v);
    return;
}

void allPaths(TreeNode* node, vector<int> v, int index){
    if(!node)
    return;
    v.push_back(node->val);
    index++;
    
    if(node->left==NULL &&node->right==NULL){
        printV(v);
    }else{
        allPaths(node->left, v, index);
        allPaths(node->right, v, index);
    }
}

void allPathSumImpl(TreeNode* node, vector<int> v, int index ,int sum){
    if(!node)
    return;
    v.push_back(node->val);
    index++;
    sum+=node->val;
    
    if(node->left==NULL &&node->right==NULL){
        printV(v);
        cout<<"Sum is : "<<sum<<endl;
    }else{
        allPathSumImpl(node->left, v, index,sum);
        allPathSumImpl(node->right, v, index,sum);
    }
}

void allZeroPathSumImpl(TreeNode* node, vector<int> v, int index ,int sum){
    if(!node)
    return;
    v.push_back(node->val);
    index++;
    sum+=node->val;
    
    if(sum == 0){
        printV(v);
        cout<<sum<<endl;
    }else{
        allZeroPathSumImpl(node->left, v, index,sum);
        allZeroPathSumImpl(node->right, v, index,sum);
    }
}

void allPathToLeaf(TreeNode* root){
    vector<int> v; 
    int index = 0;
    allPaths(root, v, index);
}

void allPathSum(TreeNode* root){
    vector<int> v; 
    int index = 0;
    int sum  = 0;
    allPathSumImpl(root, v, index,sum);
}

void allZeroPathSum(TreeNode* root){
    vector<int> v; 
    int index = 0;
    int sum  = 0;
    allZeroPathSumImpl(root, v, index,sum);
}

void diagonalTraversalImpl(TreeNode* node, map<int,vector<int>> &m, int val){
    if(!node)
    return;
    
    m[val].push_back(node->val);
    diagonalTraversalImpl(node->left, m,val+1);
    diagonalTraversalImpl(node->right,m,val);
}

void diagonalTraversal(TreeNode* root){
    map<int,vector<int>> m ;
    int val  = 0;
    diagonalTraversalImpl(root,m,val);
    printMV(m);
}

void verticalTraversalImpl(TreeNode* node, map<int,vector<int>> &m, int val){
    if(!node)
    return;
    
    m[val].push_back(node->val);
    verticalTraversalImpl(node->left, m,val-1);
    verticalTraversalImpl(node->right,m,val+1);
}

void verticalTraversal(TreeNode* root){
    map<int,vector<int>> m ;
    int val  = 0;
    verticalTraversalImpl(root,m,val);
    printMV(m);
}

int main() {
	
	TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	
	//inorder(root);
	//printLevelOrder(root);
	//cout<<endl;
	//int height_val = height(root);
	//cout<<height_val;
	//printLevelOrderByLevel(root);
	//printLevelOrderZigzag(root);

	//preOrderIterative(root);
    //postOrderIterative(root);
    
    //allPathToLeaf(root);
    //allPathSum(root);
    //allZeroPathSum(root);
    
    //diagonalTraversal(root);
	//verticalTraversal(root);
	
	
	
	return 0;
}




