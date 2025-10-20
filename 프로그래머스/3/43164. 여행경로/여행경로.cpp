#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string start, vector<bool> &visited, vector<vector<string>> &tickets, vector<string> &result){
    if(tickets.size() + 1 == result.size()){
        return 1;
    }

    for(int i = 0; i < tickets.size(); i++){
        if(!visited[i] && tickets[i][0] == start){
            result.push_back(tickets[i][1]);
            visited[i] = true;

            if(dfs(tickets[i][1], visited, tickets, result))
                return true;

            visited[i] = false;
            result.pop_back();
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end(), 
         [](const vector<string>& a, const vector<string>& b){
                if(a[0] == b[0])
                    return a[1] < b[1];
                return a[0] < b[0];
         });

    vector<string> result;
    vector<bool> visited(tickets.size(), false);

    result.push_back("ICN");
    dfs("ICN", visited, tickets, result);

    return result;
}