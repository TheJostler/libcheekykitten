# LibCheekyKitten
A cheeky Kitten cipher is a simple binary obsfucation cipher. Designed to be quick to run and effective at hiding data.

This is the software which implements my quadcode algorithm. My original concept was to have a message interpreted from UTF-8 to hex and then written from top down, instead of left to write... then the 16's place of the first byte would be concatonated with the 16's place of the next byte and same with the 1's on the line bellow. This is a new concept that should be easier to translate onto a computer program and will be more lightweight and faster. Instead the 64-bit(8 bytes) line in hex would be grouped into 4 sections line by line as so:

|XX|YY| |XX|YY| |XX|YY| |XX|YY|

I have created a working version of my algorithm using mathmatical arithmatic.. I am speed testing a "logical bit manipulation" version of the algorithm which I will include in the "LogicalAlgo" directory.

Below is an explanation of my Arithmatic algorithm... 

(For every group or every two bytes of input: x,y)

*All mathmatical operations are performed in base 16... so modulo 0x10 would be modulo 16 in regular decimal.

 X | Y --> Input Bytes

ab | cd --> To help you visualise what the variables represent

b = x mod 0x10

d = y mod 0x10

x = (y -d) + (x / 0x10);

y = (d * 0x10) + b;

Move onto next group...

# INSTALL



# USAGE
