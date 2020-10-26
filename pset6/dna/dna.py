from sys import argv
import re
import csv

# Require two command line arguments.
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit()

# Open the first CLI provided by user, the CSV, and read
with open(argv[1]) as data:
     readData = csv.reader(data, delimiter=',')
     field_names = next(readData)   # Extract column headers into a list
     field_names.pop(0)             # Remove the first column header (names)
     numStrs = len(field_names)     # Determine number of STRs to evaluate

# Open the second CLI provided by the user for reading
with open(argv[2], "r") as seq:
    dna = seq.read()

# Initialize a list and include the lengths of each STR included in the CSV file
includedLens = []
for i in range(len(field_names)):
    includedLens.append(len(field_names[i]))

# Initialize a list to hold the max counts of each STR found in sequence in the DNA
strCounts = []

# Iterage through the range of STRs included in the DNA sequence
for i in range(len(field_names)):
   
    # Utilize regex to find groupings of STR[i] in the DNA
    groups = re.findall(f'(?:{field_names[i]})+', dna)
    
    # If an STR is encountered that is not in this DNA sequence, input as 0 to the
    #   strCounts list
    if groups == []:
        strCounts.append(len(""))
        continue
   
    # Find the largest sequence of repeating STRs of type [i] in the DNA
    largest = (max(groups, key=len))
    
    # Divide the largest sequence length by the length of the STR itself to find
    #   the largest number of repeating units in the DNA -- store in the strCounts list
    #   as a string so that it can be compared to the rows in the CSV
    strCounts.append(str((len(largest) // includedLens[i])))

with open(argv[1]) as data:
    readData = csv.reader(data, delimiter=',')
    next(readData)      # Skip the first row
    for row in readData:
        
        # If the row of STR values for a given person in the database equals the STR lengths
        #   calculated above, print their name on screen. Once a match is found, exit
        if row[1:] == strCounts:
            print(" ".join(row[0:1]))
            exit()
        else:
            continue
        
print("No match")       # If no matches were found, let the user know.