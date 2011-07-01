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

   vector<int> vi(5);
   for(int i=0; i<5; i++)
      vi[i] = 3*i + 32;

   iol.set_vector_int_("list5", vi);

   cout << endl;
   iol.writeKeyList(cout);

   cout << endl;
   cout << "The first  value is: " << iol.get_float_("someFloat") << endl;
   cout << "The second value is: " << iol.get_int_("someInt") << endl;
   cout << "The third value is: " << iol.get_bool_("falsebool") << endl;
   cout << "The fourth value is: " << iol.get_bool_("truebool") << endl;
   cout << "The fifth value is: ";
   iol.write_vector_int_("list5", cout);
   cout << endl;
   
   cout << endl;
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

   cout << endl << endl << endl;
   cout << "Testing writeIOList method!" << endl << endl;

   iol.writeIOList(cout);
   
   cout << endl << endl << endl;
   cout << "Testing writing list to file" << endl << endl;

   iol.writeIOList("IOListToFile.txt");

   IOList iol2;
   iol2.readIOList("IOListToFile.txt");

   iol2.writeIOList(cout);


   return 0;
}
