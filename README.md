# Straddling Checkerboards

## Synopsis
This is a C++ class that will be used to encode and decode using a straddling
checkerboard.

## Getting Started
These instructions will get you a copy of the project up and running on your
local machine for development and testing purposes.

### Installation

#### Prerequisites
There are no prerequisites for this class.

#### Installing
Place all the files for this class in your project folder.

### Code Example
See the documentation for code examples

## Built With
This was built with pugixml for the xml parsing. And is included in this repository under lib.

## Motivation
The motivation for this project was to build a encoder and decoder class for a
straddling checkerboard.

## Tasks
- [x] Add in Spanish
- [x] Add in German
- [ ] Add conversion from UTF-8 to Code page 437
- [ ] Add in more straddling checkerboards
- [x] Make more modules by using a text files or xml file to hold the tables

## Issues
* The display of Accented characters such as `ß`, `Ö`, `Á` does not work. The character's are read from the file as UTF-8 but windows uses Code page 437.

## History
View CHANGELOG.md for all the important changes made and future changes

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

## Authors
Ryan Rupert
