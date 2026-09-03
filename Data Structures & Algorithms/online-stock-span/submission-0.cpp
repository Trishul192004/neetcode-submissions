class StockSpanner {
public:
    StockSpanner() {
    }
    stack<pair<int,int>>st; //price,index
    int index = 0 ;
    
    int next(int price) {
        //remove all prices smaller than or equal to current price
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        //prev greater element
        int span;

        if(st.empty()){
            span = index + 1;
        }
        else{
            span = index - st.top().second;
        }
        //store {price,index}
        st.push({price,index});
        index++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */