Ah, bit manipulation. Another classic when learning to develop embedded software. It saved me half of my lifetime once when I found out that I could [concatenate](https://www.dictionary.com/browse/concatenate) values that are saved in an array. This was the piece of code:

```c
unsigned long UID = 0;

UID = (tempUID[0] << 24) | (tempUID[1] << 16) | (tempUID[2] << 8) | tempUID[3];
```
This is an example of bit manipulation. The tempUID array holds one byte in every index. To concatenate them, you can use bit manipulation like this one.

It looks complicated at first, I know. But after this article, you will exactly know how this works and feel like this (this was my case):


![Feeling](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/j13byn623wmxau2utiqm.jpeg)


## What is Bit Manipulation?

Bit manipulation is the process of using bitwise operators to manipulate individual bits within a number or value. It is very powerful when you have to make very specific operations.

It's not to be confused with logical operations, which work on boolean values (e.g. true/false).

So let's get straight into it!

## Operators

There are six different operators, of which the last two are very similar, to do bit manipulation. These are the operators:

### AND Operator ( & )

The bitwise AND operator, as it is in the name, sets the bit to "1" if the compared bits are both "1".

| Input A | Input B | Output |
| ------- | ------- | ------ |
|   0     |    0    |   0    |
|   0     |    1    |   0    |
|   1     |    0    |   0    |
|   1     |    1    |   1    |


![AND Illustration](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/vosp43v8kv63q8tqcswk.PNG)

This operator is used for bit-masking. With bit-masking, you select specific bits to be read. Here is an example:

```c
result = address & 0xF0 // 0xF0 -> 11110000b
```

With this mask (0xF0), the first four bits from the right do not have the possibility of becoming '1' because with the AND operator, both bits must be '1' to obtain a '1'.
So if address, for example, is **10100110**, the result would be **10100000**.

### OR Operator( | )

The bitwise OR operator sets the bit to '1' if at least one bit is '1'.

| Input A | Input B | Output |
| ------- | ------- | ------ |
|   0     |    0    |   0    |
|   0     |    1    |   1    |
|   1     |    0    |   1    |
|   1     |    1    |   1    |


![OR Illustration](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/vhdbzgtanhgqtpmzoma1.PNG)

This operator is used a lot for combining values or concatenating them (for concatenation you would also need bit-shifting).

```c
test |= 0x80 // 0x80 -> 10000000
test = test | 0x80 // same result
```

This will set the 8th bit of the variable 'test' to '1', regardless of the value of 'test'.

### XOR Operator ( ^ )

The bitwise XOR operator is a very interesting one. In my [previous article](https://dev.to/dariocasciato/edgy-firmware-the-only-edge-detection-solution-youll-ever-need-1ma6), I mentioned that this operator can be very powerful. The XOR operator sets a bit to '1' if the two compared bits are unequal.

| Input A | Input B | Output |
| ------- | ------- | ------ |
|   0     |    0    |   0    |
|   0     |    1    |   1    |
|   1     |    0    |   1    |
|   1     |    1    |   0    |


![XOR Illustration](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/5da3e5zld35j8rl7uvfo.PNG)

There are many different use cases for the XOR operator, such as encryption with a key, toggling, or change detection. But there are many more. I used the change detection for [Edge detection](https://dev.to/dariocasciato/edgy-firmware-the-only-edge-detection-solution-youll-ever-need-1ma6). In this example, we are going to toggle values:

```c
value = value ^ 0xFF // 0xFF -> 11111111
```
Every bit in value that is a '1' will turn to '0', since 1 XOR 1 will result in 0.

Every bit in value that is a '0' will turn to '1', since 0 XOR 1 will result in 1.


### NOT Operator ( ~ )

The bitwise NOT operator is the easiest one to understand. It does exactly the same as in the example above for the XOR. It inverts every bit. The syntax is very simple.

| Input | Output |
| ----- | ------ |
|   0   |   1    |
|   1   |   0    |


![NOT Illustration](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/osiwqadyeejc8g5554b1.PNG)

This operator is very useful; for example, if you need to initialize a value inverted, you can use the bitwise NOT operator.

```c
value = 0xF0; // 0xF0 -> 11110000

value = ~value;
```

After the operation, value is **00001111**.

### LEFTSHIFT Operator ( << )

Now the interesting ones begin. These operators do exactly the thing they are called. They shift! You only need to specify how many bits the value should be shifted.


![LEFTSHIFT Illustration](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/6tjt9tigbmxdt7j4hgql.PNG)

As mentioned in the first example, this is very useful to concatenate values.


```c
value = 0x0F << 2; // 0x0F -> 00001111
```

You have 2 inputs with this operator. The one on the left is the value that needs to be shifted, and the right one specifies how many bits it needs to be shifted. So the result of this example would be **00111100**. You can also see that the new bits that are pushed in from the right are '0'. This is default and cannot be changed.

### RIGHTSHIFT Operator ( >> )

The right-shift bitwise operator also shifts bits. The only difference is that it shifts bits to the right.


![RIGHTSHIFT Illustration](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/zazawessd0q4a4ssn2xo.PNG)

Also, this one can be used for concatenating values. It also comes in handy in encryption. You can shift a value in a direction by a known amount of times. Combining it with other operators makes this extremely powerful.

```c
value = 0x50 >> 2; // 0x50 -> 01010000
```

I think you can already guess the result. If we shift 0x50 (01010000) to the right by 2, we get **00010100**.

## Understanding the first example

Now that the theoretical part is done, we should be able to understand the first example of bit manipulation I made. The goal is to concatenate them all together to get one value that contains all other values.


```c
unsigned long UID = 0;

UID = (tempUID[0] << 24) | (tempUID[1] << 16) | (tempUID[2] << 8) | tempUID[3];
```

To illustrate this, we assign a value to each array index:

```c
                    //  HEX     BIN
tempUID[0] = 0xA3;  //  0xA3    10100011
tempUID[1] = 0xFF;  //  0xFF    11111111
tempUID[2] = 0x67;  //  0x67    01100111
tempUID[3] = 0xF0;  //  0xF0    11110000
```

This bit manipulation involves two steps. The first step is to shift the values, and the second step is to combine them using the OR operator.

We need to shift all the values by the number given in the calculation:

```c
tempUID[0]:     10100011 00000000 00000000 00000000 // shifted by 24
tempUID[1]:              11111111 00000000 00000000 // shifted by 16
tempUID[2]:                       01100111 00000000 // shifted by 8
tempUID[3]:                                11110000 // not shifted
```

The second step is to combine them using the OR operator:

```c
UID = 10100011 11111111 01100111 11110000
```

So, That's it! When you first look at a calculation involving bit manipulation, it can be confusing. However, when you split up the whole process into steps, it becomes more comprehensible.

## Finale

Thank you for reading! I hope you learned something new from this article. The series will continue soon with a new article about structuring your firmware.

Feel free to leave any comments or questions below, and I'll do my best to help you out!

May your code be bug-free!