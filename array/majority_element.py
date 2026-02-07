def majority_element(nums):
    if not nums:
        return -1
    n = len(nums)
    el = nums[0]
    cnt = 1
    for i in range(1, n):
        if cnt == 0:
            el = nums[i]
        if nums[i] == el:
            cnt += 1
        else:
            cnt -= 1

    total_cnt = 0

    for i in range(0, n):
        if nums[i] == el:
            total_cnt += 1

    if total_cnt > (n // 2):
        return el
    return -1

def main():
    nums = [6,5,5]
    print(majority_element(nums))

if __name__ == "__main__":
    main()