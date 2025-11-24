import string
import time 

text = 'Alan Turing enjoyed cryptography.'
temp = ' '
for ch in text:
    for i in string.printable:
        if i == ch or ch == temp:
            time.sleep ( 0.02 )
            print( temp + i )
            temp += ch
            break
        else:
            time.sleep(0.02)
            print(temp + i)
     
