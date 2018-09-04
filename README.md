# Befunge93 #

This is a simple interpreter for the Befunge93 language.

## Installation ##
### Dependencies ###
This interpreter uses cmake as its build system, and boost for parsing command line arguements.

Using whatever manner your operating system uses to install packages, install cmake and boost.

On Mac, that would be done with
`brew install cmake && brew install boost`
### Compilation ###
To compile, first create the Makefile with
`cmake CMakeLists.txt`
Then build with
`make`

This should create an executable called `Befunge93` in your directory.

## Usage ##
Run Befunge93 with the --filepath flag to specify what program to run. 
Example:

`./Befunge93 --filepath ExamplePrograms/beer.bf`

This runs the "99 bottles of beer" example program that has been included