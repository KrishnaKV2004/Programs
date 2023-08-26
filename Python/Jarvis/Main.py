# Setting Voice Engine -->
import pyttsx3
import comtypes.client
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voices', voices[0].id)
engine.setProperty('rate', 170)

def Speak(audio):
    print("     ")
    print(f": {audio}")
    print("     ")
    engine.say(audio)
    engine.runAndWait()

Speak("Hello Tokyo, How Are You")