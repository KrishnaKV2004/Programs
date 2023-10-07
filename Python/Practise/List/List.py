alpha = ["a", "b", "c", "d"]
beta = [1, 2, 3, 4, 5]
gamma = ["Apple", "Mango", "Litchi"]

print()
print(alpha)
print(beta)
print(gamma)

print()
print(len(alpha))
print(len(beta))
print(len(gamma))

print()
print(alpha[0])
print(beta[-5:-1])
print(gamma[::-1])

print()
gamma[0:2] = ["Pineapple", "Kiwi"]
print(gamma)

print()
beta.append(6)
print(beta)
alpha.insert(4,"e")
print(alpha)
beta.remove(6)
print(beta)
alpha.pop(3)    #  If No Index It Removes Last Index
print(alpha)

print()
list1 = [10, 25, 30, 45, 50]
list2 = [x+10 for x in list1 if x%2==0]
print(list1)
print(list2)