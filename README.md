# C++ Straddling Checkerboards

## Synopsis
This is a C++ class that will be used to encode and decode using a straddling
checkerboard.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Installation

#### Prerequisites
There are no prerequisites for this class.

#### Installing
Place all the files for this class in your project folder.

### Code Example
To make the class object use
``` C++
Crypto obj_name; //this creates the class object where obj_name is the name you want to give the object
```
To Encode here is how you do it
```C++
obj_name.Encode (obj_name.CT1, string_to_encode); //this will pass the checkerboard CT1 with the string string_to_encode into the function for encoding
```
To decode here is how you do it
```C++
obj_name.Decode (obj_name.CT37, string_to_decode); //this will pass the checkerboard CT37 with the string string_to_decode into the function for decoding
```
As you can tell change the CTxx part to what ever number to change what checkerboard is used.


## Built With
This was build with pugixml.

## Motivation
The motivation for this project was to build a encoder and decoder class for a straddling checkerboard.

## Tasks
- [ ] Add in Spanish
- [ ] Add in German
- [ ] Add in more straddling checkerboards
- [x] Make more module by using a text files or xml file to hold the tables

## History
4/27/17

Made the straddling checkerboards dynamic by placing them in a xml file. 

3/23/17

Have 2 straddling checkerboards hard coded into the class. Only supports English currently.

With these two tables:

[CT-1](http://users.telenet.be/d.rijmenants/pics/aeinot.gif)

[CT-37](http://users.telenet.be/d.rijmenants/pics/ct37.gif)

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

## Authors
Ryan Rupert
