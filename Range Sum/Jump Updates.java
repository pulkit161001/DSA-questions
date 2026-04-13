// https://www.youtube.com/watch?v=sG5Lm8vi-2Q
/*  
       0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
arr = [1,5,2,6,2,6,2,8,1,6,2, 6, 2, 6,  3, 6, 2]

[[left,right,val,jump]]
[[1,6,7,2],[4,6,2,3],[3,14,5,6]]

DAT (difference array technique)

arr = [1,5,2,6,2,6,2,8,1,6,2, 6, 2, 6,  3, 6, 2]
diff =[0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0,  0, 0, 0]

//update
diff[l]+=val
diff[r+1]-=val
//compute after processing all queries
diff[i]+=diff[i-1]

- with jumps update

               l                  r            (jump=5) -> 4,9,14
       0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
diff =[0,0,0,0,+,0,0,0,0,+,0, 0, 0, 0,  -, 0, 0]

//update
diff[l]+=val
diff[next]-=val (instead of r+1) 
next = (steps inside the range + one more jump)
steps inside = (r-l)/jump
next = l + (steps_inside+1)*jump
//compute after processing all queries
diff[i]+=diff[i-jump]

*/
