def knapSack(totalW, wt, val, n):
    # initialize doubly nested
    KS = [[0 for x in range(totalW + 1)] for x in range(n + 1)]
    # build table KS[][] in bottom-up manner
    for i in range(n + 1):
        for w in range(totalW + 1):
            if i == 0 or w == 0:
                #initialization
                KS[i][w] = 0 
            elif wt[i - 1] <= w:
                #min, max format
                KS[i][w] = max(val[i - 1] + KS[i - 1][w - wt[i - 1]], KS[i - 1][w])
            else:
                KS[i][w] = KS[i - 1][w]
    return KS[n][totalW]


indexes = []


def getIndexes(target, start, path, nums):
      # needed to add tolerance due to floating point error
      tolerance = 1e-3
      # within proper tolerance
      if abs(target) < tolerance:  
          indexes.append(path[:])
          return
      for i in range(start, len(nums)):
          if abs(nums[i] - target) < tolerance:
              # add to path
              getIndexes(0, i + 1, path + [nums[i]], nums)
          elif nums[i] > target:
              # go to next index
              continue
          else:
              # successive
              getIndexes(target - nums[i], i + 1, path + [nums[i]], nums)



def main():
    # starting arguments
    price = [90, 1200, 150, 800, 40, 380, 160, 290, 25, 90]
    return_ratio = [0.1, 0.16, 0.12, 0.15, 0.08, 0.25, 0.18, 0.09, 0.11, 0.06]
    profit = []
    # calculate profit for each stock
    for i in range(len(price)):
        profit.append((price[i] * return_ratio[i]))
      
    capacity = int(input("Enter the budget: "))

    companies = ["APP", "AMZ", "FBB", "GOLG", "IBN", "MASO", "MDN", "TSLA", "VO", "WLM"]
    length = len(companies)

    # get max profit and find the indexes used for given profit
    max_profit = knapSack(capacity, price, profit, length)
    getIndexes(max_profit, 0, [], profit)

    company = []
    prices = []
    # formatting issue
    flattened_list = [item for sublist in indexes for item in sublist]

    # find the matching index where flattened list is equal to the profit
    for j in range(len(flattened_list)):
        for k in range(len(profit)):
            if profit[k] == flattened_list[j]:
                company.append(companies[k])
                prices.append(price[k])

    # output
    print("Portfolio: ", company)
    print("Expected maximum return: {:.2f}".format(round(max_profit, 2)))
    print("Total amount invested: ", sum(prices))


if __name__ == "__main__": # run
  main()
