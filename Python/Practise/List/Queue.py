queue = []

def enqueue(item):
    queue.append(item)
    print(f"Enqueued {item} into the queue.")

def dequeue():
    if not queue:
        print("Queue is empty. Cannot dequeue.")
    else:
        item = queue.pop(0)
        print(f"Dequeued {item} from the queue.")

def display():
    if not queue:
        print("Queue is empty.")
    else:
        print("Queue contents:")
        for item in queue:
            print(item)

while True:
    print("\nQueue Menu:")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Display")
    print("4. Quit")

    choice = input("Enter your choice (1/2/3/4): ")

    if choice == '1':
        item = input("Enter the item to enqueue: ")
        enqueue(item)
    elif choice == '2':
        dequeue()
    elif choice == '3':
        display()
    elif choice == '4':
        break
    else:
        print("Invalid choice. Please select a valid option (1/2/3/4).")

print("Queue program terminated.")