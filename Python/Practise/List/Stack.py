stack = []

def push(item):
    stack.append(item)
    print(f"Pushed {item} onto the stack.")

def pop():
    if not stack:
        print("Stack is empty. Cannot pop.")
    else:
        item = stack.pop()
        print(f"Popped {item} from the stack.")

def display():
    if not stack:
        print("Stack is empty.")
    else:
        print("Stack contents:")
        for item in reversed(stack):
            print(item)

while True:
    print("\nStack Menu:")
    print("1. Push")
    print("2. Pop")
    print("3. Display")
    print("4. Quit")

    choice = input("Enter your choice (1/2/3/4): ")

    if choice == '1':
        item = input("Enter the item to push: ")
        push(item)
    elif choice == '2':
        pop()
    elif choice == '3':
        display()
    elif choice == '4':
        break
    else:
        print("Invalid choice. Please select a valid option (1/2/3/4).")

print("Stack program terminated.")