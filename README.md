# addressbook_test
The test task for foundry.com company


C++ PROGRAMMING​ TASK​ : ADDRESS​ BOOK

SUMMARY

Using standard C++ and only its standard library, design and implement code that models an address book.

MINIMUM REQUIREMENTS

Support from zero to a “large number” of entries (typically 100,000s).
Entries should contain:

○ A first and/or last name (you can treat each character as a single byte, i.e. no need to support
Unicode).

○ An optional phone number.

Provide functionality to:

○ Add an entry.

○ Remove an entry.

○ Retrieve entries in alphabetical order, sorted by first name.

○ Retrieve entries in alphabetical order, sorted by last name.

○ Retrieve entries whose first or last name exactly or partially match a supplied search string,
from the beginning of the name (e.g. searching for “Dan” would match any entries with
“Daniel” as well as any “Dan”).

■ Make this matching case insensitive.

Write a short main() function that demonstrates all of the address book’s functionalities:

○ It is fine to hard-code example entries.

○ It is fine to write to the standard output.

Provide documentation for the API and to justify your design choices.

Use only features up to and including C++14.

Provide instructions on how to build your code.

ADDITIONAL​ ​ CONSIDERATIONS

Imagine that the address book code could be used by other developers, in various client applications.
Assume that the retrieval operations are going to be called the most frequently in the majority of
client applications.

NOTES

You will be given up to three days to think about and implement your solution, but this is not
intended to be a big programming task. There is no limit on the amount of time you should spend on
it but bear in mind that most candidates take around two to three hours to complete. When
submitting your solution, please let us know approximately how much time you spent.
Feel free to use C++ and standard library references, e.g. ​ cppreference.com​ , but please do not ask for
help with the specifics of this task. It should be your own work.
Feel free to comment on any known shortcomings of your design and make suggestions about how
these could be addressed given more time or if the library and version restrictions were removed.


##My description of the implementation of the test and my thoughts: 

At the beginning I decided to implement this task based on Trie data structure.
This is the fastest possible structure for searching in set of words by predicates. 
as it required in the requirement "Assume that the retrieval operations are going to be 
called the most frequently in the majority of client applications.". 

I decided to implement the Trie myself because it is a test task and I wanted to show how I can implement 
of data structures and algorithms. In real project I'd prefer to choose a well known reliable library with 
many users after careful code review. It is one half finished and I will finish it in several days 
but I found that I overloaded with interviews and will unable to finish in time. So I rewrote the task 
based on std::maps. It is not perfect solution but it fast enough and very short. I prepared test data for 
100.000 records as it was described in the requirement and made load testing the solution.

#### Architecture

The project divided to the library and a test executable. 
I implemented it as a library because of this requirement: "Imagine that the 
address book code could be used by other developers, in various client applications."
It was required to use C++ so I described API of this library in C++ style,
but in real work I would consider to describe the API a set of plain C functions with C calling convention
(in Windows API style with handles) because it allows the users to use this library in all languages which 
support import of plain C functions.     
 
The API is simple and and well commented so it is enough to read the HPP file and the test source code 
to understand how it works.

I didn't implemented error handing at all because proper error handling takes significant time for implementing
and simple one doesn't make sense in test project.
In industrial projects choosing of error handling system depends on many factors:
- How much hardware resources we have;
- Is the system we working in a realtime system.
- Can we use RTTI;
- Can we use exceptions.
- If our library is a part of a big system or framework will our error handing system be compatible with 
the system of the framework
- Is there a corporative standard for such systems as error handling, logging and so on. 
   

#### how to build

I used Cmake as a build system so build process is standard:
run

``` 
cmake -S . -B build
cmake --build build
in the directory with the project.
```

#### how to run

Go to the "test" directory it will contain the test executable and the test data.

run: 

```test_exe < 10lines.txt``` 

it shows how all functions work.
Then run:

```test_exe < 100000lines.txt```

for load testing.

I'm sorry again that the code is a bit dirty but I really was unable to reject other interviews 
and the bomb explosions make me nervous. :)
