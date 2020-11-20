#include <stdio.h>
#include <string.h>

#define MAX 10 // constant for maximum number of students

void comp_chars(int what_student, const char* correct_str, const char* comp_str, int* correct, int* wrong);
void print_results(const int max, const int* ids, const int* correct_answers, const int* wrong_answers, const char* answers); 

int main(void) {
	// Setup and Variable Declarations
	// Storage for ID's, #correct, #wrong, setting all values to 0 initially
	int id_array[MAX] = {[0 ... MAX-1] = 0};
	int num_correct[MAX] = {[0 ... MAX-1] = 0};
	int num_wrong[MAX] = {[0 ... MAX-1] = 0};
	int id, num_questions, i = 0; // int storage variables

	// Read the first line
	scanf("%d", &num_questions);                                       // grab how large the strings need to be
	num_questions++;                                                   // make space for the \0 char
	char str[num_questions], correct_string[num_questions];            // create the strings
	char answers_array[MAX][num_questions];                            // array of strings for comparison later
	scanf("%s", correct_string);                                       // save the correct answers

	// Read in the data from standard in
	while(scanf("%d %s", &id, str) == 2) {                             // so long as scanf finds two things to read
		id_array[i] = id;                                          // set the id to index i
		strcpy(answers_array[i++], str);                           // retrieve the answers
	}
	for(int j = 0; j < i; j++) { 		                           // compare the characters of the answers given and the correct ones
		comp_chars(j, correct_string, answers_array[j], num_correct, num_wrong);
	}

	// Output
	print_results(i, id_array, num_correct, num_wrong, correct_string);
	return 0;
}

void print_results(const int max, const int* ids, const int* correct_answers, const int* wrong_answers, const char* answers) {
	int x = strlen(answers);                                           // calculation made over and over
	// Print off the correct answers
	printf("Question:  ");
	for(int i = 0; i < x; i++)
		printf("%d  ", i+1);
	printf("\nAnswers:   ");
	for(int i = 0; i < x; i++)
		printf("%c  ", answers[i]);
	printf("\n");
	// Print off the student's grades
	printf("ID\tGrade(%%)\n");
	for(int i = 0; i < max; i++) {
		printf("%d:\t%.2lf\n", ids[i], (double)correct_answers[i]/strlen(answers)*100.0);
	}
	// Print off how many people missed each question
	printf("Question:   ");
	for(int i = 0; i < x; i++)
		printf("%d  ", i+1);
	printf("\nMissed by:  ");
	for(int i = 0; i < x; i++)
		printf("%d  ", wrong_answers[i]);
	printf("\n");
}

void comp_chars(int what_student, const char* correct_str, const char* comp_str, int* correct, int* wrong) {
	for(int i = 0; i < strlen(comp_str); i++) {                      // for each character in the string
		if(correct_str[i] == comp_str[i])                        // if they are both the same
			correct[what_student]++;                         // add one to the correct count
		else
			wrong[i]++;		                         // otherwise add one to the wrong count
	}
}
