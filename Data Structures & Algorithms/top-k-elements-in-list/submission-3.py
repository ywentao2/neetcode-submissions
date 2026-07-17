class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter()
        out = []
        for i in nums:
            freq[i] += 1
        buckets = [[] for i in range(len(nums) + 1)]
        for key, value in freq.items():
            buckets[value].append(key)
        for j in range(len(nums), 0, -1):
            if buckets[j] and len(out) < k:
                out.extend(buckets[j])
            if len(out) == k:
                break
        return out
