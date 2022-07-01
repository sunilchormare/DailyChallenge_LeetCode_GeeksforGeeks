class Solution {
public:
    static bool comparator(vector<int>&a, vector<int> &b)
    {
        return (a[1] > b[1]);
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
         sort(boxTypes.begin(),boxTypes.end(),comparator);
        
         int maxUnitNoOfBoxes=0;
        
        for(vector<int> a:boxTypes)
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
};