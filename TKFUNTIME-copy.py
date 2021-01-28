import tkinter
import sqlite3
import random #In this script, I will mainly be using two libraries - Tkinter and SQLite3. Tkinter is simply for the buttons, while SQLite3 is for the database.

root=tkinter.Tk()
root.geometry("530x320")
root.title("")
root.configure(bg="white") #setting up our tkinter window

conn=sqlite3.connect("dhruv.db") #Here, we get our database, which i called dhruv.db
cursor=conn.cursor()

def RFD():
       cursor.execute("CREATE TABLE IF NOT EXISTS Leaderboard (Name STRING,Score STRING)")
def DE():
       global namex
       global qqq
       cursor.execute("INSERT INTO Leaderboard VALUES ('"+namex+"','"+str(20000-score)+"')") #RFD() and DE() are two simple functions for creating our leaderboard and inserting values into it.  Basically, I'm executing these commands in my database as if they were being typed in the Terminal itself

RFD()

r=random.randint(1,100)
print(r)

print("What is your name?")
namex=str(input())

buttons=[]
squares=[1,4,9,16,25,36,49,64,81,100]
x=0
y=0
z=1
current_hint = 2
cbchint = 0
score=-1
last_clicked = 1
multiple = 2 

class tb: #I am creating a class tb so I can make every button an object.  This is the main reason I chose to show fof this script, as I knew this was an important topic that was covered in CSE.
       def __init__(self,rows,columns,v):
              self.rows=rows
              self.columns=columns
              self.v=v #This was the initialization function I used to fetch which row, column, and number it was.  I placed the buttons in a grid system, so I placed them at a certain row and at a certain column.
       def buttoncontrol(self):
              global r
              global score
              global last_clicked
              
              last_clicked = self.v
              
              score+=1
              if r!=self.v:
                     self.button.destroy()

              #This is just for whenever a button is clicked
                     
              else:
                     score=score*100
                     print("You earned",20000-score,"points!")
                     DE()
                     cursor.close()
                     conn.commit()
                     conn.close()
                     exit()
                     
       def draw(self):
              self.button=tkinter.Button(root,text=self.v,command=self.buttoncontrol)
              self.button.grid(row=self.rows,column=self.columns)
       def Hint(self):
              global r
              global score
              global current_hint
              global squares
              global last_clicked
              global multiple
              global cbchint
              
              score+=1
              if r>last_clicked and current_hint==1: 
                     print(last_clicked," is less than the hidden number!")
                     
              elif r<last_clicked and current_hint==1:
                     print(last_clicked," is greater than the hidden number!")
                     
              elif current_hint==2:
                     while multiple < r:
                            while r%multiple != 0:
                                   multiple += 1
                                   
                            if multiple < r:
                                   print("It is a multiple of" , multiple)
                            break
                     if multiple >= r:
                            print("It is prime!")
                            
              elif r in squares and current_hint==3:
                     print("It is a perfect square!")
                     
              elif current_hint == 3:
                     print("It is not a perfect square!")

              cbchint = current_hint
              while current_hint == cbchint:
                     current_hint = random.randint(1,3)
                     
       def HintCreate(self):
              self.but=tkinter.Button(root,text="HINT!",command=self.Hint)
              self.but.grid(row=10,column=0)
              
for n in range(1,101,1):
       obj=tb(x,y,z)
       buttons.append(obj)
       x+=1
       z+=1
       if x>=10:
              y+=1
              x=0
obj.HintCreate()
for n in buttons:
       n.draw()

root.mainloop()

