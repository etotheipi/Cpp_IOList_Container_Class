
#include "IOList.h"

string IOList::versionHash_ = "aeba7045b138314589763e9731157c6e";

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



// Define get/set/write/read methods for float (float)
float IOList::get_float_(string key)
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
double IOList::get_double_(string key)
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
int IOList::get_int_(string key)
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
short IOList::get_short_(string key)
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
bool IOList::get_bool_(string key)
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
string IOList::get_string_(string key)
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
   // TODO: ADD CODE FOR READING string OBJECTS FROM FILE

}
void IOList::read_string_(string key, istream & is)
{
   // TODO: ADD CODE FOR READING string OBJECTS FROM FILE

}
   


// Define get/set/write/read methods for vector_float (vector<float>)
vector<float> IOList::get_vector_float_(string key)
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
vector<double> IOList::get_vector_double_(string key)
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
vector<int> IOList::get_vector_int_(string key)
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
vector<short> IOList::get_vector_short_(string key)
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
vector<bool> IOList::get_vector_bool_(string key)
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
   // TODO: ADD CODE FOR READING vector<bool> OBJECTS FROM FILE

}
void IOList::read_vector_bool_(string key, istream & is)
{
   // TODO: ADD CODE FOR READING vector<bool> OBJECTS FROM FILE

}
   
