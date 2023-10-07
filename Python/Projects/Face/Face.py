# Importing cv2 Library -->
from email.mime import image
import cv2

# Loading Pre-Trained Face Detection Data -->
trained_face_data = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Image To Detect Face -->
image = cv2.imread('Tony.jpg')

# Convert Image To Grayscale -->
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

# To Detect Face -->
face_coordinates = trained_face_data.detectMultiScale(gray_image)

# To Print Face Coordinates -->
# print(face_coordinates)

# To Assign Coordinates In Variables -->
# (x, y, w, h) = face_coordinates[0]

'''
To Detect Multiple Faces Manually -->
(x, y, w, h) = face_coordinates[1]
cv2.rectangle(image, (x, y), (x+w, y+h), (0, 0, 0), 5)
(x, y, w, h) = face_coordinates[2]
cv2.rectangle(image, (x, y), (x+w, y+h), (0, 0, 0), 5)
(x, y, w, h) = face_coordinates[....]
cv2.rectangle(image, (x, y), (x+w, y+h), (0, 0, 0), 5)
'''

# To Draw Rectangle Around The Multiple Faces By For Loop-->
for (x, y, w, h) in face_coordinates :
    cv2.rectangle(image, (x, y), (x+w, y+h), (0, 0, 0), 5)

# To Show Image -->
cv2.imshow('Face Detector', image)

# To Pause The Execution -->
cv2.waitKey()