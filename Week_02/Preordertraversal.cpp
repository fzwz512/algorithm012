class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;  
        stack<TreeNode*> call;  
        if(root!=nullptr) call.push(root); 
        while(!call.empty()){
            TreeNode *t = call.top();
            call.pop(); 
            if(t!=nullptr){
                if(t->right) call.push(t->right); 
                if(t->left) call.push(t->left);
                call.push(t);  
                call.push(nullptr);  
            }else{  
                res.push_back(call.top()->val);  
                call.pop();  
            }
        }
        return res;
    }
};