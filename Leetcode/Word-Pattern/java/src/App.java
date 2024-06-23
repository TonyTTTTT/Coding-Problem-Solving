import java.util.HashMap;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;

        HashMap<Character, String> map = new HashMap<>();

        for (int i=0; i<pattern.length(); i++) {
            if (map.containsKey(pattern.charAt(i))) {
                if (!map.get(pattern.charAt(i)).equals(words[i])) return false;
            } else {
                if (map.containsValue(words[i])) return false;
                map.put(pattern.charAt(i), words[i]);
            }
        }

        return true;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String pattern = "abba";
        String s = "dog cat cat dog";

        boolean ans = solution.wordPattern(pattern, s);
    }
}