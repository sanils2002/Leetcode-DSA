class StockPrice {
private:
    map<int, int> prices;
    set<pair<int, int>> max_prices;
    set<pair<int, int>> min_prices;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        // Update the price at the given timestamp
        auto it = prices.find(timestamp);
        if(it != prices.end()) {
            // Remove the old price-timestamp pairs from the max and min prices sets
            max_prices.erase({it->second, timestamp});
            min_prices.erase({it->second, timestamp});
        }
        prices[timestamp] = price;

        // Update the max price
        max_prices.insert({price, timestamp});

        // Update the min price
        min_prices.insert({price, timestamp});
    }
    
    int current() {
        // Return the latest price of the stock
        return prices.rbegin()->second;
    }
    
    int maximum() {
        // Return the maximum price of the stock
        auto max_pair = *max_prices.rbegin();
        if(prices[max_pair.second] == max_pair.first) {
            // If the max price is from the latest timestamp, return it directly
            return max_pair.first;
        } 
        else {
            // Otherwise, search for the latest price with the same value
            for(auto it = prices.rbegin(); it != prices.rend(); ++it) {
                if(it->second == max_pair.first) {
                    return max_pair.first;
                }
            }
        }
        return -1; // No max price found
    }
    
    int minimum() {
        // Return the minimum price of the stock
        auto min_pair = *min_prices.begin();
        if(prices[min_pair.second] == min_pair.first) {
            // If the min price is from the latest timestamp, return it directly
            return min_pair.first;
        } 
        else {
            // Otherwise, search for the latest price with the same value
            for(auto it = prices.rbegin(); it != prices.rend(); ++it) {
                if(it->second == min_pair.first) {
                    return min_pair.first;
                }
            }
        }
        return -1; // No min price found
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */