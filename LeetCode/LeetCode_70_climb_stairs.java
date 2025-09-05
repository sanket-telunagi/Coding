/**
 * LeetCode_70_climb_stairs
 */
import java.util.Scanner; 
class Solution {
    public int climbStairs(int n) {
        int a = 0 , b = 3, c = 2 ;
        if (n <= 3) return n ;

        for (int i = 4; i <= n ; i++) {
            a = b + c ;
            c = b ;
            b = a ;
        }
        return a;
    }
}
public class LeetCode_70_climb_stairs {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt() ;
        Solution s = new Solution() ;
        System.out.println(s.climbStairs(n)) ;
        sc.close() ;
    }
}