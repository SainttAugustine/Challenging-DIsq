#! /usr/bin/bash
dtStamp=$(date "+%Y-%m-%d_%H:%M")
python3 /home/kenneth/Desktop/cron_assg/entryScripts/t1.py
echo "${dtStamp}--DATA ENTRY SUCCESSFUL--"
