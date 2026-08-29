class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {

        // Step 1: Count frequency
        Map<Integer, Integer> freq = new HashMap<>();

        for (int barcode : barcodes) {
            freq.put(
                barcode,
                freq.getOrDefault(barcode, 0) + 1
            );
        }

        // Step 2: Sort barcodes by frequency descending
        List<int[]> items = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            items.add(new int[]{
                entry.getKey(),
                entry.getValue()
            });
        }

        items.sort((a, b) -> Integer.compare(b[1], a[1]));

        // Step 3: Fill answer
        int[] result = new int[barcodes.length];

        int index = 0;

        for (int[] item : items) {

            int barcode = item[0];
            int count = item[1];

            while (count > 0) {

                result[index] = barcode;

                count--;

                // Move by 2 so identical values
                // are never adjacent.
                index += 2;

                // Even positions exhausted.
                // Start filling odd positions.
                if (index >= result.length) {
                    index = 1;
                }
            }
        }

        return result;
    }
}