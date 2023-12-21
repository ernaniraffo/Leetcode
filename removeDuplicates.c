int removeDuplicates(int* nums, int numsSize) {
    int l = 0;

    for (int r = 1; r < numsSize; r += 1) {
        if (nums[l] != nums[r]) {
            nums[++l] = nums[r];
        }
    }

    return l + 1;
}
