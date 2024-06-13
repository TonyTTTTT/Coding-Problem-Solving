import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public boolean isAnagram(String s, String t) {
        int[] map = new int[26];

        for (char c : s.toCharArray()) {
            map[c-97]++;
        }

        for (char c : t.toCharArray()) {
            map[c-97]--;
        }

        for (int cnt : map) {
            if (cnt != 0) return false;
        }

        return true;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "called";
        String t = "llaecd";

        boolean ans = solution.isAnagram(s, t);
    }
}