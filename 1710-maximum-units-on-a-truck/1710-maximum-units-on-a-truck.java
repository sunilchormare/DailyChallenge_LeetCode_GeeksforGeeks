class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
       
        Arrays.sort(boxTypes,(a,b)-> b[1]-a[1]);
        
         int maxUnitNoOfBoxes=0;
        
        for(int a[]:boxTypes)
        {
            int noOfBoxes=a[0];
            int noOfUnitsPerBox=a[1];
            if(truckSize>=noOfBoxes)
            {
                maxUnitNoOfBoxes+=noOfUnitsPerBox*noOfBoxes;
                truckSize-=noOfBoxes;
            }
            else
            {
              maxUnitNoOfBoxes+=noOfUnitsPerBox*truckSize;
                return maxUnitNoOfBoxes;
                
            }
            
        }
        return maxUnitNoOfBoxes;
    }
}