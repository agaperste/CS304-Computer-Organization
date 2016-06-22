// Complete the following setName, getStudentID, and setStudentID functions. 
//You may assume the pointers given are valid and not null.

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>

#define MAX_NAME_LEN 127
typedef struct {
    char name[MAX_NAME_LEN + 1];
    unsigned long sid;
} Student;

/* return the name of student s */
const char* getName (const Student* s) {
    return s->name;
}

/* set the name of student s
If name is too long, cut off characters after the maximum number of characters allowed.
*/
void setName(Student* s, const char* name) {
	strncpy(s->name, name, MAX_NAME_LEN);
    s->name[MAX_NAME_LEN] = '\0';
}

/* return the SID of student s */
unsigned long getStudentID(const Student* s) {
	return s->sid;
}

/* set the SID of student s */
void setStudentID(Student* s, unsigned long sid) {
	s->sid = sid;
}

void makeAndrew(Student *s) {
    setName( s, "Andrew");
    setStudentID( s, 12345678);
}

int main(int argc, char const *argv[])
{
	Student s;
	makeAndrew(&s);
	printf("%s %lu\n", getName(&s), getStudentID(&s));
	return 0;
}