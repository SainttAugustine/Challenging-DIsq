#! /usr/bin/bash

set -e
set -o pipefail

dtStamp=$(date "+%Y-%m-%d_%H:%M")
dbUName="kennetht"
dbPass="12345"
dbName="assg_cron"
dbTable="t4_djs"

/usr/bin/mysqldump -u "${dbUName}" -p"${dbPass}" "${dbName}" "${dbTable}" | gzip > "/home/kenneth/Desktop/cron_assg/backup/$(date "+%Y-%m-%d_%H:%M")_t4_djs.sql.gzip"
echo "${dtStamp}--BACKUP SUCCEFULLY EXECUTED--"
