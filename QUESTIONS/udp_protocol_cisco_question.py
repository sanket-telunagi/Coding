import time
def udp_network_protocol_1(requests, max_packets, rate):
    total_dropped_packets = 0
    queue = []
    requests.sort()

    for request in requests:
        current_time = request[0]
        packets_to_send = request[1]

        # Wait until the current time
        # time.sleep(current_time)

        # Remove packets from the queue if they should be delivered
        if len(queue) > 0 and queue[0] <= current_time:
            delivered_packets = min(len(queue), rate)
            queue = queue[delivered_packets:]
        else:
            delivered_packets = 0

        # Calculate the number of dropped packets
        dropped_packets = max(0, packets_to_send - delivered_packets)
        total_dropped_packets += dropped_packets

        # Add new packets to the queue
        new_packets = min(packets_to_send, max_packets - len(queue))
        queue.extend([current_time + i for i in range(new_packets)])

    return total_dropped_packets

def fun1 (requests, max_packets, rate) :
    total = 0
    requests.sort()
    # print(requests)

    
    # for 

def udp_network_protocol(requests, max_packets, rate):
    total_dropped_packets = 0
    queue = []
    # requests.sort()
    current_time = 0
    for request in requests:
        request_time = request[0]
        packets_to_send = request[1]

        # Wait until the current time reaches the request time
        if current_time < request_time:
            current_time = request_time

        # Remove packets from the queue if they should be delivered
        if len(queue) > 0 and queue[0] <= current_time:
            delivered_packets = min(len(queue), rate)
            queue = queue[delivered_packets:]
        else:
            delivered_packets = 0

        # Calculate the number of dropped packets
        dropped_packets = max(0, packets_to_send - delivered_packets)
        total_dropped_packets += dropped_packets

        # Add new packets to the queue
        new_packets = min(packets_to_send, max_packets - len(queue))
        queue.extend([current_time + i for i in range(new_packets)])

        current_time += 1  # Increment the current time by 1 second

    return total_dropped_packets


if __name__ == "__main__" :

    nums = []

    n , max_packets, rate = map(int, input().split())
    for i in range(n) :
        nums.append(list(map(int, input().split())))

    print(fun1(nums, max_packets, rate))

    