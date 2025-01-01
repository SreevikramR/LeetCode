class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::vector<vector<int>> stack;

        stack.insert(stack.begin(), {sr, sc});
        int initialColor = image[sr][sc];

        if (image[sr][sc] == color) {
            return image;
        }

        while(stack.size() > 0) {
            int newSr = stack.back()[0];
            int newSc = stack.back()[1];
            stack.pop_back();
            if (image[newSr][newSc] == initialColor) {
                image[newSr][newSc] = color;
                if (newSr > 0) stack.insert(stack.begin(), {newSr - 1, newSc});
                if (newSc > 0) stack.insert(stack.begin(), {newSr, newSc - 1});
                if (newSr < image.size() - 1) stack.insert(stack.begin(), {newSr + 1, newSc});
                if (newSc < image[0].size() - 1) stack.insert(stack.begin(), {newSr, newSc + 1});
            }
        }

        image[sr][sc] = color;
        return image;
    }
};
