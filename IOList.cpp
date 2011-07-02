
#include "IOList.h"


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

   map_float_ = map< string, float >();
   map_double_ = map< string, double >();
   map_int_ = map< string, int >();
   map_short_ = map< string, short >();
   map_bool_ = map< string, bool >();
   map_string_ = map< string, string >();
   map_vector_float_ = map< string, vector<float> >();
   map_vector_double_ = map< string, vector<double> >();
   map_vector_int_ = map< string, vector<int> >();
   map_vector_short_ = map< string, vector<short> >();
   map_vector_bool_ = map< string, vector<bool> >();
}

IOList::IOList(string filename)
{

   map_float_ = map< string, float >();
   map_double_ = map< string, double >();
   map_int_ = map< string, int >();
   map_short_ = map< string, short >();
   map_bool_ = map< string, bool >();
   map_string_ = map< string, string >();
   map_vector_float_ = map< string, vector<float> >();
   map_vector_double_ = map< string, vector<double> >();
   map_vector_int_ = map< string, vector<int> >();
   map_vector_short_ = map< string, vector<short> >();
   map_vector_bool_ = map< string, vector<bool> >();
   readIOList(filename);
}

void IOList::clearIOList(void)
{
   map_types_.clear();
   map_typename_.clear();
   key_list_.clear();

   map_float_.clear();
   map_double_.clear();
   map_int_.clear();
   map_short_.clear();
   map_bool_.clear();
   map_string_.clear();
   map_vector_float_.clear();
   map_vector_double_.clear();
   map_vector_int_.clear();
   map_vector_short_.clear();
   map_vector_bool_.clear();
}

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

         case IOLIST_float: write_float_(key, os);  break;
         case IOLIST_double: write_double_(key, os);  break;
         case IOLIST_int: write_int_(key, os);  break;
         case IOLIST_short: write_short_(key, os);  break;
         case IOLIST_bool: write_bool_(key, os);  break;
         case IOLIST_string: write_string_(key, os);  break;
         case IOLIST_vector_float: write_vector_float_(key, os);  break;
         case IOLIST_vector_double: write_vector_double_(key, os);  break;
         case IOLIST_vector_int: write_vector_int_(key, os);  break;
         case IOLIST_vector_short: write_vector_short_(key, os);  break;
         case IOLIST_vector_bool: write_vector_bool_(key, os);  break;
         default: os << "***ERROR: Key " << key << " not in key_list_!" << endl;
      }
      os << endl;
   }
}

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
      

      if( theType.compare("float") == 0 )
         read_float_(nameStr, is);
      else if( theType.compare("double") == 0 )
         read_double_(nameStr, is);
      else if( theType.compare("int") == 0 )
         read_int_(nameStr, is);
      else if( theType.compare("short") == 0 )
         read_short_(nameStr, is);
      else if( theType.compare("bool") == 0 )
         read_bool_(nameStr, is);
      else if( theType.compare("string") == 0 )
         read_string_(nameStr, is);
      else if( theType.compare("vector_float") == 0 )
         read_vector_float_(nameStr, is);
      else if( theType.compare("vector_double") == 0 )
         read_vector_double_(nameStr, is);
      else if( theType.compare("vector_int") == 0 )
         read_vector_int_(nameStr, is);
      else if( theType.compare("vector_short") == 0 )
         read_vector_short_(nameStr, is);
      else if( theType.compare("vector_bool") == 0 )
         read_vector_bool_(nameStr, is);
      else 
         cout << "***ERROR:  Unknown type-string! " << theType << endl;
   }
}


// Define get/set/write/read methods for float (float)
float const & IOList::get_float_(string key)
{
   assert(map_float_.find(key) != map_float_.end());
   return map_float_[key];
}
void IOList::set_float_(string key, float const & val)
{
   map_float_[key] = val; 
   map_typename_[key] = "float";
   map_types_[key] = IOLIST_float;
   key_list_.push_back(key);
}
void IOList::write_float_(string key, ostream & os)
{
   os << get_float_(key);
}
void IOList::read_float_(string key, istream & is)
{
   
   float out;
   is >> out;
   set_float_(key, out); 
      
}
   


