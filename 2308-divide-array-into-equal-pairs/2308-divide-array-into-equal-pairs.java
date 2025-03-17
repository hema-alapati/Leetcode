class Solution {
    public boolean divideArray(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();

        // Count occurrences of each number
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Check if all numbers appear an even number of times
        for (int count : freq.values()) {
            if (count % 2 != 0) {
                return false;
            }
        }

        return true;
    }
}