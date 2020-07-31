# MoonCake Price

# 基本思想就是找最贵的买
def maxmize_price(N, D, storages, full_prices):

	# 单价
	price_nums = [full_prices[i] / storages[i] for i in range(N)]
	price_to_idx = {price_nums[idx]:idx for idx in range(N)}
	prices = sorted(price_nums, reverse = True) #排序后的价格列表(降序)

	idx = 0        # 按单价排列的顺序索引
	price_idx = 0  # 输入的月饼价格索引(原始索引)
	demand_cnt = 0
	remain_demand = D
	max_price = 0
	while remain_demand > 0:
		# 用排序后的价格去查找索引，然后查看对应的吨数
		price_idx = price_to_idx.get(prices[idx])
		# 找目前最贵的月饼来买
		
		# 如果此类月饼存量小于或等于现存需求，全买了（可能不够）
		if storages[price_idx] <= remain_demand:
			max_price += full_prices[price_idx]   # 增加总售价
			remain_demand -= storages[price_idx]
		# 如果此类月饼存量大于现存需求
		else:
			max_price += remain_demand * prices[idx]
			remain_demand = 0  # 不需要寻找下一类月饼
		idx += 1
		if idx >= N:
			break # 满足不了需求D
		 
	print("%.2f" % (max_price))	 
	
	
input_nums = input() # category: N,  demand: D
N, D = [int(num) for num in input_nums.split(' ')] 

storages = input()
full_prices = input()

# 正数啊 不是正整数不能用int，要用float
storages = [float(store) for store in storages.split(' ')] 
full_prices = [float(price) for price in full_prices.split(' ')]
maxmize_price(N, D, storages, full_prices)
# # Test
# for i in range(1, 100):
	# N, D = i, i*i
	# storages = [i for i in range(1, N+1)]
	# full_prices = [i for i in range(1, N+1)][::-1]	
	# maxmize_price(N, D, storages, full_prices)
