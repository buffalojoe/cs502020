from sys import argv
from sys import exit
from cs50 import SQL

db = SQL("sqlite:///students.db")

if len(argv) != 2:
    print("Usage: import.py file.csv")
    exit()
    
house = argv[1]

dbresult = db.execute(f"SELECT first, middle, last, birth FROM students WHERE house = '{argv[1]}' ORDER BY last, first")

for entry in dbresult:
    #print(entry)
    print(f"{entry['first']} ", end="")
    
    if entry['middle'] == 'None':
        print("", end="")
    else:
        print(f"{entry['middle']} ", end="")
        
    print(f"{entry['last']}, born {entry['birth']}")