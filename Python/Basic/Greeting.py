Letter = '''Hi
<|NAME|>
You are selected !
Have a nice day !
Date: <|DATE|>'''
name = input("Enter Your Name")
date = input("Enter Date")
Letter = Letter.replace("<|NAME|>", name)
Letter = Letter.replace("<|DATE|>", date)
print(Letter) 