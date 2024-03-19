/*
levels starts from 1..find the level with the largest sum
Approach --> simple BFS to get sum at each level
*/
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int level = 1;
        int ansLevel = 0, currMaxSum = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (sum > currMaxSum)
            {
                currMaxSum = sum;
                ansLevel = level;
            }
            level++;
        }

        return ansLevel;
    }
};