// Define get/set/write/read methods for double (double)
double const & IOList::get_double_(string key)
{
   assert(map_double_.find(key) != map_double_.end());
   return map_double_[key];
}
void IOList::set_double_(string key, double const & val)
{
   map_double_[key] = val; 
   map_typename_[key] = "double";
   map_types_[key] = IOLIST_double;
   key_list_.push_back(key);
}
void IOList::write_double_(string key, ostream & os)
{
   os << get_double_(key);
}
void IOList::read_double_(string key, istream & is)
{
   
   double out;
   is >> out;
   set_double_(key, out); 
      
}
   


// Define get/set/write/read methods for int (int)
int const & IOList::get_int_(string key)
{
   assert(map_int_.find(key) != map_int_.end());
   return map_int_[key];
}
void IOList::set_int_(string key, int const & val)
{
   map_int_[key] = val; 
   map_typename_[key] = "int";
   map_types_[key] = IOLIST_int;
   key_list_.push_back(key);
}
void IOList::write_int_(string key, ostream & os)
{
   os << get_int_(key);
}
void IOList::read_int_(string key, istream & is)
{
   
   int out;
   is >> out;
   set_int_(key, out); 
      
}
   


// Define get/set/write/read methods for short (short)
short const & IOList::get_short_(string key)
{
   assert(map_short_.find(key) != map_short_.end());
   return map_short_[key];
}
void IOList::set_short_(string key, short const & val)
{
   map_short_[key] = val; 
   map_typename_[key] = "short";
   map_types_[key] = IOLIST_short;
   key_list_.push_back(key);
}
void IOList::write_short_(string key, ostream & os)
{
   os << get_short_(key);
}
void IOList::read_short_(string key, istream & is)
{
   
   short out;
   is >> out;
   set_short_(key, out); 
      
}
   


// Define get/set/write/read methods for bool (bool)
bool const & IOList::get_bool_(string key)
{
   assert(map_bool_.find(key) != map_bool_.end());
   return map_bool_[key];
}
void IOList::set_bool_(string key, bool const & val)
{
   map_bool_[key] = val; 
   map_typename_[key] = "bool";
   map_types_[key] = IOLIST_bool;
   key_list_.push_back(key);
}
void IOList::write_bool_(string key, ostream & os)
{
   os << get_bool_(key);
}
void IOList::read_bool_(string key, istream & is)
{
   
   bool out;
   is >> out;
   set_bool_(key, out); 
      
}
   


// Define get/set/write/read methods for string (string)
string const & IOList::get_string_(string key)
{
   assert(map_string_.find(key) != map_string_.end());
   return map_string_[key];
}
void IOList::set_string_(string key, string const & val)
{
   map_string_[key] = val; 
   map_typename_[key] = "string";
   map_types_[key] = IOLIST_string;
   key_list_.push_back(key);
}
void IOList::write_string_(string key, ostream & os)
{
   
   os << get_string_(key);
   
}
void IOList::read_string_(string key, istream & is)
{
   
   char temp[256];
   string out;
   is >> temp;
   out = string(temp);
   set_string_(key, out);

}
   


// Define get/set/write/read methods for vector_float (vector<float>)
vector<float> const & IOList::get_vector_float_(string key)
{
   assert(map_vector_float_.find(key) != map_vector_float_.end());
   return map_vector_float_[key];
}
void IOList::set_vector_float_(string key, vector<float> const & val)
{
   map_vector_float_[key] = val; 
   map_typename_[key] = "vector_float";
   map_types_[key] = IOLIST_vector_float;
   key_list_.push_back(key);
}
void IOList::write_vector_float_(string key, ostream & os)
{
   
   int sz = (int)get_vector_float_(key).size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << get_vector_float_(key)[i] << " ";
      
}
void IOList::read_vector_float_(string key, istream & is)
{
   
   int sz;
   is >> sz;
   vector<float> out(sz);
   for(int i=0; i<sz; i++)
      is >> out[i];
   set_vector_float_(key, out);
      
}
   


