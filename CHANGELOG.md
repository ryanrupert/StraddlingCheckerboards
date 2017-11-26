# Changelog

## v2.1.2 (2017-11-22)
### Fixed
* Issue with space in getTable function


## v2.1.1 (2017-11-21)
### Fixed
* Constructor parameters


## v2.1.0 (2017-11-13)
### Added
* Constructor parameters

### Changed
* Encode function to make it modular


## v2.0.1 (2017-11-10)
### Fixed
* Warning from the setLang function


## v2.0.0 (2017-04-27)
### Added
* setLang function which will set the language for the object
* getTable function which will load the selected table (Private member)
* table.xml which contains the new tables
* Build with dependencies in the makefile

### Removed
* Old versions of the CT1, CT37, and Code tables that were hard coded were removed


## v1.0.0 (2017-03-29)
### Added
* Encode function to encode the text with the selected table
* Decode function to decode the text with the selected table
* CT1 table used as a table to encode or decode text
* CT37 table used as a table to encode or decode text
* Code table used to shorten or lengthen text being encoded or decoded
