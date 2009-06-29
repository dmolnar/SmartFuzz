#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

/* Test case Python Issue 1179 */
/* See http://bugs.python.org/issue1179/ */ 

/* Just a placeholder right now. */ 


/* Original code snippet:

	char *cp, *ncp;
 	short *nsp;
 	Py_Int32 *nlp;
	int len, size, x, y, newx1, newx2, newy1, newy2;
 	int ix, iy, xstep, ystep;
 	PyObject *rv;

	if ( len != size*x*y ) {  <======= bug is here 

	 PyErr_SetString(ImageopError, "String has incorrect length");
	 return 0;
 	}
 	xstep = (newx1 < newx2)? 1 : -1;
 	ystep = (newy1 < newy2)? 1 : -1;
*/


int main (int argc, char** argv)
{

  int len, size, x, y, newx1, newx2, newy1, newy2;
  int infile; 

  infile = open(argv[1],O_RDONLY); 


  return 0;
}
