input_text = input()
root, N, k = input_text.split(" ")
N, k = int(N), int(k)

nodes_list = {}
for i in range(N):
    item = input()
    cur_addr, value, next_addr = item.split(" ")
    value = int(value)
    if cur_addr not in nodes_list:
        nodes_list[cur_addr] = [value, next_addr]

# value: (cur, next)
node_links = {nodes_list[key][0]:[key, nodes_list[key][1]] for key in nodes_list.keys()}        

nodes = []
address = root
for i in range(N):
    node_value = nodes_list[address][0]
    nodes.append(node_value)
    address = nodes_list[address][1]
	
	
print(nodes)