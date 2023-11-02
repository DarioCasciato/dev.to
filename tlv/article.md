Title: TLV: A Powerful Tool for handling Data in Embedded Systems

Todays article in the firmware 101 series is about TLVs. TLVs are a way to store or organize data. Since i've known about TLVs, i use them in almost every project, becuase of their simplicity and flexibility. In this article i will explain what TLVs are, how they work and how/where to use them.

## What are TLVs?

The first time i've heard about TLV's, was about 2.5 months ago, when i started to work as a fulltime embedded developer. (I firstly confused it with the Windows VLC media player).
TLV stands for **Tag**-**Length**-**Value**. If you illustrate them, they look something like this:

(Image raw)

TLV's are just a way to organize data and make it easy to interpret. TLV formats allows a compact representation of data, which is needed in embedded systems, where memory and storage are limited.

## how do TLVs work?

As mentioned before, a TLV is made up of 3 Parts: Tag, Length and Value:

### Tag
The Tag is like the ID of the data. It tells you what kind of data is stored in the TLV. For example, if you are searching for a specific data, you can just look for the corresponding tag. For example, if you have a device-number and a password, and you want to store them, you can just assign them tags. The tags could be something like this:

**Tags:**
- Device-ID: 0x01
- Password: 0x02

### Length
The length is the length of the value. It tells you how many bytes the value is long.
For example, if you have a 32-bit integer as value, the length would be 4 (bytes). The length is needed, because the value can be of any length. It could be a single byte, or a 32-bit integer, or even a string. The length is needed to know how many bytes you have to read for the value.
The length is also needed when searching for a specific tag or value in a flash storage for example. If you know the length of the value, you know how many bytes you have to skip to get to the next TLV.
Here for example, we are searching for a number that is stored in a flash storage with the TLV-Tag **0x03**:

(Img search)

When we reach the TLV with the tag **0x03**, we know that the value is 4 bytes long, so we can just read the next 4 bytes and we have the number!

### Value
The Value is the actual data. It can be of any length and any type. It can be a single byte, a 32-bit integer, a string, or even another TLV. The value is the actual data that you want to store or transmit.

It's also possible to store more than 1 value in a TLV. In a communication-protocol it's very common to do so. This could look something like this:

(2-values img)

Since the receiver of the data knows what kind of command is receieved (because of the tag), it knows how to interpret the values. For example, if the tag is 0x01, the receiver knows that the first value is the device-number and the second value is. The length of the TLV is just the sum of the lengths of these values.



## Where to use TLVs?
There are a lot of applications that use TLVs. A common application is in communication protocols. For example, if you have a device that communicates with a host, you can use the TLV encoding to transmit the data, so it's easy to interpret for the host. It's also possible to set up a server that can handle TLVs. So if you want to request something from the server, you can just send a TLV with the tag of the request without any data (the length would be 0), and the server could then respond with the same tag and the requested data as value.

(server-client img)

Also a common application is in flash storages. If you want to store a devices data, scores, credentials or something else, you can just store them in TLVs, and when you want to read them, you can just search for the corresponding tag and read the value. So it's also possible to update the data, by just overwriting the TLV with the same tag. But you have to be cautious! Because if the new value is longer than the old one, you have to make sure that there is enough unused space after the TLV, so you don't accidentally overwrite the next TLV (if there is one).

Not long ago, i wrote a ID-Storage Library in C++ for Arduino, that exactly uses the principle of TLVs. It's a library that allows you to store and retrieve data in a flash/eeprom storage. You can find it here: [ID-Storage Library](https://github.com/DarioCasciato/arduino-template-oop/blob/main/utils/Storage/IDStorage.h)


## Finale
Thank you for reading! I hope you learned something new from this article.

Feel free to leave any comments or questions below, and I'll do my best to help you out!

May your code be bug-free!