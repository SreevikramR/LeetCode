class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxProfit = 0
        for i, price in enumerate(prices):
            if price < minPrice:
                minPrice = price
            newProfit = price - minPrice
            if newProfit > maxProfit:
                maxProfit = newProfit
        return maxProfit
