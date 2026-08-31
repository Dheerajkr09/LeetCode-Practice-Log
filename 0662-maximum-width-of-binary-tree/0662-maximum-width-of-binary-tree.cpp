class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned int>> q;   // unsigned int 

        q.push({root, 0});

        while(!q.empty())
        {
            int levelSize = q.size();
            unsigned int minIndex = q.front().second;
            unsigned int leftMostIndex, rightMostIndex;

            for(int i = 0; i < levelSize; i++)
            {
                unsigned int currIndex = q.front().second - minIndex;
                TreeNode* currNode = q.front().first;
                q.pop();
                if(i == 0) leftMostIndex = currIndex;
                if(i == levelSize - 1) rightMostIndex = currIndex;

                if(currNode->left)
                    q.push({currNode->left, currIndex*2+1});
                if(currNode->right)
                    q.push({currNode->right, currIndex*2+2});
            }
            maxWidth = max(maxWidth, (int)(rightMostIndex - leftMostIndex + 1));
        }
        return maxWidth;
    }
};