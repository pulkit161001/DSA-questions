// https://leetcode.com/problems/range-sum-query-mutable/description/
// https://www.youtube.com/watch?v=aI10OoSvhUI
class NumArray {
    int block[], block_size, a[];
    public NumArray(int[] nums) {
        int n=nums.length;
        // ceil bcz n=8 we get sqrt=2 we have 4 blocks but we want less groups
        // ceil will give 3 blocks only
        block_size = (int)Math.ceil(Math.sqrt(n));
        block = new int[block_size];
        a = new int[n];
        
        for(int i=0;i<n;i++){
            int id = i/block_size;
            block[id]+=nums[i];
            a[i] = nums[i];
        }
    }
    
    public void update(int index, int val) {
        int diff = val - a[index];
        
        int id = index/block_size;
        block[id] += diff;
        a[index] += diff;
    }
    
    // [2,3,1, 2,5,6, 8,1,3]
    //    l             r
    public int sumRange(int left, int right) {
        int leftBlock = left/block_size, rightBlock = right/block_size;
        int ans=0;

        //case 1: (l,r) in same block
        if(leftBlock == rightBlock){    
            for(int i=left;i<=right;i++){
                ans+=a[i];
            } 
            return ans;
        }

        //case 2: (l,r) in diff block
        // (l,l_block_end) + (next_block_start, next_block_end) + (r_block_start,r)
        // traverse (sqrt n) + (saved) + traverse (sqrt n)
        
        //next_block_starting_index - 1
        int left_end = (leftBlock+1)*block_size-1;
        for(int i=left;i<=left_end;i++){
            ans+=a[i];
        }

        //next_of_start_block to (prev_of_start_r_block)
        for(int i=leftBlock+1;i<rightBlock;i++){
            ans+=block[i];
        }

        //r_block_start_index to r
        int right_start = rightBlock*block_size;
        for(int i=right_start;i<=right;i++){
            ans+=a[i];
        }

        return ans;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
