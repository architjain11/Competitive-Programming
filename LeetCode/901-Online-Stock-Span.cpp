class StockSpanner {
public:
    vector<int> prices;
    vector<int> span;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        
        span.push_back(1);
        int last=span.size()-1;
        
        for(int i=last-1; i>=0; i--) {
            if(prices[i]>prices[last]) break;
            span[last]+=span[i];
            i-=span[i]-1;
        }
        
        return span[last];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */