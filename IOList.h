
#ifndef _IOLIST_H_
#define _IOLIST_H_

#include <iostream>
#include <fstream>
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
//  so I'm doing this anyway.  A copy of the python is included at the
//  end of this file
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

   IOList(void);
   IOLIST_TYPE getType(string key);

   void clearIOList(void);
   void writeIOList(string filename);
   void readIOList(string filename);
   void writeIOList(ostream & os);
   void readIOList(istream & is);

   int size(void) {return (int)key_list_.size();}
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
   float const & get_float_(string key);
   void set_float_(string key, float const & val);
   void write_float_(string key, ostream & os);
   void read_float_ (string key, istream & is);
   
   // Enable datatype double (double)
   double const & get_double_(string key);
   void set_double_(string key, double const & val);
   void write_double_(string key, ostream & os);
   void read_double_ (string key, istream & is);
   
   // Enable datatype int (int)
   int const & get_int_(string key);
   void set_int_(string key, int const & val);
   void write_int_(string key, ostream & os);
   void read_int_ (string key, istream & is);
   
   // Enable datatype short (short)
   short const & get_short_(string key);
   void set_short_(string key, short const & val);
   void write_short_(string key, ostream & os);
   void read_short_ (string key, istream & is);
   
   // Enable datatype bool (bool)
   bool const & get_bool_(string key);
   void set_bool_(string key, bool const & val);
   void write_bool_(string key, ostream & os);
   void read_bool_ (string key, istream & is);
   
   // Enable datatype string (string)
   string const & get_string_(string key);
   void set_string_(string key, string const & val);
   void write_string_(string key, ostream & os);
   void read_string_ (string key, istream & is);
   
   // Enable datatype vector_float (vector<float>)
   vector<float> const & get_vector_float_(string key);
   void set_vector_float_(string key, vector<float> const & val);
   void write_vector_float_(string key, ostream & os);
   void read_vector_float_ (string key, istream & is);
   
   // Enable datatype vector_double (vector<double>)
   vector<double> const & get_vector_double_(string key);
   void set_vector_double_(string key, vector<double> const & val);
   void write_vector_double_(string key, ostream & os);
   void read_vector_double_ (string key, istream & is);
   
   // Enable datatype vector_int (vector<int>)
   vector<int> const & get_vector_int_(string key);
   void set_vector_int_(string key, vector<int> const & val);
   void write_vector_int_(string key, ostream & os);
   void read_vector_int_ (string key, istream & is);
   
   // Enable datatype vector_short (vector<short>)
   vector<short> const & get_vector_short_(string key);
   void set_vector_short_(string key, vector<short> const & val);
   void write_vector_short_(string key, ostream & os);
   void read_vector_short_ (string key, istream & is);
   
   // Enable datatype vector_bool (vector<bool>)
   vector<bool> const & get_vector_bool_(string key);
   void set_vector_bool_(string key, vector<bool> const & val);
   void write_vector_bool_(string key, ostream & os);
   void read_vector_bool_ (string key, istream & is);
   
};
#endif


