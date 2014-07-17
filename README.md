Name: Simple Buffer Overflow

Description: The user will be presented with a C program that takes input using gets(). Their objective will be to overflow the buffer so that they will overwrite the data contained by the variable named "keyRequest".
The "keyRequest" variable will then be sent to a server via a socket. The server will then check to see if the keyRequest is correct. If it is correct, the key will be transmitted back to the user.
Otherwise, the message "Nope." will be displayed. The correct password is "MOSS".

NOTE: Server code is also included in the repository. This will be running on the server during the even itself. ALSO, we will need to edit the buff.c source code to match the hostname and the port of the server.

Key: aSByZWFsbHkgaG9wZSBsaWZlIGdldHMgZWFzaWVyLi4u

Solution: One way to solve this would be to use a scripting language to overflow the buffer. Example solution: python -c 'print "A"*88 + "MOSS"' | ./buff

To compile: We have to disable the overflow protection. During testing I had compiled using the following command:
 gcc -Wall -fno-stack-protector -D_FORTIFY_SOURCE=0 buff.c -o buff
 
 listener.c
 gcc -Wall -D_FORTIFY_SOURCE=0 listener.c -o listener
 
 Note: You may want to use -g compiler flag to debug the code.

Hint:
	Moss:	Flip! It’s an iPhone! There are flipping iPhones overflowing from the crane machine!
	[Moss looks through pockets]
	Moss:	Ugh, I’m out of coin. 
	[Kicks crane door that reads “PLEASE DO NOT REACH INTO THE PLAYING AREA”]
	[Enter Jen]
	Jen:		Moss?! Moss? What am I gonna do?
	[Moss appears inside of crane, surrounded by toys]
	Jen:		What are you…? How did you get in there?
	Moss:	Through the hole.
	Jen:		Why?
	Moss:	There’s an iPhone, Jen! An actual iPhone!
	Jen:		I need your password. I need the password for the translation program.
	Moss:	Help me get the iPhone first. I can’t move my arms.
	Jen:		No.
	Moss:	I need to get it through the shoot. Someone else will take it if you don’t.
	Jen:		I’m sure they’re not giving it away. An engineer must have dropped it.
	Moss:	No. No. No, it’s a prize! It’s a prize! You’ve gotta help!
	Jen:		I don’t have time.
	Moss:	But it’s an iPhone, Jen. I may be able to get an iPhone without giving any money to Apple! 	I’ll be living the dream!
	Jen:		What’s the password? What’s the password?!
	[Moss tries to get phone with mouth]
	[Jen bangs on glass]
	[Moss stops]
	Jen:		MOSS!
	[Jen bangs on glass]
	Jen:		MOSS!
	[Camera fade]
	[Jen is controlling the crane. Moss has the phone in his mouth and throws it into the shoot. Jen 	looks through the trap door and looks back up at Moss.]
	Jen:		Where is it?
	Moss:	I must be blocking it. I’ll try and move to clear the passage.
	[Moss tries to move with no luck]
	Jen:		Come on, Moss.
	[Moss keeps trying, sweat accumulating on his face]
	Jen:		Come on, Moss. You can do it. Push! Come on, Moss. Keep breathing. PUSH!
	Moss:	Shut up!
	[Moss keeps trying]
	Jen:		You can do it, Moss.
	Moss:	I hate you!
	[Moss keeps trying]
	Jen:		Why are you saying that?
	Moss:	I don’t know! Stop talking!
	[Moss keeps trying]
	Jen:		Come on, Moss. Come on! That’s it! It’s coming! I think I can see the start button! One last push! One, two three! Push! Come on, Moss! Push! Push!
	[Sound of phone entering shoot]
	[Moss calms down]
	[Jen, crying, holds up the phone like a newborn baby]
	Moss:	It’s beautiful.
	Jen:		PASSWORD!
	Hint:		4 digits