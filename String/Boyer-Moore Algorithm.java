// https://www.geeksforgeeks.org/problems/search-pattern0205/1
// https://www.youtube.com/watch?v=4Xyhb72LCX4
// https://youtu.be/Wj606N0IAsw?si=ojVgaxIzW57QBgSy

________________________________________________________________________
// Part 1: Bad Character Rule
// mismatch char -> swift pattern that many index to match char on both strings
// https://www.geeksforgeeks.org/dsa/boyer-moore-algorithm-for-pattern-searching/

class Solution {
    ArrayList<Integer> search(String pat, String txt) {
        int pn = pat.length(), tn = txt.length();
        ArrayList<Integer> ans = new ArrayList<>();
        int idx[] = new int[26];
        Arrays.fill(idx,-1);
        
        // store char corresponding index (update for duplicate char's)
        for(int i=0;i<pn;i++){
            idx[pat.charAt(i)-'a']=i;
        }
        
        int i=0;
        while(i+pn<=tn){
            int j=pn-1;
            
            // traverse right to left
            while(j>=0 && txt.charAt(i+j)==pat.charAt(j)){
                j--;
            }

            // entire pattern matched
            if(j<0){
                ans.add(i);
                // find txt next char after pattern length char (index should be valid)
                i+=(i+pn<tn?pn-idx[txt.charAt(i+pn)-'a']:1);
            }else{
                //mismatch case
                //1. same char exist in pattern -> shift pattern that many forward
                //2. no matched char there -> shift entire pattern string after this char index
                i+=Math.max(1,j-idx[txt.charAt(i+j)-'a']);
            }
        }
        
        return ans;
    }
}

________________________________________________________________________
// Part 2: Good Suffix Rule
// https://www.geeksforgeeks.org/dsa/boyer-moore-algorithm-good-suffix-heuristic/

/*
mismatch char -> (suffix already matched... can I align it somewhere else in the pattern)
case 1. another occurance of suffix(denoted by t) -> switch pattern to align with the txt string
case 2. no exact match of suffix -> A prefix of P, which matches with suffix of t in T
case 3. no match -> swift pattern past the suffix t
  */
