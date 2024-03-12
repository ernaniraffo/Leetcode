void rotate(int* nums, int numsSize, int k) {
    int count = 0;
    for (int start = 0; count < numsSize; start += 1) {
        int curr = start;
        int prev = nums[curr];
        while (1) {
            int next = (curr + k) % numsSize;

            int temp = nums[next];
            nums[next] = prev;
            prev = temp;

            count += 1;
            curr = next;

            if (curr == start) {
                break;
            }
        }
    }
}
