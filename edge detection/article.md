# Edgy Firnware: The Only Edge Detection Solution You'll Ever Need

## My first experience

I think this topic is a very classic, when you are writing your first more complex embedded program (rather than a blinking LED). E.g. You want to count how many times a button has been pressed. This was one of my first tasks I was ever given, when I was learning firmware development.
I thought that it was as easy as:
```c
if(digitalRead(BUTTON)) counter++;
```
But this method resulted in the counter incrementing infinitely in a matter of seconds because it checked if the button was pressed and not if there was a positive edge.

In my apprenticeship as an electronics engineer, I had a teacher that spoke more about his political opinions than coding. But the few times he talked about coding, he really taught us something. He once taught me five lines of code that changed the way I see the world and how I write code. These are the following:

```c
btn.old = btn.act;
btn.act = INPUT;
btn.edge = btn.act ^ btn.old;
btn.edge_pos = btn.edge & btn.act;
btn.edge_neg = btn.edge & btn.OLD;
```

I know this does not look like much, but after you read this article, you will realize that this is the perfect edge detection method.

## How to set it up

### Struct

To make it as much "clean code" as possible, it's very nice to use a struct for this case.

```c
typedef struct
{
    uint8_t act;
    uint8_t old;
    uint8_t edge;
    uint8_t edge_pos;
    uint8_t edge_neg;
} edge_t;
```

### Detection

Now the five sacred lines of code follow. They are inserted at the top of the while or infinite program loop. Don't forget to initialize the edge_t struct:

```c
int main()
{
    edge_t btn = {0};

    while(1)
    {
        btn.old = btn.act;
        btn.act = digitalRead(BUTTON);
        btn.edge = btn.act ^ btn.old;
        btn.edge_pos = btn.edge & btn.act;
        btn.edge_neg = btn.edge & btn.OLD;


        // Inifinite loop, user code
    }
}
```

In this example, I am reading the input from a button that is connected to one of the digital pins on an Arduino.

Now we are set! At the beginning, it looks a bit clunky, but you will understand how easy it works below.

## How to use it?
If you only have one button in your circuit/project, it's going to be incredibly easy to use this edge detection.

We have the possibility to detect/get the following properties of the button:
- The current state
- The state it had in the previous cycle
- Change of state
- Positive edge
- Negative edge

Here is how you can detect/get these properties:

### The current state
```c
if(btn.act)
{
    Serial.println("Button is pressed!");

    //Detects if the button is pressed. equivalent of "if(digitalRead(BUTTON))"
}
```

### The button state in the previous cycle
```c
if(btn.old)
{
    Serial.println("Button was pressed last cycle!");

    //Detects if the button was pressed the cycle before
}
```

### Change of state
```c
if(btn.edge)
{
    Serial.println("Button State changed!");

    //Detects if the button changed from not pressed to pressed, and vice versa
}
```

### Positive Edge
```c
if(btn.edge_pos)
{
    Serial.println("Button pressed down!");

    //Detects if the button changed from not pressed to pressed (Positive Edge)
}
```

### Negative Edge
```c
if(btn.edge_neg)
{
    Serial.println("Button released!");

    //Detects if the button changed from pressed to not pressed (Negative Edge)
}
```

## How does it work?

Now follows the explanation of these code lines:
```c
btn.old = btn.act;
btn.act = digitalRead(BUTTON);
btn.edge = btn.act ^ btn.old;
btn.edge_pos = btn.edge & btn.act;
btn.edge_neg = btn.edge & btn.old;
```

**To illustrate the states of the boolean values, I will be using Level Diagrams, where each square represents one iteration of the infinite program loop.**

### btn.act

```c
btn.act = digitalRead(BUTTON);
```

(In this example, we are again reading a button input that is connected to a digital pin of an Arduino)

The **act** value is straightforward to understand, as it always has the same value as **digitalRead(BUTTON)**. Throughout the rest of the explanation, I will refer to the current button state as **act**.



![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/y5fyvib7z15jrnhpw3q9.PNG)



