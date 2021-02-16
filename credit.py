# In this code, the user inputs a number, and we must determine what type credit card it is: American Express (AMEX), Visa, MasterCard, or if it is invalid.
# This is sort of a training wheel library given to us by the course, which can be used only for getting input.

from cs50 import get_int

while True:
    credit = get_int("Number: ")  # We get the credit card number.
    if credit > 0:  # We keep prompting the user ntil they give us a valid integer over 0.
        break

credit = str(credit)  # For the code, I found it logical to turn the number into a string.
# This allows me to find how many characters are in it, and reference certain elements in our "table"

length = len(credit)  # We get the length of our number.

# Going forward, you will need to understand my logic.  First, I need to check if the card is valid before I search for its specific type.
# To check, the course explained that the method of doing this is to first multiply every other digit by 2, right to left, starting from the second to last digit.
# Next we add all the digits of all the products together (For example, if we get the product 12 for a number, we add 1 and 2).
# After that, we add to our current sum the numbers we didn't multiply by 2.

checksum =  0  # This is the sum we will be using in our test for validity.
tmplength = length - 2  # We will now be multiplying every other number by 2.  This starts at the second-to last digit.

while tmplength >= 0:
    num1 = int(credit[tmplength]) * 2  # num1 is the product for our current digit.
    num1 = str(num1)  # However, we can't add it to checksum just yet.
    # We need to convert it to a string, take all the digits in it, then add the integer form of those into checksum.
    for n in num1:
        checksum += int(n)
    tmplength -= 2  # We update tmplength to keep moving backwards in the string

tmplength = length - 1  # Now, let's rerun the same code, except now we're getting the numbers we DIDN'T multiply by 2.

while tmplength >= 0:
    num1 = int(credit[tmplength])  # This is simple enough.  I just add each number to checksum.
    checksum += num1
    tmplength -= 2

checksum = str(checksum)  # We now convert checksum to a string to find its length.
sumlen = len(checksum)

if checksum[sumlen - 1] == "0":  # I f the last digit of checksum is 0, it is valid.  Now we check every card number.
    # The if conditions are pretty self explanatory.  Basically, they all have a certain number of digits, and start with the same numbers.
    if length == 15 and credit[0] == "3" and (credit[1] == "4" or credit[1] == "7"):
        print("AMEX")

    elif length == 16 and credit[0] == "5" and int(credit[1]) >= 1 and int(credit[1]) <= 5:
        print("MASTERCARD")

    elif (length == 13 or length == 16) and credit[0] == "4":
        print("VISA")

else:
    print("INVALID")

