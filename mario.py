# This is just a simple code to make two pyramids based on the user's input.
# The height they give us must be between 1 and 8, inclusive.

while True:

    height = input("Height: ")
    # I know this is a bit wrong for larger code, to check if height was in a list, ut I felt it was fastest.
    # If I made height as an int(input()), it would give an error if a user typed soemthing other than an integer.
    # So I checked if the "string" was really an integer that met the requrements
    if height in ["1", "2", "3", "4", "5", "6", "7", "8"]:
        height = int(height)
        break

for i in range(1, height+1, 1):  # For every line...
    for b in range(height, i, -1):
        print(" ", end="")

    for a in range(i):
        print("#", end="")

    print("  ", end="")

    for c in range(i):
        print("#", end="")

    print("")

