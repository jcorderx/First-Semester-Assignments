/*This program will demonstate how loops, scanf, and printf statement can 
 * used in order to take user input and produce one of three shapes
 * and dimensions based on said input 
 */


#include <stdio.h>

void rectangle();
void triangle();
void hexagon();

int main(void){
	//Variables as described. 
	int height, length, width, stars; 

	int input;
	
	//Variables for continue
	char cont;

	do {
		printf("Please Select One of the following \n"
			"1 for Rectangle \n"
			"2 for Pyramid/Triangle \n"
			"3 for Hexagon \n");

		scanf("%i", &input);
		
		//Switch to select the method
		switch(input){
			case 1:
				rectangle();
				break;			
			case 2:
				triangle();
				break;
			case 3:
				hexagon();
				break;
			default:
				printf("Invalid selection please try again");
				break;
		}	
	
		printf("Do you wish to continue? \n"
			"If not please type 'N'\n"	);
		scanf(" %c", &cont);
	}while((cont != 'N') && (cont != 'n'));


}

void rectangle(){
	int length, width, area;
	int row, column;

	printf("Enter an interger for width: \n");
	scanf("%i", &width);

	printf("\nEnter and interger for length: \n");
	scanf("%i", &length);

	//Prints the top of the rectangle
	for(row = 0; row < width; row++){
		printf("*");
	}
	
	printf("\n");
	//for loop to print the star at the beginning and the end of the row
	for(column = 0; column < length - 2; column++){
		printf("*");
	
		for(row = 0; row < width -2; row++){
			printf(" ");
		}
		printf("*\n");
	}

	//Prints the bottom line of the rectangle
	for(row = 0; row < width; row++){
		printf("*");
	}
	printf("\n");
}

void triangle(){
	int row, star, space;
	int height, column;

	printf("\nPlease Enter an Interger for the Height of the triangle: ");
	scanf("%i", &height);
	
	column = height;

	//loop to print out each row
	for(row = 1; row <= column; row++){
		for (space = 1; space < height; space++){
			printf(" ");
		}

		for(star = 1; star <= row; star++){
			printf("* ");
		}

		printf("\n");
		height = height - 1;
	}
			
}

void hexagon(){
	int row, space, star;
	int middle = 0;
	int count = 0;

	printf("Please Enter the Length for each Side:");
	scanf("%i", &star);

	//prints the firs line of the hexagon
	for(row = star + 1; row > 0; row--){
		printf(" ");
	}

	for(row = 0; row < star; row++){
		printf("*");
	}
	printf("\n");

	//This set of loops print out the top half of the hexagon after the first line
	for(row = 1; row < star; row++){
		for(space = star - count; space > 0; space--){
			printf(" ");
		}
		
		printf("*");
	
		for(space = star + middle; space > 0; space--){
			printf(" ");
		} 
		
		printf("*");
		printf("\n");

		middle += 2;
		count += 1;
		
	}

	//This section of loops handle the bottom have of the hexagon

	for(row = 2; row < star; row++){
		for (space = star - count; space > -2; space--){
			printf(" ");
		}
		printf("*");

		count -= 1;
		middle -= 2;

		for (space = star + middle - 1; space > 1; space--){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}

	//loop for the bottom row
	for(row = star + 1; row > 0; row--){
		printf(" ");
	}
	for(row = 0; row < star; row++){
		printf("*");
	}
	printf("\n");
}

