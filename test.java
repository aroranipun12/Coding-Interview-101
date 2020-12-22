import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Solution {

    


    public static void BFSPath(boolean [][] edges, int n, int sv, int end, boolean [] visited, ArrayList<Integer> arr)
    {
        Queue<Integer> q=new LinkedList<>();
        HashMap<Integer,Integer> map=new HashMap<>();
        // ArrayList<Integer> temp = new ArrayList<>();
        visited[sv]=true;
        q.add(sv);
       
       // boolean found=false;
        while(!q.isEmpty())
        {
            int currVertex=q.poll();
            
            // arr.add(currVertex);
            if(currVertex==end)
            {
                //found=true;
                
                break;
            }

            for(int i=0;i<n;i++)
            {

                // if(i==currVertex)
                //     continue;
                if(i!=currVertex&&edges[currVertex][i]&&!visited[i])
                {
                    q.add(i);
                    visited[i]=true;
                    
                    map.put(i,currVertex);
                }
            }
            q.poll();
            if (q.isEmpty())//null
            {
                return;
            }

        }
        arr.add(end);
        int i = end;
        while(i != sv)
        {
            arr.add(map.get(i));
            i = map.get(i);
        }
       arr.add(sv);
        
    }


    

	
 public static void main(String[] args) throws NumberFormatException, IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int e=sc.nextInt();
        if(n==0)
            return;
        if(e==0)
        {
            
            return;
        }
        boolean [][] edge=new boolean[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                edge[i][j]=false;

        }
        for(int i=0;i<e;i++)
        {
            int a=sc.nextInt();
            int b=sc.nextInt();
            edge[a][b]=true;
            edge[b][a]=true;
        }
        long V1=sc.nextLong();

        long V2=sc.nextLong();


//         if(V1>=n||V2>=n)
//         {
            
//             return;
//         }
        int v1=(int)V1;
        int v2=(int)V2;

        boolean [] visited=new boolean[n];
        for(int i=0;i<n;i++)
            visited[i]=false;
        ArrayList <Integer> list=new ArrayList<>();
         BFSPath(edge,n,v1,v2,visited,list);
         if(list.isEmpty())
             return;
        for(int i=0;i<list.size();i++)
            System.out.print(list.get(i)+" ");
       

    }
}