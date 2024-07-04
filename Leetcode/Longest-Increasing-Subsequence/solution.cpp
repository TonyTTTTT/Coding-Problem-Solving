#include <vector>
#include <algorithm>
using namespace std;

struct MyTreeNode {
    int val;
    int curMax = 0;
    MyTreeNode* left = nullptr;
    MyTreeNode* right = nullptr;

    MyTreeNode(int x) : val(x) {};
};

class Solution {
private:
    MyTreeNode* createBalancedBST(vector<int>& sortedNums, int l, int r) {
        if (l > r) return nullptr;

        int mid = (l+r) / 2;

        MyTreeNode* root = new MyTreeNode(sortedNums[mid]);
        root->left = createBalancedBST(sortedNums, l, mid-1);
        root->right = createBalancedBST(sortedNums, mid+1, r);

        return root;
    }
    
    void findCurMax(MyTreeNode* root, int num, int& curMax) {
        if (!root) return;

        if (root->val == num) {
            findCurMax(root->left, num, curMax);
            root->curMax = curMax;
        } else if (root->val < num) {
            curMax = max(curMax, root->curMax+1);
            findCurMax(root->right, num, curMax);
        } else { //root->val > num
            findCurMax(root->left, num, curMax);
            root->curMax = max(root->curMax, curMax);
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        MyTreeNode* root = createBalancedBST(sortedNums, 0, sortedNums.size()-1);
        int curMax;

        for (auto num : nums) {
            curMax = 1;
            findCurMax(root, num, curMax);
            ans = max(ans, curMax);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7,7,7,7,7,7,7};

    int ans = solution.lengthOfLIS(nums);

    return 0;
}

