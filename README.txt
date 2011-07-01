********************************************************************************
*
*  IOList Source Code
*  
*  Author:  Alan Reiner
*  Email:   etotheipi_@_gmail_._com
*  Date:    01 July, 2011
*
********************************************************************************


---------------------
Motivation
---------------------

The goal of this project was to assist myself in extreme modularization of C++
code projects.  Let's say I have a bunch of modules that are independently coded
and only know of each other by the main.cpp passing members from one module
to input arguments for the other modules.  There are two inconveniences here:

   1)  You must maintain constructor/doModule argument lists, and get/set 
       accessors.  You must pass things in the correct order, and update the 
       argument list when a new input/output is added
   2)  For each module you wish to unit test, you must write a separate write-
       and read-from-file method, and create a specialized file-format for each 
       module.  In other words, you have actually decide to make each module
       standalone, and spend the time on each one to create file types for them.

However, using this class, all constructors and doModule argument lists consist
of one object:  an IOList object.  The IOList object is used like this:

   IOList iol;
   iol.set_float_("FirstFloat", 12.5);
   iol.set_int_("numItems", 11);
   iol.set_vector_short_("theShortList", an_stl_vector_of_shorts);

   runModule(iol);



Later, the values can be recovered simply by knowing the type and the name

   int nItem = iol.get_int_("numItems");
   float randomFloat = iol.get_int_("FirstFloat");
   vector<short> vs = iol.get_vector_short_("theShortList");



This saves a little bit of time by allowing you to add and remove inputs/outputs
at will without messing with any methods' argument lists.  This reason alone
doesn't justify the IOList class--this does:

   void runModule(IOList moduleIn, bool writeFile=false)
   {
      if(writeFile)
         moduleIn.writeIOList("ModuleInputs.txt"); 

      member_int_a_    = moduleIn.get_int_("numSomething");
      member_double_b_ = moduleIn.get_double_("randomDouble");
      // ...
   }



Why is this amazing?  Because any module that has no dependencies other than
an IOList object can read or write that object to file without knowing anything
about what is in the IOList object.  This means that if you execute the module
in a full system, you get the exact inputs needed to rerun that module 
identically in a standalone/isolated environment.  In other words, it is 
effortless to implement I/O files for each module, besides picking a filename.


---------------------
Implementation
---------------------

Because C++ does not deal with mixed data types very well, there was not a 
good way to implement this without rewriting the methods for each class, 
individually.  Some might suggest using the boost::any class, but there are
two problems with this:

   1) I have to write the write/read methods for each module, regardless
   2) Not everyone has the boost-library in their target environment (me!)

Every effort I made to find a good-coding-style C++ way to do this, had
at least one fatal flaw.  So I resorted to drastic measures...

I created a python script which constructs all the type-specific methods 
for me.  The python script contains a list of data types to be supported
by the class, and will write the get/set/write/read methods for each.
Most of the methods can be written automatically because of the similarity
of datatypes.  Others require customized write/read methods, but that's okay.
The script did 99% of the other work for us.


---------------------
Versioning
---------------------

While this is not scalable to arbitrary datatypes, they data type only needs
to be included once, ever.  The python script includes a copy of itself at 
the end of the header file, so you always have the latest copy of the .py
script if you have the latest .h file.  You only need to keep the .py
script, or copy the .py script from the .h and run it with the new datatypes.

There might be a problem if IOList files are created, and then the IOList
types are changed as described in the previous paragraph.  This is handled
by notifying the user that the version has changed since the IOList file was
created.  The list of datatypes at the top of the .py file are all concatenated
together its hash is hardcoded into the IOList class.  If you make sure you
write this version hash to every IOList file, you will always know if you match
versions.  Changing the IOList version is not guaranteed to break compatibility,
but you are guaranteed to be okay if the version hash matches
      
