/*
Problem: 449. Serialize and Deserialize BST - Medium
Links: https://leetcode.com/problems



Detail:

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. 
You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Example 1:
    Input: root = [2,1,3]
    Output: [2,1,3]

Example 2:
    Input: root = []
    Output: []
 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The input tree is guaranteed to be a binary search tree.

*/



#include <queue>
#include <string>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root==nullptr) return {};

        string result=to_string(root->val)+'_';
        queue<TreeNode*> tmp;
        tmp.push(root);;
        while (!tmp.empty()){
        
                result+= to_string( tmp.front()->val ) + '_';

                if( tmp.front()->left != nullptr )
                    tmp.push( tmp.front()->left );

                if( tmp.front()->right != nullptr )
                    tmp.push( tmp.front()->right );

                tmp.pop();
        }
      return result;  
    }

    void addNode(TreeNode* &root , int a){
        if(root == nullptr){
            root = new TreeNode(a);
            return;
        }
        
        if(a < root->val)
            addNode(root->left,a);
        
        else if(a > root->val)
            addNode(root->right,a);
        
        else
            return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        TreeNode* res=nullptr;

        for(size_t i=0;i<data.size();i++){
            string tmp="";
            while(data[i]!='_' and i<data.size()){
                tmp.push_back(data[i]);
                i++;
            }
            addNode(res,stoi(tmp));
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;