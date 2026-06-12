/*
https://youtu.be/WTtuOj6FXE8?si=8QRl2GxS_lArka06&t=1788

binary lifting is finding the kth ancestor of the current node
instead of find parent's parent k times we can use binary lifting
e.g. 13th ancestor of the current node we can represent in the form of power of 2
13 = 2^3 + 2^2 + 2^0
for storing every ancestor of every parent we gonna use parent[][]
    1st cell represent current_node
    2nd cell represent 2^jth parent
parent[current_node][2^jth_parent] = kth_parent_node (if i take 2^i  jumps from cur node, which ancestor i will reach)
Note. We can't create parent[node][direct_jump] for a skewed tree we have n jumps so we have to create n*n size dp -> MLE
instead of jumping 2^jth from current node we will
    Find 2^(j-1)th parent and asked him to find 2^(j-1)th parent { 2^j = 2^(j-1) + 2^(j-1) }
    
    intermediate = parent[node][j-1]
    parent[node][j] = parent[intermediate][j-1]
    dimensions -> parent = n * log2(n) -> (depth jumps in power of 2 : 2^jth_jump = n where j = log2(n))
*/

// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
// LCA - https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii
class TreeAncestor {
    int par[][], col;
    public TreeAncestor(int n, int[] parent) {
        col = (int)(Math.log(n) / Math.log(2.0));
        par = new int[n][col+1];
        for(int i[]:par)    Arrays.fill(i,-1);
        for(int i=0;i<n;i++){
            par[i][0]=parent[i];
        }

        for(int jump=1;jump<=col;jump++){
            for(int node=1;node<n;node++){
                int inter = par[node][jump-1];
                if(inter==-1)   continue;
                par[node][jump] = par[inter][jump-1];
            }
        }

        // for(int i[]:par){
        //     for(int j:i){
        //         System.out.print(j+" ");
        //     }
        //     System.out.println();
        // }
    }
    
    public int getKthAncestor(int node, int k) {
        for(int j=col;j>=0;j--){
            //13 = 2^3 + 2^2 + 2^0 (1101)
            if( ((1<<j)&k) > 0){
                node = par[node][j];
                if(node==-1)    return -1;
            }
        }
        return node;
    }
}
