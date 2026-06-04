# Network Monitor

Lightweight firewall/monitor scaffolding in Python for inspecting traffic and detecting possible DoS behavior.

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

```bash
python firewall/dos_firewall.py
```

## Notes

- Capturing packets may require elevated privileges on some systems.
