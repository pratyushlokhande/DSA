# # Python program to reverse a linked list
# # Time Complexity : O(n)
# # Space Complexity : O(n) as 'next'
# # variable is getting created in each loop.

# # Node class


# class Node:

#     # Constructor to initialize the node object
#     def __init__(self, data):
#         self.data = data
#         self.next = None


# class LinkedList:

#     # Function to initialize head
#     def __init__(self):
#         self.head = None

#     # Function to reverse the linked list
#     def reverse(self):
#         prev = None
#         current = self.head
#         while(current is not None):
#             next = current.next
#             current.next = prev
#             prev = current
#             current = next
#         self.head = prev

#     # Function to insert a new node at the beginning
#     def push(self, new_data):
#         new_node = Node(new_data)
#         new_node.next = self.head
#         self.head = new_node
#     # naming cange kar plag na lag jay.
#     # Utility function to print the LinkedList -- ye puch lena ki liku ya nhi print ka

#     def printList(self):
#         temp = self.head
#         while(temp):
#             print(temp.data, end=" ")  # yaha error hai space hi rakh
#             temp = temp.next

#     def append(self, new_data):
#         new_node = Node(new_data)
#         new_node.next = self.head
#         self.head = new_node


# # Driver program to test above functions
# llist = LinkedList()
# llist.push(20)
# llist.push(4)
# llist.push(15)
# llist.push(85)

# # input mang le

# print("Given Linked List")
# llist.printList()
# llist.reverse()
# print("\nReversed Linked List")
# llist.printList()

# ll.push("yha push karr de")
# ye reversed pr push karega to confirm kar le
# puch ki basically insert at tail hai na?
# This code is contributed by Nikhil Kumar Singh(nickzuck_007)

# custom data structure hai that is inbuilt by python

# list = [1, 2, 3, 4]

# list.append([6, 7])
# print(list)

# print first n fibonacci  number

# recursion bhi bata dena
def get_finnocci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        print("fibonacci number is", get_finnocci(n-1) + get_finnocci(n-2))
        return get_finnocci(n-1) + get_finnocci(n-2)
# o(N)AAYGA
# YE BHI CONSTANT AAYGA

# print first n fibonacci  number in constant space commplexity


def get_finnocci_constant_space(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        a = 0
        b = 1
        for i in range(2, n+1):
            c = a + b
            a = b
            b = c
        return c


# get_finnocci_constant_space(5)
# get all fibonacci number in constant space between 0 to n


def get_finnocci_constant_space_between_0_to_n(n):
    if n == 0:
        print(0)
        return
    elif n == 1:
        print(1)
        return
    else:
        a = 0
        b = 1
        print(a, b)  # 1 is printed first base case (0 and 1)
        # because base kia hai
        for i in range(2, n+1):
            c = a + b
            a = b
            b = c
            print(c)

# O(c)
# get_finnocci_constant_space_between_0_to_n(5)

# IS VAID PALLINDROM


# pallindrome substring greater than k
def get_pallindrome_substring_greater_than_k(s, k):
    n = len(s)
    for i in range(n):
        for j in range(i+1, n+1):
            if is_pallindrome(s[i:j]):
                print(s[i:j])
                return
    print("No pallindrome substring greater than k")


def is_pallindrome(s):
    if s == s[::-1]:
        return True
    else:
        return False


def get_pallindrome_substring_greater_than_k(s, k):
    n = len(s)
    for i in range(n):
        for j in range(i+1, n+1):
            if is_pallindrome(s[i:j]):
                if len(s[i:j]) >= k:
                    print(s[i:j])
                    # return
    # print("No pallindrome substring greater than k")


get_pallindrome_substring_greater_than_k("abbacddccaaba", 3)
