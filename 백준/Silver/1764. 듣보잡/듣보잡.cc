#include <iostream>
#include <set>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::set<std::string> nh_persons;
    std::set<std::string> nhs_persons;

    for(int i = 0; i < n; i++){
        std::string person;
        std::cin >> person;
        nh_persons.insert(person);
    }
    for(int i = 0; i < m; i++){
        std::string person;
        std::cin >> person;
        if(nh_persons.find(person) != nh_persons.end()){
            nhs_persons.insert(person);
        }
    }

    std::cout << nhs_persons.size() << std::endl;
    for(auto &p : nhs_persons){
        std::cout << p << "\n";
    }

    return 0;
}