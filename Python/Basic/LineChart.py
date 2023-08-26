import matplotlib.pyplot as plt

n=[8,10,20,15]
week =[1,2,3,4]
price =[40,60,100,50]

plt.plot(week,price,'g',marker='o',ms=5,mec='r')
plt.plot(week,n,'b',lw=2,ls='-.')
plt.ylabel("Price Of Item")
plt.xlabel("Week")
plt.title("Chart")
plt.grid(True)
plt.show()
