int maxProfit(int* prices, int pricesSize){

    int own = -1, profit = 0, i = 0;
    for (i = 0; i < pricesSize - 1; i++)
    {
        if (prices[i] <= prices[i + 1])
        {
            if (own == -1) //buy
                own = prices[i];
        
            //else hold
        }
        else
        {
            if (own != -1) // sell
            {
                profit += prices[i] - own;
                own = -1;
            }
            //else pass
        }
    }

    if (i == pricesSize - 1 && own != -1) profit += prices[pricesSize - 1] - own;

    return profit;
}