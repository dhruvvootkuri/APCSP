import cv2
import numpy as np
a=0

def nothing(x):
       pass

cap=cv2.VideoCapture(0)
frame=cap.read()
print("We don't know where anything is.  We have one artifact here at the lab, though. Here's what it said:")
print("ఇక్కడ మీ మొదటి క్లూ ఉంది..")
print("మీరు పని వరకు ఉంటే.")
print("నేను నా బూట్లు ఎక్కడ ఉంచాను.")
print("మీరు మొదటి వాస్తవాన్ని కనుగొంటారు.")
cv2.namedWindow("Trackbars")
cv2.createTrackbar("L-H","Trackbars",89,180,nothing)
cv2.createTrackbar("L-S","Trackbars",255,255,nothing)
cv2.createTrackbar("L-V","Trackbars",180,180,nothing)
cv2.createTrackbar("U-H","Trackbars",133,255,nothing)
cv2.createTrackbar("U-S","Trackbars",48,255,nothing)
cv2.createTrackbar("U-V","Trackbars",255,255,nothing) 
cv2.waitKey(2000)
while True:
       a=0
       _,frame=cap.read()
       hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
       l_h=cv2.getTrackbarPos("L-H","Trackbars")
       l_s=cv2.getTrackbarPos("L-s","Trackbars")
       l_v=cv2.getTrackbarPos("L-V","Trackbars")
       u_h=cv2.getTrackbarPos("U-H","Trackbars")
       u_s=cv2.getTrackbarPos("U-S","Trackbars")
       u_v=cv2.getTrackbarPos("U-V","Trackbars")

       lower_red=np.array([l_h,l_s,l_v])
       upper_red=np.array([u_h,u_s,u_v])
       mask=cv2.inRange(hsv,lower_red,upper_red)
       kernel=np.ones((5,5),np.uint8)
       mask = cv2.erode(mask,kernel)

       contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
       
       for cnt in contours:
              cv2.drawContours(frame,[cnt],0,(0,0,0),5)
              approx=cv2.approxPolyDP(cnt,0.01*cv2.arcLength(cnt,True),True)
              area=cv2.contourArea(approx)
              cv2.drawContours(frame,[approx],0 ,(0,0,0),5)
              if len(approx)==4 and area>1000 and a==0:
                     print("")
                     print("We've analyzed your artifact.  Good work.  It's a puzzle! Here's what the artifact said:")
                     print("మీ మొదటి అన్వేషణలో అభినందనలు.")
                     print("ఇప్పుడు లోపల ఏమి ఉంది అని మీరు చూస్తారు.")
                     print("మీరు ఇప్పుడు చల్లటి భూమిని దాటాలి.")
                     print("మరియు నేను చాలా ఇష్టపడని ఆహారాన్ని కనుగొనండి.")
                     a+=1
                     break
              if a==1:
                     break
       if a==1:
              break
       cv2.imshow("Computer Lab",frame)
       key=cv2.waitKey(1)
cv2.waitKey(2000)
while True:
       a=0
       _,frame=cap.read()
       hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
       l_h=cv2.getTrackbarPos("L-H","Trackbars")
       l_s=cv2.getTrackbarPos("L-s","Trackbars")
       l_v=cv2.getTrackbarPos("L-V","Trackbars")
       u_h=cv2.getTrackbarPos("U-H","Trackbars")
       u_s=cv2.getTrackbarPos("U-S","Trackbars")
       u_v=cv2.getTrackbarPos("U-V","Trackbars")

       lower_red=np.array([l_h,l_s,l_v])
       upper_red=np.array([u_h,u_s,u_v])
       mask=cv2.inRange(hsv,lower_red,upper_red)
       kernel=np.ones((5,5),np.uint8)
       mask = cv2.erode(mask,kernel)

       contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
       
       for cnt in contours:
              cv2.drawContours(frame,[cnt],0,(0,0,0),5)
              approx=cv2.approxPolyDP(cnt,0.01*cv2.arcLength(cnt,True),True)
              area=cv2.contourArea(approx)
              cv2.drawContours(frame,[approx],0 ,(0,0,0),5)
              if len(approx)==12 and area>1000 and a==0:
                     print("")
                     print("You're on a roll! Back here, we've encrypted their language.These guys are playing with us:")
                     print("మీరు రెండవ క్లూ కనుగొన్నారు.")
                     print("మీరు కనుగొనటానికి దగ్గరగా ఉన్నారు.")
                     print("త్వరలోనే మీరు సత్యం పొందుతారు.")
                     print("మీరు సంగీతానికి లోపల ఉన్నదాని కోసం చూస్తున్నప్పుడు.")
                     a+=1
                     break
              if a==1:
                     break
       if a==1:
              break
       cv2.imshow("Computer Lab",frame)
       key=cv2.waitKey(1)
