package org.uva.solver;

import java.util.Scanner;

public class Main {
    private static int algo(int x) {
        int cnt = 1;
        while(x != 1) {
            if(x % 2 == 1) {
                x = 3 * x + 1;
            }
            else {
                x = x/2;
            }
            cnt += 1;
        }
        return cnt;
    }
    public static void main(String[] args) {
        int a, b, minab, maxab, ans;
        Scanner input = new Scanner(System.in);
        while(input.hasNextInt()) {
            ans = 0;
            a = input.nextInt();
            b = input.nextInt();
            minab = Math.min(a, b);
            maxab = Math.max(a, b);

            for (int i = minab; i <= maxab; i++) {
                int res = algo(i);
                if (res > ans) {
                    ans = res;
                }
            }
            System.out.printf("%d %d %d\n", a, b, ans);
        }
    }
}