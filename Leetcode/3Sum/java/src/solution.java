import java.util.*;

class Solution {
    private List<List<Integer>> twoSum(int[] nums, int target, List<List<Integer>> ans) {
        int left=0, right=nums.length-1;

        while (left < right) {
            int cur = nums[left] + nums[right];
            if (cur == target) {
                ans.add(Arrays.asList(-1*target, nums[left], nums[right]));

                left++;
                while(left<right && nums[left]==nums[left-1]) left++;
                right--;
                while(left<right && nums[right]==nums[right+1]) right--;
            } else if (cur < target) {
                left++;
            } else { // cur > target
                right--;
            }
        }

        return ans;
    }
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();

        for (int i=0; i<nums.length; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            
            List<List<Integer>> res = twoSum(Arrays.copyOfRange(nums, i+1, nums.length), nums[i] * -1, ans);
        }
        
        return ans;
    }
}

class Main {
    static public void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {0,-1,0,1,2,-1,1,-4};

        List<List<Integer>> ans = solution.threeSum(nums);
    }
}