class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int beds_placed = 0;
        int flowerbedLength = flowerbed.size();
        int left_plot, right_plot;
        for (int i = 0; i < flowerbedLength; i += 1) {
            if (!flowerbed[i]) {
                left_plot = (i == 0 ? 0 : flowerbed[i - 1]);
                right_plot = (i + 1 == flowerbedLength ? 0 : flowerbed[i + 1]);

                if (!left_plot and !right_plot) {
                    flowerbed[i] = 1;
                    beds_placed += 1;
                    if (beds_placed == n) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
