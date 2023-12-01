/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;

    for (int i = digitsSize - 1; i >= 0; i -= 1) {
        if (i > 0 && digits[i] != 9) {
            break;
        } else if (i == 0 && digits[i] == 9) {
            *returnSize += 1;
        }
    }

    if (*returnSize > digitsSize) {
        int* ans = calloc(*returnSize, sizeof(int));
        ans[0] = 1;
        return ans;
    }

    int* ans = calloc(*returnSize, sizeof(int));

    int i = *returnSize - 1;
    int sum;
    int carry = 1;

    while (i >= 0) {
        sum = digits[i] + carry;
        carry = (sum == 10);
        ans[i] = sum % 10;
        i -= 1;
    }

    return ans;
}
