int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return numsSize;
    }

    int unique = 2;
    for (int i = 2; i < numsSize; i += 1) {
        if (nums[i] != nums[unique - 2]) {
            nums[unique] = nums[i];
            unique += 1;
        }
    }

    return unique;
}
