class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int count = 0;
        List<Integer> ans = new ArrayList<>();

        // First loop: Count occurrences of pivot and add elements < pivot
        for (int num : nums) {
            if (num == pivot) count++;
            else if (num < pivot) ans.add(num);
        }

        // Second loop: Add elements > pivot, inserting pivot elements in between
        for (int num : nums) {
            if (num > pivot) {
                while (count > 0) {
                    ans.add(pivot);
                    count--;
                }
                ans.add(num);
            }
        }

        // If any pivot elements remain, add them at the end
        while (count > 0) {
            ans.add(pivot);
            count--;
        }

        // Convert List<Integer> back to int[]
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        return result;
    }
}
