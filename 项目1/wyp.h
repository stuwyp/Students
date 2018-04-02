struct date
{
	int year;
	int month;
	int day;
};
struct allscore
{
	float pas;
	float math;
	float eng;
};
struct student
{
	char id[12];
	char name[15];
	char gender[7];
	char tel[12];
	char dorm[6];
	char room[6];
	struct date birth;
	struct allscore score;
};

int stu_num();
void printSpaces(int n);
void printSpacesAndLines(int m, int n);

void add();
void exitProgram();
void printStars();
void menu();
void printOneSpace();
void printOneLine();
void printMessage3();
void printMessage1();
void printMessage2();
void mainface();
void interface();

void data(int count);
void sortid(int count);
void sortname(int count);
void findById(int count);
void findByName(int count);
void findByDorm(int count);
void sort(int count, int s);
void findByGender(int count);
void deletedata(int *count);
void correctdata(int *count);

int addStudents();
int delStudents(int t);
int alterStudents(int t);
int findStudents(int t);
int sortStudents();
int printStudentsInfo();
