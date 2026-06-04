# Network Monitor

Lightweight firewall/monitor scaffolding in Python for inspecting traffic and detecting possible DoS behavior.

## How It Works

The firewall extracts source IPs from packets and calculates the receive rate. If the rate exceeds a hardcoded threshold, the IP is blocked.

## Requirements

- Python 3.12+
- scapy

## Setup

Create and activate a virtual environment, then install dependencies:

```bash
python -m venv env
source env/bin/activate
pip install scapy
```

## Run

Run the firewall with root privileges:

```bash
sudo python3 firewall/dos_firewall.py
```

## Testing

You can generate test traffic with an ESP32. The sample sketch is in the testing folder: [testing/esp32_traffic_creator.c](testing/esp32_traffic_creator.c)

```


