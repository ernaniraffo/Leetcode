int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int num;
    for (int i = 0; i < numsSize; i += 1) {
        if (count == 0) {
            num = nums[i];
        }
        count += (nums[i] == num ? 1 : -1);
    }
    return num;
}