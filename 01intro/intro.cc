#include <iostream>
 using namespace std;

int main(int args, char** argv) {
  int langs;

  cout << "Hello reader.\n" << "Welcome to C++" << endl;

  cout << "How many programming languages have you used? ";
  cin >> langs;

  while (langs >= 0) {
    switch (langs)  {
    case 0:
      cout << "This class may not be for you" << endl;
      break;
    case 1:
      cout << "This class may be challenging" << endl;
  	break;
    case 2:
      cout << "This class will be fun" << endl;
  	break;
    case 3:
      cout << "This class might be interesting" << endl;
  	break;
    default:
      cout << "Easy mode" << endl;
    }
	
    cout << "How many programming languages have you used? ";
    cin >> langs;
  }

  

  return 0;
}
