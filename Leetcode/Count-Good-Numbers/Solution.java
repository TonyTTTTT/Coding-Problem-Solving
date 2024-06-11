// import java.util.*;
import java.math.BigInteger;

class Solution {
    public int countGoodNumbers(long n) {
        BigInteger ans = new BigInteger("5");
        ans = ans.pow((int)Math.ceil((double)n/2));

        BigInteger four = new BigInteger("4");
        four = four.pow((int)n/2);

        ans = ans.multiply(four);

        ans = ans.mod(BigInteger.valueOf(1000000007));

        return ans.intValue();
    }

    public static void main(String[] args) {
        long n = 806166225460393L;
        Solution solution = new Solution();
        int ans = solution.countGoodNumbers(n);
    }
}