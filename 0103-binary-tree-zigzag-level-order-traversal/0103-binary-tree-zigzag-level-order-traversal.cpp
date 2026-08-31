class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;                 // final answer — sab levels ki rows

        if(root == NULL)
        {
            return result;                            // empty tree → empty result
        }

        queue<TreeNode*> q;                          // BFS queue

        q.push(root);                                 // level 0 se start

        bool lefttoright = true;                      // level 0 hamesha L→R

        while(!q.empty())                             // jab tak levels bache hain
        {
            int n = q.size();                          // current level ke total nodes (fix karo pehle hi)

            vector<int> row(n);                        // is level ka result (fixed size)

           for(int i = 0;i < n;i++)                     // sirf current level process karo
            {
                TreeNode* node = q.front();              // agla node uthao
                q.pop();                                 // queue se hata do

                int index = lefttoright ? i : n-i-1;      // direction ke hisaab se position
                row[index] = node->val;                   // value us position pe rakho

                if(node->left)
                {
                    q.push(node->left);                   // next level ke liye left child
                }
                if(node->right)
                {
                    q.push(node->right);                  // next level ke liye right child
                }
            }
            lefttoright = !lefttoright;  //flip           // agle level ke liye direction ulti
            result.push_back(row);                        // ye level ka row final answer mein

        }
        return result;                                    // saare levels done

        
    }
};