/*
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

*/
class Solution {
  public:
    int height(Node *root, int &res , unordered_map<Node * ,int> &mp)
    {
        if(root == nullptr)
        {
            return 0 ;
        }
        if(mp.find(root) != mp.end())
        {
            return mp.find(root)->second ;
        }
    
        int lh;
        if(mp.find(root->left) != mp.end())
        {
            lh = mp.find(root->left)->second ;
        }
        else
        {
            lh = height(root->left , res , mp);
            mp[root->left] = lh ;
        }
        
        int rh;
        
        if(mp.find(root->right) != mp.end())
        {
            rh = mp.find(root->right )->second ;
        }
        else{
            
            rh = height(root->right , res , mp);
            mp[root->right] = rh ;
            
            }
            
        res = max(res , lh + rh + 1);
        
        return mp[root] = max(lh , rh) + 1 ;
    }
    
    int diameter(Node* root) {
        
        int res = INT_MIN , temp ;
        
        unordered_map<Node * , int> mp ;
        
        temp = height(root , res , mp) ;
        return res ;
        
    }
};