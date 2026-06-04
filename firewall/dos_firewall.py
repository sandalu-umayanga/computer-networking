import os
import sys
import time
from scapy.all import sniff, IP
from collections import defaultdict

Threshold = 2  # Max packets per second from a single IP
print("Starting DoS Firewall...")
print(f"Threshold set to {Threshold} packets/second")

def packet_handler(packet):

    # print(packet[IP].src, "->", packet[IP].dst)

    src_ip = packet[IP].src
    packet_counts[src_ip] += 1

    current_time = time.time()
    time_diff = current_time - start_time[0]
    if time_diff >= 1:
        for ip, count in packet_counts.items():
            packet_rate = count / time_diff

            if packet_rate > Threshold and ip not in blocked_ips:
                print(f"Blocking IP: {ip} - {packet_rate:.2f} packets/second")
                blocked_ips.add(ip)
                
                # Here you would add code to block the IP using firewall rules
                # os.system(f"iptables -A INPUT -s {ip} -j DROP")
        packet_counts.clear()
        start_time[0] = current_time



if __name__ == "__main__":
    if os.geteuid() != 0:
        print("Please run as root")
        sys.exit(1)
    
    packet_counts = defaultdict(int)
    start_time = [time.time()]
    blocked_ips = set()

    print("Monitoring network traffic...")
    sniff(filter="ip", prn=packet_handler)