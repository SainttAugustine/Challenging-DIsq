#! /usr/bin/bash

set -e
set -o pipefail

dtStamp=$(date "+%Y-%m-%d_%H:%M")
dbUName="kennetht"
dbPass="12345"
dbName="assg_cron"
dbTable="t3_random"

/usr/bin/mysqldump -u "${dbUName}" -p"${dbPass}" "${dbName}" "${dbTable}" | gzip > "/home/kenneth/Desktop/cron_assg/backup/$(date "+%Y-%m-%d_%H:%M")_t3_random.sql.gzip"
echo "${dtStamp}--BACKUP SUCCEFULLY EXECUTED--"
