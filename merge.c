#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_START     3
#define MAX_INCREMENT 5

void print_array(int* nums, int numsSize) {
    printf("[");
    for (int i = 0; i < numsSize; i += 1) {
        printf("%d", nums[i]);
        printf("%s", (i + 1 == numsSize ? "]\n" : ", "));
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;

    int k;
    for (k = nums1Size - 1; k >= 0; k -= 1) {
        if (i >= 0 && j >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i--];
        } else if (j >= 0) {
            nums1[k] = nums2[j--];
        }
    }
}

void array_fill_rand(int* nums, int end) {
    int num = rand() % MAX_START;

    for (int i = 0; i < end; i += 1) {
        nums[i] = num;
        num += rand() % MAX_INCREMENT;
    }
}

bool is_sorted(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i += 1) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int m = -1;
    int n = -1;

    printf("Enter nums1.size nums2.size\n");
    scanf("%d %d", &m, &n);

    int* nums1 = calloc(m + n, sizeof(int));
    int* nums2 = calloc(n, sizeof(int));

    array_fill_rand(nums1, m);
    array_fill_rand(nums2, n);

    printf("\n");
    print_array(nums1, m + n);
    print_array(nums2, n);
    printf("\n");

    merge(nums1, m + n, m, nums2, n, n);

    print_array(nums1, m + n);

    if (!is_sorted(nums1, m + n)) {
        fprintf(stderr, "Sorting error: not sorted");
    }

    free(nums1);
    free(nums2);
}