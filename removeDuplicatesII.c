int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int l = 2;
    for (int r = 2; r < numsSize; r += 1) {
        if (nums[r] != nums[l - 2]) {
            nums[l] = nums[r];
            l += 1;
        }
    }

    return l;
}
