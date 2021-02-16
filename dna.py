from sys import argv, exit  # These two libraries are for reading the csv file and getting command line arguments and exiting
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")  # Here, we just make sure the correct number of arguments are given
    exit(1)

file = open(argv[1], "r")  # Here, we open up both the csv file with the dna database and the text file with a dna string.
text = open(argv[2], "r")
reader = csv.reader(file)  # We use the csv library to read the file we opened into a sort of list of lists.

txtreader = text.read()  # This is to convert our text file into a string, and store it into txtreader

# search is a function that checks for the longest consecutive repetitions of a word in our txtreader string, with the parameter being the word to search for.


def search(searchword):
    replist = []  # replist is a list I will be using to append the number of repetitions at each character.  Basically, I plan on checking each character, and starting from that character onwards, how many consecutive repetitions are there?
    count = 0  # This is the counter for repetitions

    for i in range(0, len(txtreader), 1):  # For every character in the string
        # x and j are used to reference the first and last character of a substring I reference to check if it is equal to the searchword
        x = i + len(searchword)
        j = i
        while True:
            # print(txtreader[j:x],searchword)
            # Basically, I check if the substring of txtreader with txtreader[x] as its first char and txtreader[j] as its last is equal to searchword
            if txtreader[j:x] == searchword:
                count += 1  # If these two are equal, then we raise the count by 1, as we found the first of what we hope is our longest repetition
                # Next we slide this substring over by the length of searchword, so we can do this process again with the substring right next to the previous one
                x += len(searchword)
                j += len(searchword)
            else:
                # If it isn't equal, we finished the repetition. We can append count to replist and keep moving.
                replist.append(count)
                count = 0  # We now reset count.
                break

    # Now, we need to find the biggest number in replist, because that is the biggest number of repetitions.  First, let's sort it into descending order.
    replist.sort(reverse=True)

    return replist[0]  # now that it's sorted, the highest is the first!


num = 0

for row in reader:  # Every element in reader is a list, which contains data for one row
    if argv[1] == "databases/large.csv":  # We have to databases, one large and the other small, with different columns for each
        if row[1] == str(search("AGATC")) and row[2] == str(search("TTTTTTCT")) and row[3] == str(search("AATG")) and row[4] == str(search("TCTAG")) and row[5] == str(search("GATA")) and row[6] == str(search("TATC")) and row[7] == str(search("GAAA")) and row[8] == str(search("TCTG")):
            # We do an if statement to check if everything matches up. If not, then the person we scanned is not the person with the dna.
            print(row[0])
            num += 1

    else:
        if row[1] == str(search("AGATC")) and row[2] == str(search("AATG")) and row[3] == str(search("TATC")):
            print(row[0])
            num += 1

if num == 0:
    print("No match")  # As you can see, we put a counter in the for loop called num.  If nothing was found, num would never be changed.