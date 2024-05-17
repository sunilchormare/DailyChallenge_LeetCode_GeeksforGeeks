class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int size1=nums1.length,size2=nums2.length;
        Map<Integer,Integer> nm=new HashMap<>();
        for(int i=0;i<size1;i++)
        {
            for(int j=0;j<size2;j++)
            {
                int val=nums2[j]-nums1[i];
                nm.put(val, nm.getOrDefault(val,0)+1);
            }
        }
        int mini=Integer.MAX_VALUE;
        for(int k:nm.keySet())
        {
            int arr[]=new int[size1];
            for(int i=0;i<size1;i++)
            {
                arr[i]=nums1[i]+k;
            }
            Arrays.sort(arr);
            if(check(arr,nums2))
            {
                mini=Math.min(mini,k);
            }
        }
        return mini;
    }
    private boolean check(int nums1[], int nums2[])
    {
        int i=0,j=0,val=2;
        while(i<nums1.length && j<nums2.length)
        {
            if(nums1[i] == nums2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
                val--;
                if(val < 0)
                {
                    return false;
                }
            }
        }
        return j == nums2.length && (i-j) <= 2;
    }
}