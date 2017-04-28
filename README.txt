Forms
	*A form would allow for a user to create a new entry in the database. 

Reports
	*A report is used to display information from the database. Specific information relevant to the information within. 

Queries
	*Allow for the retrieval and use of data. There may be 2 potential query options, the first being just for viewing
	the data and the second for viewing and editing an entry

Macros
	*Consider adding a macro as a feature to the database to make using it easier. 

Modules
	*module = struct basically. 

brainstorm
	*Should this "database" simply interact with 1 file which it can simply read from and append information to?
	*if the data is stored in a file then the order of adding new information has to be adding/appending information to the file, and then running the command to sort the entries alphabetically.

Still need
	*A function to edit information in the info.txt files.
	*A function or program that creates and output file that shows the result of some query
	*Some way to organize the files in the database directory.
	*A way to identify the fields and get just that specific piece
	*Some kind of security or password maybe.
	*Implimentation of a Hash table. Database indexing
		-A hash table (hash map) is a data structure which implements an associative array abstract data type, a structure that can map keys to values
		-A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

		   e.g. < index = f(key, array_size) >
		   
		   e.g.	< hash = hashfunc(key)       >
			< index = hash % array_size  >

		-The index is made based on the data entry itself so if you need to find a specific entry it will be possible to use the hash function
		to calculate the key/index needed to get access to it.
	*Our hash function will associate each file with a key for access????
	
	
	
