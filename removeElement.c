int removeElement(int* nums, int numsSize, int val) {
    int pos = 0;
    for (int i = 0; i < numsSize; i += 1) {
        if (nums[i] != val) {
            nums[pos] = nums[i];
            pos += 1;
        }
    }
    return pos;
}