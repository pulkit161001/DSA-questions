// https://www.geeksforgeeks.org/problems/search-pattern-z-algorithm--141631/1
// https://www.youtube.com/watch?v=CpZh4eF8QBw
// https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

class Solution
{
    
    ArrayList<Integer> search(String pat, String S)
    {
        ArrayList<Integer> ans = new ArrayList<>();
        int z[] = create_z(pat+"$"+S);
        // print(z);
        for(int i=0,n=z.length,pn=pat.length();i<n;i++){
            if(z[i]==pn)    ans.add(i-pn);
        }
        return ans;
    }
    int[] create_z(String s){
        int n=s.length(), ans[] = new int[n];
        int left=0, right=0;
        
        //l<=i<=r
        for(int i=1;i<n;i++){
            if(i>right){
                //we have to reassign our z box
                
                //starting pos
                left=i;
                //ending pos
                right=i;
                while(right<n && s.charAt(right)==s.charAt(right-left)){
                    right++;
                }
                
                //total length equals
                ans[i] = right-left;
                //only till right-1 index substring is equal
                right--;
            
                
            }else{
                
                //if we are in a z box/window then we don't have to calculate the value again and again
                
                //till left we have filled and current index is ith
                //so we have to go to (i-left)th index in the prefix substring
                int pi = i-left;
                
                int val = ans[pi];
                
                //{prefix substring calculated value} is smaller than z box boundry
                if(val<right-i+1){
                    //then directly put precalculated value
                    ans[i] = val;
                
                    
                }else{
                    //if value is touching boundry or exceeding boundry
                    //then there may be a chance that more char's are equal so, expand further
                    //so calculate the remaining value
                    
                    //thus we will set L as i and start matching from str[R]  onwards  
                    //and get new R then we will update interval [L,R] 
                    //and calculate Z[i]
                    left=i;
                    while(right<n && s.charAt(right)==s.charAt(right-left)){
                        right++;
                    }
                    
                    //total length equals
                    ans[i] = right-left;
                    //only till right-1 index substring is equal
                    right--;
                    
                }
            }
        }
        
        return ans;
    }
    void print(int z[]){
        for(int i:z){
            System.out.print(i+" ");
        }
        System.out.println();
    }
}
