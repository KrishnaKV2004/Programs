import os
import pickle
import numpy as np
import cv2 as cv
import face_recognition
import cvzone
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from firebase_admin import storage
from datetime import datetime

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred, {
    'databaseURL': "https://face-recognition-95478-default-rtdb.firebaseio.com/",
    'storageBucket': "face-recognition-95478.appspot.com"
})

bucket = storage.bucket()

cap = cv.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

imgBackground = cv.imread('Resources/background.png')

# Importing the mode images into a list
folderModePath = 'Resources/Modes'
modePathList = os.listdir(folderModePath)
imgModeList = []
for path in modePathList:
    imgModeList.append(cv.imread(os.path.join(folderModePath, path)))
# print(len(imgModeList))

# Load the encoding file
print("Loading Encode File ...")
file = open('EncodeFile.p', 'rb')
encodeListKnownWithIds = pickle.load(file)
file.close()
encodeListKnown, studentIds = encodeListKnownWithIds
# print(studentIds)
print("Encode File Loaded")

modeType = 0
counter = 0
id = -1
imgStudent = []

while True:
    success, img = cap.read()

    imgS = cv.resize(img, (0, 0), None, 0.25, 0.25)
    imgS = cv.cvtColor(imgS, cv.COLOR_BGR2RGB)

    resized_img=cv.resize(img,(640,480))

    faceCurFrame = face_recognition.face_locations(imgS)
    encodeCurFrame = face_recognition.face_encodings(imgS, faceCurFrame)

    imgBackground[162:162 + 480, 55:55 + 640] = resized_img
    imgBackground[44:44 + 633, 808:808 + 414] = imgModeList[modeType]

    if faceCurFrame:
        for encodeFace, faceLoc in zip(encodeCurFrame, faceCurFrame):
            matches = face_recognition.compare_faces(encodeListKnown, encodeFace)
            faceDis = face_recognition.face_distance(encodeListKnown, encodeFace)
            # print("matches", matches)
            # print("faceDis", faceDis)

            matchIndex = np.argmin(faceDis)
            # print("Match Index", matchIndex)

            if matches[matchIndex]:
                # print("Known Face Detected")
                # print(studentIds[matchIndex])
                y1, x2, y2, x1 = faceLoc
                y1, x2, y2, x1 = y1 * 4, x2 * 4, y2 * 4, x1 * 4
                bbox = 100 + x1, 162 + y1, 55+x2, 55+y2
                imgBackground = cvzone.cornerRect(imgBackground, bbox, rt=0)
                id = studentIds[matchIndex]
                if counter == 0:
                    cvzone.putTextRect(imgBackground, "Loading", (275, 400))
                    cv.imshow("Face Attendance", imgBackground)
                    cv.waitKey(1)
                    counter = 1
                    modeType = 1

        if counter != 0:

            if counter == 1:
                # Get the Data
                studentInfo = db.reference(f'Students/{id}').get()
                print(studentInfo)
                # Get the Image from the storage
                blob = bucket.get_blob(f'Images/{id}.png')
                array = np.frombuffer(blob.download_as_string(), np.uint8)
                imgStudent = cv.imdecode(array, cv.COLOR_BGRA2BGR)
                # Update data of attendance
                datetimeObject = datetime.strptime(studentInfo['last_attendance_time'],
                                                   "%Y-%m-%d %H:%M:%S")
                secondsElapsed = (datetime.now() - datetimeObject).total_seconds()
                print(secondsElapsed)
                if secondsElapsed > 400:
                    ref = db.reference(f'Students/{id}')
                    studentInfo['Total_attendance'] += 1
                    ref.child('Total_attendance').set(studentInfo['Total_attendance'])
                    ref.child('last_attendance_time').set(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
                else:
                    modeType = 3
                    counter = 0
                    imgBackground[44:44 + 633, 808:808 + 414] = imgModeList[modeType]

            if modeType != 3:

                if 10 < counter < 20:
                    modeType = 2

                imgBackground[44:44 + 633, 808:808 + 414] = imgModeList[modeType]

                if counter <= 10:
                    cv.putText(imgBackground, str(studentInfo['Total_attendance']), (861, 125),
                                cv.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1)
                    cv.putText(imgBackground, str(studentInfo['Major']), (1006, 550),
                                cv.FONT_HERSHEY_COMPLEX, 0.5, (255, 255, 255), 1)
                    cv.putText(imgBackground, str(id), (1006, 493),
                                cv.FONT_HERSHEY_COMPLEX, 0.5, (255, 255, 255), 1)
                    cv.putText(imgBackground, str(studentInfo['Standing']), (910, 625),
                                cv.FONT_HERSHEY_COMPLEX, 0.6, (100, 100, 100), 1)
                    cv.putText(imgBackground, str(studentInfo['Year']), (1025, 625),
                                cv.FONT_HERSHEY_COMPLEX, 0.6, (100, 100, 100), 1)
                    cv.putText(imgBackground, str(studentInfo['Starting_year']), (1125, 625),
                                cv.FONT_HERSHEY_COMPLEX, 0.6, (100, 100, 100), 1)

                    (w, h), _ = cv.getTextSize(studentInfo['Name'], cv.FONT_HERSHEY_COMPLEX, 1, 1)
                    offset = (414 - w) // 2
                    cv.putText(imgBackground, str(studentInfo['Name']), (808 + offset, 445),
                                cv.FONT_HERSHEY_COMPLEX, 1, (50, 50, 50), 1)

                    imgBackground[175:175 + 216, 909:909 + 216] = imgStudent

                counter += 1

                if counter >= 20:
                    counter = 0
                    modeType = 0
                    studentInfo = []
                    imgStudent = []
                    imgBackground[44:44 + 633, 808:808 + 414] = imgModeList[modeType]
    else:
        modeType = 0
        counter = 0
    # cv.imshow("Webcam", img)
    cv.imshow("Face Attendance", imgBackground)

    if cv.waitKey(1) & 0xFF == ord('q'):
          break