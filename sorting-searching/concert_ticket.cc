#include<iostream>
#include<set>

void distribute_tickets(std::multiset<int>& ticket_price, int m){
    for(int i = 0; i < m; i++){
        int customer_offer;
        std::cin >> customer_offer;
        auto it = ticket_price.upper_bound(customer_offer);
        if(it == ticket_price.begin()){
            std::cout << -1 << std::endl;
        } else {
            --it; 
            std::cout << *it << std::endl;
            ticket_price.erase(it);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    
    std::multiset<int> ticket_price;
    for(int i = 0; i < n; i++){
        int price;
        std::cin >> price;
        ticket_price.insert(price);
    }
    
    distribute_tickets(ticket_price, m);
    return 0;
}
