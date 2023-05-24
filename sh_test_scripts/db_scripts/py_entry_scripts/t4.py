import csv
import MySQLdb

mydb = MySQLdb.connect(host="localhost", user="kennetht", password="@12345", database="assg_cron")

filepath = "/home/kenneth/Desktop/cron_assg/entryScripts/djs.csv"

with open(filepath) as csv_file:
	csvfile = csv.reader(csv_file, delimiter=",")
	all_values=[]
	for row in csvfile:
		value = (row[0], row[1])
		all_values.append(value)

query = "insert into `t4_djs` (`name`, `country`) values (%s, %s)"
mycursor = mydb.cursor()
mycursor.executemany(query, all_values)
mydb.commit()
