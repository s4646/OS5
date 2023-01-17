**Don't forget to compile the code using `make` command**

**Usage:**  
***Server:***
```ruby
ubuntu@ubuntu-ASUS-TUF:~/Documents/OS5$ ./main 1
selectserver: new connection received
original: loL
palindrome: YES
original: RaCeCaR_
palindrome: YES
original: new wen
palindrome: YES
original: new2Wen
palindrome: YES
original: test
palindrome: NO
selectserver: socket 4 hung up
^C
ubuntu@ubuntu-ASUS-TUF:~/Documents/OS5$ 
```
***Client:***
```ruby
ubuntu@ubuntu-ASUS-TUF:~/Documents/OS5$ ./client 
Socket successfully created..
connected to the server..
Enter string: loL
Enter string: RaCeCaR_
Enter string: new wen
Enter string: new2Wen
Enter string: test
Enter string: quit
Goodbye!
ubuntu@ubuntu-ASUS-TUF:~/Documents/OS5$ 
```