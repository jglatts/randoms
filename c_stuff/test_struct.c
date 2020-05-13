#include <stdio.h>
#include <string.h>

typedef struct TestStruct {
	int checked;
	double checked_d;
	char name[50];
} TestStruct;

typedef struct Player {
	char name[50];
	int rank;
	int is_alive;
	float health;
} Player;

TestStruct* make_new_struct(int i, double d, char c[]);
void test_struct(void);
void check_struct(TestStruct* p);
void play_game(void);


int main(void) {
	test_struct();
	return 0;
}

TestStruct* make_new_struct(int i, double d, char c[]) {
	TestStruct* out = (TestStruct*)malloc(sizeof(TestStruct));
	out->checked = i;
	out->checked_d = d;
	for (int i = 0; i < strlen(c); ++i) out->name[i] = c[i];
	return out;
}

void test_struct(void) {
	TestStruct* ts = make_new_struct(69, 420.26, "ogmudbone");
	printf("User Name: %s\nValue of Struct: %d\nValue of Struct: %f\nAddress: %p\n", ts->name, ts->checked, ts->checked_d, ts);
	/*
	TestStruct* ts = (TestStruct*)malloc(sizeof(TestStruct));
	ts->checked = 420;
	ts->checked_d = 69.69;
	printf("Please Enter Name...");
	scanf("%s", ts->name);
	check_struct(ts);
	*/
}

void check_struct(TestStruct* p) {
	printf("User Name: %s\nValue of Struct: %d\nValue of Struct: %f\nAddress: %p\n", p->name, p->checked, p->checked_d, p);
	p->checked = 26;
	p->checked_d = 1958.58;
	printf("\nUser Name: %s\nValue of Struct: %d\nValue of Struct: %f\nAddress: %p\n", p->name, p->checked, p->checked_d, p);
}	

void play_game(void) {
	// run a loop here 
	// while player->is_alive ...

}