### btn.old

```c
btn.old = btn.act;
btn.act = digitalRead(BUTTON);
```

The **old** value refers to the state of the button in the previous iteration of the program loop. It is always the state of the button in the previous cycle. We save the value **act** into **old**, and then first we get the new value for **act**.



![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/sw2tsszefc2xuix7128x.PNG)


### btn.edge

```c
btn.edge = btn.act ^ btn.old;
```
Now it gets interesting. The "^" operator, also known as the XOR operator, detects whether two values are different. It returns true if the values are different and false if the values are the same. So now we have the possibility to detect a change in the state of the button, if we compare **act** and **old**.


![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/eyfpec3ypwu10dy26z4t.PNG)


### btn.edge_pos

```c
btn.edge_pos = btn.edge & btn.act;
```

So the **edge_pos** is the one we are all looking for! This detects the positive edge, or the change from not pressed to pressed.

We compare the value **edge** and **act** with an AND operator. The AND operator returns true if both values are true.

If **edge** is true, we know that we had a change in the button state. The change is detected if **act** and **old** are unequal.

If we have a change from not pressed to pressed, act is true and old is false. If we have a change from pressed to not pressed, act is false and old is true. That's why we can compare **edge** and **act** with the AND operator to get the positive edge.


![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/s253uy5koeu4x5zsvtez.PNG)


### btn.edge_neg

```c
btn.edge_neg = btn.edge & btn.old;
```

There are cases where you have to read the negative edge of a signal.

As I explained before, if we have a change from pressed to not pressed, **act** is false and **old** is true. So now we can compare **edge** and **old** with the AND operator to get the negative edge.



![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/p6ri2do4ysmqzicjw8hd.PNG)

<br/>
<br/>

## More than one button?

So, you have more than one button in your project, and every button needs edge detection? Don't think that you have to do this:

```c
edge_t btn1 = {0};
edge_t btn2 = {0};
edge_t btn3 = {0};
edge_t btn4 = {0};
...
```

Since every value in the struct is declared as uint8_t, we have 8 bits to use in every value! The only thing we have to do to have more than just one button is to redefine the **act** value.

I'm going to make an example where I have 8 buttons, and every button is connected to one digital pin of an Arduino from pin 1 to 8:

```c
btn.act =   digitalRead(1) |
            (digitalRead(2) << 1) |
            (digitalRead(3) << 2) |
            (digitalRead(4) << 3) |
            (digitalRead(5) << 4) |
            (digitalRead(6) << 5) |
            (digitalRead(7) << 6) |
            (digitalRead(8) << 7);
```
*[My Article about Bit-Manipulation](https://dev.to/dariocasciato/bits-and-bytes-a-comprehensive-guide-to-bit-manipulation-for-developers-m5c)*

Now, every bit of **act** corresponds to one button.


![Image description](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/rz8bkn2gpsy3g4ihbkst.PNG)

We can't use **if(btn.edge_pos)** anymore. We need to specify which button we want to detect. This can be done with a bit mask.

I like to create **Defines** for every button.

```c
//                  HEX         BINARY
#define BUTTON_1    0x01    //  00000001
#define BUTTON_2    0x02    //  00000010
#define BUTTON_3    0x04    //  00000100
#define BUTTON_4    0x08    //  00001000
#define BUTTON_5    0x10    //  00010000
#define BUTTON_6    0x20    //  00100000
#define BUTTON_7    0x40    //  01000000
#define BUTTON_8    0x80    //  10000000
```

Every value I gave the defines represents one bit for the **uint8_t act**.

From here, it is straightforward. If we want to detect, for example, the positive edge of the third button, we can do this:

```c
if(btn.edge_pos & BUTTON_3)
```

With this bit mask, we allow it to detect changes only for the specific bit.

## Finale

Thank you for reading! I encourage you to continue exploring this topic further and see how you can apply it in your projects. I am excited to announce that I will be continuing this series on Firmware Basics!

Feel free to leave any comments or questions below, and I'll do my best to help you out!

May your code be bug-free!