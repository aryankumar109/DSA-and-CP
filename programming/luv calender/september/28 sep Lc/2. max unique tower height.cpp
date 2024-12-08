class Solution {
public:
    long long maximumTotalSum(vector<int>& heights) {
        unordered_map<int, int> heightCount;
        for (int height : heights) {
            heightCount[height]++;
        }

        sort(heights.rbegin(), heights.rend());
        long long totalSum = 0;
        int currentMax = heights[0];
        int p = heights[0] ;
        for (int& height : heights) {
            if (heightCount[height] > 1) {
                currentMax =min(p ,height) ;
                while (heightCount[currentMax] > 0) {
                    currentMax--;
                    if (currentMax == 0) return -1;
                }
                heightCount[height]--;
                height = currentMax;
                heightCount[currentMax]++;
                p = currentMax ;
            }
            totalSum += height;
        }

        return totalSum;
    }
};


