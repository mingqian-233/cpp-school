#include <iostream>

using namespace std;

 

int main()

{

        int row; // the row position

        int column; // the column position

        int space; // number of spaces to print

        

        // first triangle

        /* Write a for header to iterate row from 1 to 10 */

        {

                /* Write a for header to iterate column from 1 to row */

                cout << "*";

                

                cout << endl;

        } // end for

        

        cout << endl;

        

        // second triangle

        /* Write a for header to iterate row from 10 down to 1 */

        {

                /* Write a for header to iterate column from 1 to row */

                cout << "*";

                

                cout << endl;

        } // end for

        

        cout << endl;

        

        // third triangle

        /* Write a for header to iterate row from 10 down to 1 */

        {

                /* Write a for header to iterate space from 10 down to one more than row */

                cout << " ";

                

                /* Write a for header to iterate column from 1 to row */

                cout << "*";

                

                cout << endl;

        } // end for

        

        cout << endl;

        

        // fourth triangle

        /* Write a for header to iterate row from 10 down to 1 */

        {

                /* Write a for header to iterate space from 1 to one less than row */

                cout << " ";

                

                /* Write a for header to iterate column from 10 down to row */

                cout << "*";

                

                cout << endl;

        } // end for

} // end main