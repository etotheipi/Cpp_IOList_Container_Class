
#ifndef _IOLIST_H_
#define _IOLIST_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//#define NDEBUG
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////
//
//  This class was created by a python script, specifically designed
//  to construct the individual methods for each datatype.  C++ 
//  really doesn't like mixed data types, but I really want them,
//  so I'm doing this anyway.
//
//  -----------------------------------------------
//  VERSION_HASH:  aeba7045b138314589763e9731157c6e
//  -----------------------------------------------
//
//  The version hash is created by concatenating all types in the python
//  script to be included here, then taking the MD5 hash of the resulting 
//  string.  Therefore, if a type is added or removed, or the list is 
//  reorganized, the version hash will change, and we can verify that
//  any files written with an old hash MAY NOT work with the newer code.
//  This is only likely to break if data types were removed.
//  
//
//  class IOList
//    
//    Author:  Alan Reiner
//    Date:    25 June, 2011
//    What:    The purpose of this class is to hold an array of mixed-type
//             objects that is extremely easy to use and pass around between
//             modules.  This makes the interfaces trivial to modify, since
//             they only require a single IOList input, which could contain
//             any number and combination of variables.  
//
//             Additionally, I hope that the IOLists will have a generic
//             "pickling" which allows them to be converted to and from files. 
//             The benefit is that every time the module is run, it can write
//             the IOList to file before consuming, and then the exact same 
//             inputs can be read from file to run the module in a standalone
//             state, later.  
//
//             Unfortunately, C++ does not make it easy to store mixed data
//             types in the same data structure.  I had to go to great lengths
//             to figure out how to reduce the number of steps you have to take
//             to include a new datatype in the IOList interface.  It's not
//             trivial, and definitely not scalable, but it's a one time
//             investment (to enable IOList storage of your new datatype). 
//             Every technique I could come up with to make this easier had
//             at least one fatal flaw.
//
//             In the future, it might be worth looking into the C++0x TR1 
//             libraries, which include the boost::any class.  It sounds
//             ideal for this application, though I'm not sure how well the 
//             pickling will work.  You would still have to manually specify
//             how the individual data types can be written/read to/from file.
//             And of course, you'd have to have the boost libraries available
//             on all the target systems.
//
//             This class is not optimized for speed or efficiency, because 
//             it's only use is as an container to pass assorted groups of 
//             assorted data between modules.  It won't be necessarily "slow"
//             either, but definitely should not be used for arbitrary 
//             computational activities. 
//

typedef enum
{

   IOLIST_float,
   IOLIST_double,
   IOLIST_int,
   IOLIST_short,
   IOLIST_bool,
   IOLIST_string,
   IOLIST_vector_float,
   IOLIST_vector_double,
   IOLIST_vector_int,
   IOLIST_vector_short,
   IOLIST_vector_bool,


   IOLIST_NUM_TYPES,
   IOLIST_KEY_NOT_EXIST
} IOLIST_TYPE;

class IOList
{

private:
   map<string, IOLIST_TYPE> map_types_;
   map<string, string> map_typename_;
   vector<string> key_list_;
   static string versionHash_;

public:

   IOLIST_TYPE getType(string key);
   void writeIOList(ostream & os);
   void readIOList(istream & is);

   string getVersionHash(void) { return versionHash_; }
   bool compareVersionHash(string hash) { return (hash.compare(versionHash_)==0);}

   void writeKeyList(ostream & os);

private:

   map< string, float > map_float_;
   map< string, double > map_double_;
   map< string, int > map_int_;
   map< string, short > map_short_;
   map< string, bool > map_bool_;
   map< string, string > map_string_;
   map< string, vector<float> > map_vector_float_;
   map< string, vector<double> > map_vector_double_;
   map< string, vector<int> > map_vector_int_;
   map< string, vector<short> > map_vector_short_;
   map< string, vector<bool> > map_vector_bool_;
public:

   // Enable datatype float (float)
   float get_float_(string key);
   void set_float_(string key, float const & val);
   void write_float_(string key, ostream & os);
   void read_float_ (string key, istream & is);
   

   // Enable datatype double (double)
   double get_double_(string key);
   void set_double_(string key, double const & val);
   void write_double_(string key, ostream & os);
   void read_double_ (string key, istream & is);
   

   // Enable datatype int (int)
   int get_int_(string key);
   void set_int_(string key, int const & val);
   void write_int_(string key, ostream & os);
   void read_int_ (string key, istream & is);
   

   // Enable datatype short (short)
   short get_short_(string key);
   void set_short_(string key, short const & val);
   void write_short_(string key, ostream & os);
   void read_short_ (string key, istream & is);
   

   // Enable datatype bool (bool)
   bool get_bool_(string key);
   void set_bool_(string key, bool const & val);
   void write_bool_(string key, ostream & os);
   void read_bool_ (string key, istream & is);
   

   // Enable datatype string (string)
   string get_string_(string key);
   void set_string_(string key, string const & val);
   void write_string_(string key, ostream & os);
   void read_string_ (string key, istream & is);
   

   // Enable datatype vector_float (vector<float>)
   vector<float> get_vector_float_(string key);
   void set_vector_float_(string key, vector<float> const & val);
   void write_vector_float_(string key, ostream & os);
   void read_vector_float_ (string key, istream & is);
   

   // Enable datatype vector_double (vector<double>)
   vector<double> get_vector_double_(string key);
   void set_vector_double_(string key, vector<double> const & val);
   void write_vector_double_(string key, ostream & os);
   void read_vector_double_ (string key, istream & is);
   

   // Enable datatype vector_int (vector<int>)
   vector<int> get_vector_int_(string key);
   void set_vector_int_(string key, vector<int> const & val);
   void write_vector_int_(string key, ostream & os);
   void read_vector_int_ (string key, istream & is);
   

   // Enable datatype vector_short (vector<short>)
   vector<short> get_vector_short_(string key);
   void set_vector_short_(string key, vector<short> const & val);
   void write_vector_short_(string key, ostream & os);
   void read_vector_short_ (string key, istream & is);
   

   // Enable datatype vector_bool (vector<bool>)
   vector<bool> get_vector_bool_(string key);
   void set_vector_bool_(string key, vector<bool> const & val);
   void write_vector_bool_(string key, ostream & os);
   void read_vector_bool_ (string key, istream & is);
   
};
#endif