cv2.waitKey(2000)
while True:
       a=0
       _,frame=cap.read()
       hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
       l_h=cv2.getTrackbarPos("L-H","Trackbars")
       l_s=cv2.getTrackbarPos("L-s","Trackbars")
       l_v=cv2.getTrackbarPos("L-V","Trackbars")
       u_h=cv2.getTrackbarPos("U-H","Trackbars")
       u_s=cv2.getTrackbarPos("U-S","Trackbars")
       u_v=cv2.getTrackbarPos("U-V","Trackbars")

       lower_red=np.array([l_h,l_s,l_v])
       upper_red=np.array([u_h,u_s,u_v])
       mask=cv2.inRange(hsv,lower_red,upper_red)
       kernel=np.ones((5,5),np.uint8)
       mask = cv2.erode(mask,kernel)

       contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
       
       for cnt in contours:
              cv2.drawContours(frame,[cnt],0,(0,0,0),5)
              approx=cv2.approxPolyDP(cnt,0.01*cv2.arcLength(cnt,True),True)
              area=cv2.contourArea(approx)
              cv2.drawContours(frame,[approx],0 ,(0,0,0),5)
              if len(approx)==3 and area>1000 and a==0:
                     print("")
                     print("SO CLOSE. Here's the next riddle:")
                     print("మీరు నన్ను కనుగొనటానికి యోగ్యుడవు.")
                     print("నేను దాదాపు మీ అవగాహనలో ఉన్నాను.")
                     print("తరువాతి క్లూ వృద్ధి స్థానంలో కనుగొనబడుతుంది.")
                     print("దానిని వెతుకుము, మీరు చెయ్యగలరు.")
                     a+=1
                     break
              if a==1:
                     break
       if a==1:
              break
       cv2.imshow("Computer Lab",frame)
       key=cv2.waitKey(1)
cv2.waitKey(2000)
while True:
       a=0
       _,frame=cap.read()
       hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
       l_h=cv2.getTrackbarPos("L-H","Trackbars")
       l_s=cv2.getTrackbarPos("L-s","Trackbars")
       l_v=cv2.getTrackbarPos("L-V","Trackbars")
       u_h=cv2.getTrackbarPos("U-H","Trackbars")
       u_s=cv2.getTrackbarPos("U-S","Trackbars")
       u_v=cv2.getTrackbarPos("U-V","Trackbars")

       lower_red=np.array([l_h,l_s,l_v])
       upper_red=np.array([u_h,u_s,u_v])
       mask=cv2.inRange(hsv,lower_red,upper_red)
       kernel=np.ones((5,5),np.uint8)
       mask = cv2.erode(mask,kernel)

       contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
       
       for cnt in contours:
              cv2.drawContours(frame,[cnt],0,(0,0,0),5)
              approx=cv2.approxPolyDP(cnt,0.01*cv2.arcLength(cnt,True),True)
              area=cv2.contourArea(approx)
              cv2.drawContours(frame,[approx],0 ,(0,0,0),5)
              if len(approx)==6 and area>1000 and a==0:
                     print("")
                     print("It was a map!")
                     print("Scientists have located the civilization.Congrats!")
                     a+=1
                     break
              if a==1:
                     break
       if a==1:
              break
       cv2.imshow("Computer Lab",frame)
       key=cv2.waitKey(1)
cv2.waitKey(2000)
cap.release()
cv2.destroyAllWindows()

       

