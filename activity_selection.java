// importing ALL classes from package                                                      importing all java classes........
import java.util.*;
// making a public class 
public class activity_selection {
    public static void main(String[] args) {
        // making two arrays one for the starting of the activities 
        //and one for the ending of the activities \

        int start[] = {1,3,0,5,8,5};
        int end[] = {2,4,6,7,9,9};

        // end time basis sorted 
          
        // created a variable to calculate how
        // much max activities can we perform in this array
        int maxAct = 0;
        // making a array list namede (ans) and would be storing the index 
        // of the selected index
        ArrayList<Integer>ans = new ArrayList<> ();
        // acc. to our greedy approach we always selct the first index as 
        // this question states the first activity would end the most early
        // so , storing the first activity in the arraylist (ANS)
        maxAct =1;
        ans.add(0);
        // NOW , this inLastEnd will be storing the end time of the last selcted activity
         int inLastEnd = end[0];
         // cheaking all the activities:

         for( int i  = 0 ; i < end.length ; i++){
         // if the start tinme of the current activity is more or equal to the end time of the last selected activity 
            if (start[i] >= inLastEnd){
                // if the (if block) gets true we execute : 
                //
                maxAct ++;
                ans.add(i);
                // update the new selected activity with its end time 
                inLastEnd = end [i];
            }
         }
         
         System.out.println("maxAct:"  + maxAct);
         for(int i =0;i<ans.size();i++){
            System.out.println("A" + ans.get(i)+" ");
         }
         System.out.println();
    } 
}


