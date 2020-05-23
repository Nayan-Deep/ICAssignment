//NOTE: All the parts of question 1 are combined in this single program.
//CODE BY: nayan
#include<stdio.h>
struct studentRecord
{
 int roll_no;
 char name[20], address[40];
 float subject1_marks, subject2_marks, subject3_marks;
};
//////////////FUNC. DECLARE///////////////////////
void enter(struct studentRecord student[10]);
void display(struct studentRecord student[10], int a);
void display1to5(struct studentRecord student[10]);
void displayMaxSub1(struct studentRecord student[10]);
void displayMaxTotal(struct studentRecord student[10]);
void displayNameA(struct studentRecord student[10]);
void displayAsc(struct studentRecord student[10]);
//////////////MAIN FUNC.///////////////////////
int main()
{ struct studentRecord student[10];
  int n;
  enter(student);
  printf("\n1.Sol a\n1.Sol b\n1.Sol c\n1.Sol d\n1.Sol e\nEnter Choice: ");
  scanf("%d", &n);
  switch(n)
   { case 1: display1to5(student);      //sol a
             break;
     case 2: displayMaxSub1(student);   //sol b
             break;
     case 3: displayMaxTotal(student);   //sol c
             break;
     case 4: displayNameA(student);   //sol d
             break;
     case 5: displayAsc(student);   //sol e
             break;
    default: printf("Invalid Choice");
             break;
   }
  return 0;
}
///////////////////DISPLAY////////////////////////
void display(struct studentRecord student[10], int a)
{
  printf("\n\nSTUDENT %d", a+1);
  printf("\nRoll no.: %d", student[a].roll_no);
  printf("\nName: %s", student[a].name);
  printf("\nAddress: %s", student[a].address);
  printf("\nSubject 1 Marks: %f", student[a].subject1_marks);
  printf("\nSubject 2 Marks: %f", student[a].subject2_marks);
  printf("\nSubject 3 Marks: %f", student[a].subject3_marks);
}
///////////////ENTER////////////////////
void enter(struct studentRecord student[10])
{ int i;
	for(i=0;i<10;i++)
	{
	  printf("\n\nSTUDENT %d", i+1);
	  printf("\nRoll no.: ");
	  scanf("%d", &student[i].roll_no);
	  printf("Name: ");
	  scanf("%s", &student[i].name);
    printf("Address: ");
	  scanf("%s", &student[i].address);
    printf("Subject 1 Marks: ");
    scanf("%f", &student[i].subject1_marks);
    printf("Subject 2 Marks: ");
    scanf("%f", &student[i].subject2_marks);
    printf("Subject 3 Marks: ");
    scanf("%f", &student[i].subject3_marks);
	}
}
///////////////////FUNC1////////////////////////
void display1to5(struct studentRecord student[10])
{ int i;
	for(i=0;i<10;i++)
	{ if(student[i].roll_no<5 && student[i].roll_no>1)
     display(student, i);
	}
}
///////////////////FUNC2////////////////////////
void displayMaxSub1(struct studentRecord student[10])
{ int i;
  float max = 0;
	for(i=0;i<10;i++)
	{ if(student[i].subject1_marks>max)
	    max = student[i].subject1_marks;
	}
	for(i=0;i<10;i++)
	{ if(student[i].subject1_marks == max)
    display(student, i);
	}
}
///////////////////FUNC3////////////////////////
void displayMaxTotal(struct studentRecord student[10])
{ int i;
  float max = 0;
	for(i=0;i<10;i++)
	{ if((student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks) > max)
	    max = student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks;
	}
	for(i=0;i<10;i++)
	{ if(student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks == max)
    display(student, i);
	}
}
///////////////////FUNC4////////////////////////
void displayNameA(struct studentRecord student[10])
{ int i;
	for(i=0;i<10;i++)
	{ if(student[i].name[0] == 'A' || student[i].name[0] == 'a')
    display(student, i);
	}
}
///////////////////FUNC5////////////////////////
void displayAsc(struct studentRecord student[10])
{
  int A[10],i,j,b,sum;
  for(i=0;i<10;i++)
  {
    A[i] = (student[i].subject1_marks + student[i].subject2_marks + student[i].subject3_marks);
  }

  for(i=0;i<10;i++)
  {
    for(j=i+1; j<10; j++)
    {
      if(A[i] > A[j])
      {
	b = A[i];
	A[i] = A[j];
	A[j] = b;
      }
    }
  }

  for(i=0;i<10;i++)
  {
    for(j=0;j<10;j++)
    {
      if(A[i] == student[j].subject1_marks + student[j].subject2_marks + student[j].subject3_marks)
        display(student, j);
    }
  }
}
