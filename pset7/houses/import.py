from sys import argv
from sys import exit
from cs50 import SQL
import csv

db = SQL("sqlite:///students.db")

# Print an error and exit if the incorrect number of command-line arguments is given
if len(argv) != 2:
    print("Usage: import.py file.csv")
    exit()

# Load the CSV provided as an argument into memory
with open(argv[1]) as data:
    sData = csv.reader(data, delimiter=',')
    headers = next(sData)     # Trim off the header row
    headers.pop(0)

    for row in sData:
        name = row[0]
        sname = name.split()

        if len(sname) != 3:
            sname.insert(1, None)

        row[0:1] = sname

        db.execute(f"INSERT INTO students (first, middle, last, house, birth) VALUES \
        ('{row[0]}', '{row[1]}', '{row[2]}', '{row[3]}', '{row[4]}')")