// Define get/set/write/read methods for vector_double (vector<double>)
vector<double> const & IOList::get_vector_double_(string key)
{
   assert(map_vector_double_.find(key) != map_vector_double_.end());
   return map_vector_double_[key];
}
void IOList::set_vector_double_(string key, vector<double> const & val)
{
   map_vector_double_[key] = val; 
   map_typename_[key] = "vector_double";
   map_types_[key] = IOLIST_vector_double;
   key_list_.push_back(key);
}
void IOList::write_vector_double_(string key, ostream & os)
{
   
   int sz = (int)get_vector_double_(key).size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << get_vector_double_(key)[i] << " ";
      
}
void IOList::read_vector_double_(string key, istream & is)
{
   
   int sz;
   is >> sz;
   vector<double> out(sz);
   for(int i=0; i<sz; i++)
      is >> out[i];
   set_vector_double_(key, out);
      
}
   


// Define get/set/write/read methods for vector_int (vector<int>)
vector<int> const & IOList::get_vector_int_(string key)
{
   assert(map_vector_int_.find(key) != map_vector_int_.end());
   return map_vector_int_[key];
}
void IOList::set_vector_int_(string key, vector<int> const & val)
{
   map_vector_int_[key] = val; 
   map_typename_[key] = "vector_int";
   map_types_[key] = IOLIST_vector_int;
   key_list_.push_back(key);
}
void IOList::write_vector_int_(string key, ostream & os)
{
   
   int sz = (int)get_vector_int_(key).size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << get_vector_int_(key)[i] << " ";
      
}
void IOList::read_vector_int_(string key, istream & is)
{
   
   int sz;
   is >> sz;
   vector<int> out(sz);
   for(int i=0; i<sz; i++)
      is >> out[i];
   set_vector_int_(key, out);
      
}
   


// Define get/set/write/read methods for vector_short (vector<short>)
vector<short> const & IOList::get_vector_short_(string key)
{
   assert(map_vector_short_.find(key) != map_vector_short_.end());
   return map_vector_short_[key];
}
void IOList::set_vector_short_(string key, vector<short> const & val)
{
   map_vector_short_[key] = val; 
   map_typename_[key] = "vector_short";
   map_types_[key] = IOLIST_vector_short;
   key_list_.push_back(key);
}
void IOList::write_vector_short_(string key, ostream & os)
{
   
   int sz = (int)get_vector_short_(key).size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << get_vector_short_(key)[i] << " ";
      
}
void IOList::read_vector_short_(string key, istream & is)
{
   
   int sz;
   is >> sz;
   vector<short> out(sz);
   for(int i=0; i<sz; i++)
      is >> out[i];
   set_vector_short_(key, out);
      
}
   


// Define get/set/write/read methods for vector_bool (vector<bool>)
vector<bool> const & IOList::get_vector_bool_(string key)
{
   assert(map_vector_bool_.find(key) != map_vector_bool_.end());
   return map_vector_bool_[key];
}
void IOList::set_vector_bool_(string key, vector<bool> const & val)
{
   map_vector_bool_[key] = val; 
   map_typename_[key] = "vector_bool";
   map_types_[key] = IOLIST_vector_bool;
   key_list_.push_back(key);
}
void IOList::write_vector_bool_(string key, ostream & os)
{
   
   vector<bool> const & vb = get_vector_bool_(key);
   int sz = (int)vb.size();
   os << sz << " ";
   for(int i=0; i<sz; i++)
      os << vb[i] << " ";
   
}
void IOList::read_vector_bool_(string key, istream & is)
{
   
   vector<bool> vb(0);
   int sz, tempInt;
   is >> sz;
   for(int i=0; i<sz; i++) 
   {
      is >> tempInt;
      vb.push_back(tempInt == 1);
   }
   set_vector_bool_(key, vb);

}
   
