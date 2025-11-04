#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>

double answer;
int total_x = 0, total_y = 0;

void brute_force(std::vector<std::pair<int, int>> &points, int idx, int selected_x, int selected_y, int count){
    if(count == points.size() / 2){
        double diff_x = 2 * selected_x - total_x;
        double diff_y = 2 * selected_y - total_y;

        double curr_dist = sqrt(diff_x*diff_x + diff_y*diff_y);
        answer = std::min(answer, curr_dist);

        return;
    }

    if(idx == points.size()){
        return;
    }

    brute_force(points, idx + 1, selected_x + points[idx].first, selected_y + points[idx].second, count + 1);
    brute_force(points, idx + 1, selected_x, selected_y, count);

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        total_x = 0, total_y = 0;
        answer = std::numeric_limits<double>::max();
        int n;
        std::cin >> n;

        std::vector<std::pair<int ,int>> points(n);
        for(int j = 0; j < n; j++){
            std::cin >> points[j].first >> points[j].second;
            total_x += points[j].first;
            total_y += points[j].second;
        }

        brute_force(points, 0, 0, 0, 0);

        std::cout << std::fixed << std::setprecision(12) << answer << "\n";
    }

    return 0;
}