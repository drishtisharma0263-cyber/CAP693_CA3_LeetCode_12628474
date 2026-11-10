void rotate(int* nums, int numsSize, int k)
{
    int temp[numsSize];
    int i;

    k = k % numsSize;

    for (i = 0; i < numsSize; i++)
    {
        temp[(i + k) % numsSize] = nums[i];
    }

    for (i = 0; i < numsSize; i++)
    {
        nums[i] = temp[i];
    }
}
