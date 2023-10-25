class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1); // Initialize the output vector with 1s.

        int leftProduct = 1;
        int rightProduct = 1;

        // Calculate the product of elements to the left of each element.
        for (int i = 0; i < n; i++) {
            output[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        // Calculate the product of elements to the right of each element.
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return output;
    }
};
