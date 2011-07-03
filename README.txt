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
and only know of each other by main.cpp passing one module's output variables
as input arguments to another module.  There are two inconveniences here:

   1)  You must maintain constructor/execution argument lists.
       You must pass things in the correct order, and update the argument list 
       when a new input/output is added or removed.

   2)  If you wish to unit-test any modules, you must write specific methods for
       write-to-file and read-from-file, creating a file-format for each 
       module.  In other words, you have to actually decide to make each module
       standalone, and spend the time on each one to design file formats.

However, using this class, all constructors and execution argument lists consist
of only a single IOList object:

   IOList IOL;
   IOL.set_float_("gravity_m_per_s2", 9.81);
   IOL.set_int_("numParticles", 11);
   IOL.set_vector_string_("particleNames", particleNameVect);
   runSimulation(IOL);


Later, the values can be recovered in any order by knowing the type/name:

   int nPart = iol.get_int_("numParticles");
   float grav = iol.get_float_("gravity_m_per_s2");
   vector<string> vs = iol.get_vector_string_("particleNames");


In my case, this means no longer maintaining execution methods with 30+ args.
This saves a little bit of time by allowing you to add and remove inputs/outputs
at will without modifying any methods' argument lists.  But this isn't why the
IOList class is amazing--this is:

   void runModule(IOList moduleIn, bool prepareStandalone=false)
   {
      if(prepareStandalone)
         moduleIn.writeIOList("ModuleInputs.txt"); 

      member_int_a_    = moduleIn.get_int_("numCows");
      member_double_b_ = moduleIn.get_double_("sheepWeight");
      // ...
   }

Later, you only need to do:

   IOList IOL("ModuleInputs.txt");
   runModule(IOL);


Any module that has no dependencies other than an IOList object can read or 
write that object to file without knowing anything about what is in the IOList 
object.  This means that if you execute the module in a full system, you get 
the exact inputs needed to rerun that module identically in a 
standalone/isolated environment.  In other words, it is effortless to implement 
I/O files for each module, besides choosing a filename.


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
      
