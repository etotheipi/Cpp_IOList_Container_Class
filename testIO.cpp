#include <iostream>
#include "IOList.h"

using namespace std;

int main(void)
{
   IOList iol;

   cout << "Version Hash: " << iol.getVersionHash() << endl;
   cout << iol.compareVersionHash(iol.getVersionHash()) << endl;
   
   iol.set_float_("someFloat", 1.1f);
   iol.set_int_("someInt", 3);
   iol.set_bool_("falsebool", 1>2); 
   iol.set_bool_("truebool", 1<2); 

   iol.writeKeyList(cout);

   cout << "The first  value is: " << iol.get_float_("someFloat") << endl;
   cout << "The second value is: " << iol.get_int_("someInt") << endl;
   cout << "The third value is: " << iol.get_bool_("falsebool") << endl;
   cout << "The fourth value is: " << iol.get_bool_("truebool") << endl;
   
   cout << "print someFloat ";
   iol.write_float_("someFloat", cout);
   cout << endl;
   
   IOLIST_TYPE type = iol.getType("someFloat");
   cout << "float type: " << (int)type << endl;

   type = iol.getType("someInt");
   cout << "int type: " << (int)type << endl;

   type = iol.getType("DNE");
   cout << "no type: " << (int)type << endl;

   cout << "bool false: " << iol.get_bool_("falsebool") << endl;
   cout << "bool true: " << iol.get_bool_("truebool") << endl;


   return 0;
}
