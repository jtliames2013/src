(2) stock leetcode原题。follow up：stock II leetcode原题。another follow up: what if there are some transition fee for each transition?

public:
    int maxProfit(vector<int>& prices, int charge) {
        int profit=0;
        int n=prices.size();
        int bottom, top, prevbottom=-1;

        for (int i=0; i<n; i++) {
            while (i<n-1 && prices[i]>=prices[i+1]) i++;
            bottom=prices[i];
            while (i<n-1 && prices[i]<=prices[i+1]) i++;
            top=prices[i];
            if (prevbottom!=-1) bottom=min(bottom, prevbottom);
            if (top-bottom>charge) {
            	profit+=top-bottom-charge;
            	prevbottom=-1;
            } else {
            	prevbottom=bottom;
            }
        }
        return profit;
    }
};

