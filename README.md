0. Implement the push and pall opcodes.

The push opcode

The opcode push pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
You won’t have to deal with overflows. Use the atoi function
The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

Usage pall
Format: see example
If the stack is empty, don’t print anything

1. Implement the pint opcode.

The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

2. Implement the pop opcode.

The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

3. Implement the swap opcode.

The swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

4. Implement the add opcode.

The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

5. Implement the nop opcode.

The nop opcode

The opcode nop doesn’t do anything.

Usage: nop

6. Implement the sub opcode.

The sub opcode

The opcode sub subtracts the top element of the stack from the second top element of the stack.

Usage: sub
If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

7. Implement the div opcode.

The div opcode

The opcode div divides the second top element of the stack by the top element of the stack.

Usage: div
If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

8. Implement the mul opcode.

The mul opcode

The opcode mul multiplies the second top element of the stack with the top element of the stack.

Usage: mul
If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

9. Implement the mod opcode.

The mod opcode

The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

Usage: mod
If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

10. Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

11. Implement the pchar opcode.

The pchar opcode

The opcode pchar prints the char at the top of the stack, followed by a new line.

Usage: pchar
The integer stored at the top of the stack is treated as the ascii value of the character to be printed
If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

12. Implement the pstr opcode.

The pstr opcode

The opcode pstr prints the string starting at the top of the stack, followed by a new line.

Usage: pstr
The integer stored in each element of the stack is treated as the ascii value of the character to be printed
The string stops when either:
the stack is over
the value of the element is 0
the value of the element is not in the ascii table
If the stack is empty, print only a new line

13. Implement the rotl opcode.

The rotl opcode

The opcode rotl rotates the stack to the top.

Usage: rotl
The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
rotl never fails

14. Implement the rotr opcode.

The rotr opcode

The opcode rotr rotates the stack to the bottom.

Usage: rotr
The last element of the stack becomes the top element of the stack
rotr never fails

15. Implement the stack and queue opcodes.

The stack opcode

The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

Usage: stack
The queue opcode

The opcode queue sets the format of the data to a queue (FIFO).

Usage: queue
When switching mode:

The top of the stack becomes the front of the queue
The front of the queue becomes the top of the stack

16. Write a Brainf*ck script that prints School, followed by a new line.

All your Brainf*ck files should be stored inside the bf sub directory
You can install the bf interpreter to test your code: sudo apt-get install bf
Read: Brainf*ck

17. Add two digits given by the user.

Read the two digits from stdin, add them, and print the result
The total of the two digits with be one digit-long (<10)

18. Multiply two digits given by the user.

Read the two digits from stdin, multiply them, and print the result
The result of the multiplication will be one digit-long (<10)

19. Multiply two digits given by the user.




Read the two digits from stdin, multiply them, and print the result, followed by a new line 
