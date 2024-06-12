class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int[] step = {0, 0};
        int startR = 0, startC=0;
        
        while (n-1>0) {
            int r=startR, c=startC;
            step[0] = n-1;
            step[1] = 0;
            for (int i=0; i<n-1; i++) {
                int tmp = matrix[r][c];
                for (int j=0; j<4; j++) {
                    if (j==3) matrix[r][c] = tmp;
                    else matrix[r][c] = matrix[r+step[0]][c+step[1]];
                    r += step[0];
                    c += step[1];
                    
                    int tmp2 = step[1];
                    step[1] = step[0];
                    step[0] = -1 * tmp2;
                }
                step[0]--;
                step[1]--;
                c++;
            }
            n -= 2;
            startR++;startC++;
        }
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] matrix = {
            {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}
        };

        solution.rotate(matrix);
    }
}