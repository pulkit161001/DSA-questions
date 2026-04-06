static Long[] lcmAndGcd(Long A , Long B) {
    Long[] ans=new Long[2];
    ans[1]=gcd(A,B);
    ans[0]=(A*B)/ans[1];
    return ans;
}
    
static Long gcd(Long A, Long B){
    while(A%B!=0){
        Long rem=A%B;
        A=B;
        B=rem;
    }
    return B;
}
// Basic Euclidean Algorithm for GCD
static int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

//Extended Euclidean Algorithm
/*
Input: a = 30, b = 20
Output: gcd = 10, x = 1, y = -1
Explanation: 30*1 + 20*(-1) = 10

Diophantine Equations
ax + by = c (linear equation) 
(solution only if gcd(a,b) divides c)


ax + by = gcd(a,b)
gcd(a,b) = gcd(b%a,a)
gcd(b%a,a) = (b%a)x1 + ay1

ax + by = (b%a)x1 + ay1
ax + by = (b - [b/a] * a)x1 + ay1
ax + by = a(y1 - [b/a] * x1) + bx1

x = (y1 - [b/a] * x1)
y = x1
*/

// https://www.geeksforgeeks.org/problems/extended-euclidean-algorithm3848/1


class Solution {
    // ax + by = c
    // ax + by = gcd(a,b)
    static int[] gcd(int a, int b) {
        if(a==0){
            // a=0
            // by = gcd(0,b)
            // (y=1)
            // gcd, x, y 
            return new int[]{b,0,1};
        }
        
        // x = y1
        // y = x1 - (a/b)*y1
        // to find x1 and y1
        int small_ans[] = gcd(b%a,a);
        // small_ans store (gcd, x1, y1) return statement
        int gcd = small_ans[0], x1 = small_ans[1], y1 = small_ans[2];
        
        int x = y1 - (b/a)*x1;
        int y = x1;
        // gcd, x, y 
        return new int[]{gcd,x,y};
    }
}