// The following is a copy of the python script used to create IOList sources
// The script includes a copy of itself in the header file it creates!
/*
from os import path
import hashlib
from sys import argv


################################################################################
## Master list of datatypes to be included in the IOList class
typelistFull = [ ['float',                         'STD_RW'], \
                 ['double',                        'STD_RW'], \
                 ['int',                           'STD_RW'], \
                 ['short',                         'STD_RW'], \
                 ['bool',                          'STD_RW'], \
                 ['string',                        'CUSTOM'], \
                 ['vector<float>',                 'ARRAY_1D_SQ_BRKT_STD_RW'], \
                 ['vector<double>',                'ARRAY_1D_SQ_BRKT_STD_RW'], \
                 ['vector<int>',                   'ARRAY_1D_SQ_BRKT_STD_RW'], \
                 ['vector<short>',                 'ARRAY_1D_SQ_BRKT_STD_RW'], \
                 ['vector<bool>',                  'CUSTOM'] ]

################################################################################
## Any classes requiring custom read/write code should be defined here
##
## The signatures for the write and read methods are: 
##    void IOList::write_%s_(string key, ostream & os)
##    void IOList::read_%s_(string key, istream & is)
customWriteCode = {}
customReadCode = {}

customWriteCode['string'] = """
   os << get_string_(key);
   """
customReadCode['string'] = """
   char temp[256];
   string out;
   is >> temp;
   out = string(temp);
   set_string_(key, out);
"""

customWriteCode['vector<bool>'] = """
   vector<bool> const & vb = get_vector_bool_(key);
   int sz = (int)vb.size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << vb[i] << " ";
   """
customReadCode['vector<bool>'] = """
   vector<bool> vb(0);
   int sz, tempInt;
   is >> sz;
   for(int i=0; i<sz; i++) 
   {
      is >> tempInt;
      vb.push_back(tempInt == 1);
   }
   set_vector_bool_(key, vb);
"""


nTypes = len(typelistFull )

typelistType   = [t[0] for t in typelistFull]
typelistRWCode = [t[1] for t in typelistFull]

typelistName = []
for tp in typelistFull :
   t = tp[0]
   t = t.replace('<', '_')
   t = t.replace('>', '_')
   t = t.replace(',', '_')
   t = t.replace(' ', '')
   t = t.strip('_')
   typelistName.append(t)


versionHash = '0000000000000000'
try:
   import hashlib
   versionHash = hashlib.md5('_'.join(typelistType)).hexdigest();
except(ImportError):
   print '***WARNING: hashlib module not present, cannot enable version-checking'



dot_h = open('IOList.h','w')
def h(s, end='\n'):
   dot_h.write(s + end);

nextCode = \
"""
#ifndef _IOLIST_H_
#define _IOLIST_H_

#include <iostream>
#include <fstream>
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
//  so I'm doing this anyway.  A copy of the python is included at the
//  end of this file
//
//  -----------------------------------------------
//  VERSION_HASH:  %s
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
"""

h(nextCode % (versionHash,))


for n in typelistName:
   h('   IOLIST_' + n + ',')


nextCode = \
"""
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

   IOList(void);
   IOLIST_TYPE getType(string key);

   void clearIOList(void);
   void writeIOList(string filename);
   void readIOList(string filename);
   void writeIOList(ostream & os);
   void readIOList(istream & is);

   int size(void) {return (int)key_list_.size();}
   string getVersionHash(void) { return versionHash_; }
   bool compareVersionHash(string hash) { return (hash.compare(versionHash_)==0);}

   void writeKeyList(ostream & os);

private:
"""

h(nextCode)

for T,N in zip(typelistType, typelistName):
   h('   map< string, %s > map_%s_;' % (T,N))
   
   
h('\npublic:')


# Write all the get and set methods
for T,N in zip(typelistType, typelistName):
   nextCode = \
   """   // Enable datatype %s (%s)
   %s const & get_%s_(string key);
   void set_%s_(string key, %s const & val);
   void write_%s_(string key, ostream & os);
   void read_%s_ (string key, istream & is);
   """
   h(nextCode % (N,T, T,N, N,T, N, N))

# Finally close the class declaration
h('};') 
h('#endif')


h('')
h('')
h('// The following is a copy of the python script used to create IOList sources')
h('// The script includes a copy of itself in the header file it creates!')
h('/','')
h('*')

pyfile = open(argv[0],'r');
pyscript = pyfile.readlines()
pyfile.close();
dot_h.writelines(pyscript)
h('')
h('')
h('*','')
h('/')


dot_h.close()



# Now start writing the IOList.cpp file
dot_cpp = open('IOList.cpp','w')
def cpp(s, end='\n'):
   dot_cpp.write(s + end);


nextCode = """
#include "IOList.h"

string IOList::versionHash_ = "%s";

IOLIST_TYPE IOList::getType(string key) 
{
   if(map_types_.find(key) != map_types_.end())
      return map_types_[key];
   else
      return IOLIST_KEY_NOT_EXIST;
}

void IOList::writeKeyList(ostream & os)
{
   for(int i=0; i<(int)key_list_.size(); i++)
   {
      string key = key_list_[i];
      cout << key << " " << map_typename_[key] << endl;
   }
}

IOList::IOList(void)
{
"""

cpp(nextCode % (versionHash,))

for T,N in zip(typelistType, typelistName):
   nextCode = "   map_%s_ = map< string, %s >();"
   cpp(nextCode % (N,T))

cpp("}")

### Method to clear an IOList;
nextCode = \
"""
void IOList::clearIOList(void)
{
   map_types_.clear();
   map_typename_.clear();
   key_list_.clear();
"""
cpp(nextCode)

for T,N in zip(typelistType, typelistName):
   cpp('   map_%s_.clear();' % (N,))

cpp('}')
   

### Method to write an entire IOList to file
nextCode = \
"""
void IOList::writeIOList(string filename)
{
   ofstream os(filename.c_str(), ios::out);
   writeIOList(os);
   os.close();
}
void IOList::writeIOList(ostream & os)
{
   os << "IOLIST_SIZE " << size() << endl;
   for(int i=0; i<(int)size(); i++)
   {
      string key = key_list_[i];
      IOLIST_TYPE theType = map_types_[key];
      os << map_typename_[key] << " " << key << " ";
      switch(theType)
      {
"""
cpp(nextCode)

for T,N in zip(typelistType, typelistName):
   cpp('         case IOLIST_%s: write_%s_(key, os);  break;' % (N,N))

cpp('         default: os << "***ERROR: Key " << key << " not in key_list_!" << endl;')
cpp('      }')
cpp('      os << endl;')
cpp('   }')
cpp('}')


### Method to read an entire IOList from file
nextCode = \
"""
void IOList::readIOList(string filename)
{
   ifstream is(filename.c_str(), ios::in);
   readIOList(is);
   is.close();
}
void IOList::readIOList(istream & is)
{
   clearIOList();

   char deadStr[256];
   char typeStr[256];
   char nameStr[256];
   is >> deadStr;
   
   int sz;
   is >> sz;
   
   for(int i=0; i<sz; i++)
   {
      is >> typeStr;
      is >> nameStr;
      string theType = string(typeStr);
      string theName = string(nameStr);
      
"""
cpp(nextCode)

cpp('      ','')
for T,N in zip(typelistType, typelistName):
   cpp('if( theType.compare("%s") == 0 )' % (N,))
   cpp('         read_%s_(nameStr, is);' % (N,))
   cpp('      else ', '')

cpp('\n         cout << "***ERROR:  Unknown type-string! " << theType << endl;')

cpp('   }')
cpp('}')


### Finally, define all the get/set methods for each datatype
for RWCode, T,N in zip(typelistRWCode, typelistType, typelistName):
   nextCode = """

// Define get/set/write/read methods for %s (%s)
%s const & IOList::get_%s_(string key)
{
   assert(map_%s_.find(key) != map_%s_.end());
   return map_%s_[key];
}
void IOList::set_%s_(string key, %s const & val)
{
   map_%s_[key] = val; 
   map_typename_[key] = "%s";
   map_types_[key] = IOLIST_%s;
   key_list_.push_back(key);
}
void IOList::write_%s_(string key, ostream & os)
{
   %s
}
void IOList::read_%s_(string key, istream & is)
{
   %s
}
   """

   writeCode = ''
   readCode  = ''
   
   if RWCode == 'STD_RW':
      writeCode = "os << get_%s_(key);" % (N,)
      readCode  = \
      """
   %s out;
   is >> out;
   set_%s_(key, out); 
      """ % (T,N)
   elif RWCode == 'ARRAY_1D_SQ_BRKT_STD_RW':
      writeCode = \
      """
   int sz = (int)get_%s_(key).size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << get_%s_(key)[i] << " ";
      """  % (N,N)
      readCode = \
      """
   int sz;
   is >> sz;
   %s out(sz);
   for(int i=0; i<sz; i++)
      is >> out[i];
   set_%s_(key, out);
      """ % (T,N)
   elif RWCode == 'CUSTOM':
      writeCode = customWriteCode[T]
      readCode  = customReadCode[T]
   else:
      print ''
      print '*** ERROR:  UNKONWN RWCode'
      print ''
      exit(0)
      
   cpp(nextCode % (N,T, T,N, N,N,N, N,T, N,N,N, N, writeCode, N, readCode))
      

dot_cpp.close()




*/
