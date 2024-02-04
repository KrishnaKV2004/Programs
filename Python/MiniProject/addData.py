import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

cred = credentials.Certificate("serviceAccountKey.json")
firebase_admin.initialize_app(cred,{'databaseURL':"https://face-recognition-95478-default-rtdb.firebaseio.com/"})

ref=db.reference('Students')

data = {
    "22021156":
        {
            # Key:value
            "Name":"Ayush Chamoli",
            "Major":"AI",
            "Starting_year":2022,
            "Total_attendance":100,
            "Standing":"A",
            "Year":2,
            "last_attendance_time":"2023-11-11 00:54:34"
        },
        "852741":
        {
            "Name":"Bill Gates",
            "Major":"Cloud Computing",
            "Starting_year":2020,
            "Total_attendance":100,
            "Standing":"C",
            "Year":3,
            "last_attendance_time":"2023-11-11 00:54:34"
        },
        "963852":
        {
            "Name":"Elon Musk",
            "Major":"Data Analytics",
            "Starting_year":2021,
            "Total_attendance":100,
            "Standing":"B",
            "Year":3,
            "last_attendance_time":"2023-11-11 00:54:34"
        }
}

for key,value in data.items():
    # child to send data to a specific directory
    ref.child(key).set(value)