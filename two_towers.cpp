#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::max;
using std::min;
using std::abs;
using std::cout;

void print(const vector<int> &vec)
{
    for (unsigned j=0; j<vec.size(); ++j)
        cout << vec[j] << ' ';
    cout << std::endl;
}

int main()
{
    int n_blocks;
    std::cin >> n_blocks;
    int max_sum = 0;
    vector<int> block_heights(n_blocks);
    for (int i=0; i<n_blocks; ++i) {
        std::cin >> block_heights[i];
        max_sum += block_heights[i];
    }
    vector<int> cur_heights(max_sum, -1);
    cur_heights[0] = 0;
    for (int i=0; i<n_blocks; ++i) {
        vector<int> prev_heights(cur_heights);
        for (int cur_diff = max_sum-1; cur_diff>=0; --cur_diff) {
            if (prev_heights[cur_diff] < 0)
                continue;
            int down = prev_heights[cur_diff];
            int up = down + cur_diff;
            int new_down = down + block_heights[i];
            int new_up = up + block_heights[i];
            cur_heights[abs(new_up - down)] =
                max(cur_heights[abs(new_up - down)], min(new_up, down));
            cur_heights[abs(up - new_down)] =
                max(cur_heights[abs(up - new_down)], min(new_down, up));
            cur_heights[cur_diff] = max(cur_heights[cur_diff],
                prev_heights[cur_diff]);
        }
    }
    cout << cur_heights[0] << std::endl;
}
            



