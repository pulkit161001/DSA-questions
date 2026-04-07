// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class DSU{
    int parent[];
    int rank[];
    DSU(int n){
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    
    void union(int x,int y){
        int px=find(x), py=find(y);
        if(px==py){
            return;
        }
        if(rank[px]<rank[py]){
            parent[px]=py;
        }else if(rank[py]<rank[px]){
            parent[py]=px;
        }else{
            parent[px]=py;
            rank[py]++;
        }
    }
}
class Solution {
    public int spanningTree(int V, int[][] edges) {
        int components=V, mst=0, max=Integer.MAX_VALUE;
        DSU dsu = new DSU(V);
        //n different vertex (store nbr_node, nbr_wgt)
        int closest[][] = new int[V][2];
        for(int i=0;i<V;i++)    closest[i][1] = max;
        
        //we have to decrease the component from V to only 1 
        while(components>1){
            
            //traverse all edges and store the closest nodes in representative
            for(int e[]:edges){
                int u=e[0], v=e[1], w=e[2];
                int pu=dsu.find(u), pv=dsu.find(v);
                //already in the same component
                if(pu==pv)  continue;
                
                //store min_weight (closest) edge in the pu
                if(w<closest[pu][1]){
                    closest[pu][0]=pv;
                    closest[pu][1]=w;
                }
                //undirect edge
                //store min_weight (closest) edge in the pv
                if(w<closest[pv][1]){
                    closest[pv][0]=pu;
                    closest[pv][1]=w;
                }
            }
            
            //combine the components
            for(int i=0;i<V;i++){
                //if there's an closest edge
                if(closest[i][1]!=max){
                    int u=i, v=closest[i][0], w=closest[i][1];
                    int pu=dsu.find(u), pv=dsu.find(v);
                    //if it is already connected (as we have undirected edge)
                    if(pu==pv)  continue;
                    
                    //not already connected
                    mst+=w;
                    dsu.union(pu,pv);
                    components--;
                }
            }
            
            //reset the closest array to find closest for combined component
            for(int i=0;i<V;i++)    closest[i][1] = max;
        }
        
        return mst;
    }
}
