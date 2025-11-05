#include <iostream>
#include <vector>

struct DisjointSet{
    std::vector<int> parent;
    std::vector<int> size;

    DisjointSet(int n) : parent(n + 1), size(n + 1, 1){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return false;
        }
        if(size[a] < size[b]){
            std::swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> know_people(n);
    std::vector<std::vector<int>> parties;

    int know_truth_people;
    std::cin >> know_truth_people;
    for(int i = 0; i < know_truth_people; i++){
        std::cin >> know_people[i];
    }

    std::vector<std::vector<int>> guestbooks;
    for(int i = 0; i < m; i++){
        int guests; 
        std::cin >> guests;
        std::vector<int> guestbook(guests);
        for(int j = 0; j < guests; j++){
            std::cin >> guestbook[j];
        }
        guestbooks.push_back(guestbook);
    }

    DisjointSet djs(n);
    for(auto &guests : guestbooks){
        for(int i = 1; i < guests.size(); i++){
            djs.unite(guests[0], guests[i]);
        }
    }

    std::vector<bool> truthRoot(n + 1, false);
    for(int p : know_people){
        truthRoot[djs.find(p)] = true;
    }

    int answer = 0;
    for(auto &guests : guestbooks){
        bool ok = true;
        for(int guest : guests){
            if(truthRoot[djs.find(guest)]){
                ok = false;
                break;
            }
        }

        if(ok){
            answer++;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}