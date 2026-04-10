class NumArray {
    FenwickTree ft;
    public NumArray(int[] nums) {
        int n=nums.length;
        ft=new FenwickTree(nums,n+1);
        // Now it's O(n*logn)
        // we can acheive in O(n) 
        // https://youtu.be/uSFzHCZ4E-8?t=460&si=OZSDgQKLCxKQm0t3
        for(int i=0;i<n;i++){
            ft.update(i+1,nums[i]);
        }
    }
    
    public void update(int index, int val) {
        int pre = ft.a[index];
        int new_val = val-pre;
        ft.update(index+1,new_val);
        ft.a[index]=val;
    }
    
    public int sumRange(int left, int right) {
        return ft.range(left+1,right+1);
    }
}

class FenwickTree{
    int n;
    int ft[];
    int a[];
    FenwickTree(int a[],int n){
        this.n=n;
        this.a=a;
        ft=new int[n];
    }
    
    int sum(int i){
        int ans=0;
        while(i>0){
            ans+=ft[i];
            i-=( i&(-i) );
        }
        return ans;
    }
    
    void update(int i,int x){
        while(i<n){
            ft[i]+=x;
            i+=( i&(-i) );
        }
    }
    
    int range(int l,int r){
        return sum(r) - sum(l-1);
    }
}
