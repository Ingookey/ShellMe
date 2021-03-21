import heapq

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        li = [1,]
        return k

if __name__ == "__main__":

    ll=[1,4,2,3,5]
    ss = Solution.maxSlidingWindow(ll, 3)
    print("ss: ".format(ss))

    if False:
        ll=[1,4,2,3,5]
        print(ll,'原始数组')
        heapq.heapify(ll)
        print(ll,'小根堆')
        # 此时若想得到大顶堆
        newl = [-ll[i] for i in range(len(ll))]
        print(newl,'插入负数后的小根堆')
        heapq.heapify(newl) #以插入的负数做小根堆，越大的数字插入的负数就越小，所以这样就相当于做了大根堆
        # 此时已经按照第一个值变成了小顶堆，即变成了逆序
        max_heap = list()
        while newl:
            _, s = heapq.heappop(newl) #删除并返回 newl中的最小元素
            max_heap.append(s)