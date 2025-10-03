#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student_info{
    char name[20];
    char course_code_1[20];
    char course_code_2[20];
    char course_code_3[20];
    char course_code_4[20];
    char course_code_5[20];
    char grade_1;
    char grade_2;
    char grade_3;
    char grade_4;
    char grade_5;
    struct student_info *next;
}*head=NULL;
void add_a_student();
void search_a_student();
void update_student_details();
void delete_a_student();
void display_students();
int main()
{
    while(1)
    {
        int ch;
        printf("Enter your choice:\n1.Insert student details\n2.Search a student\n3.Update student details\n4.Delete a student details\n5.Display all students\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:add_a_student();
            break;
            case 2:search_a_student();
            break;
            case 3:update_student_details();
            break;
            case 4: delete_a_student();
            break;
            case 5:display_students();
            break;
            case 6:return 0;
            break;
            default:printf("Enter a valid choice\n");
        }  
    }  
   
}
void add_a_student()
{
    struct student_info *nn=(struct student_info*)malloc(sizeof(struct student_info));
    char name[20],a[20],b[20],c[20],d[20],e[20];
    char f,g,h,i,j;
    printf("Enter the name of the student:");
    scanf("%s",name);
    strcpy(nn->name,name);
    printf("Enter the course code for course 1:");
    scanf("%s",a);
    strcpy(nn->course_code_1,a);
    printf("Enter the grade for the course %s:",nn->course_code_1);
    scanf(" %c",&f);
    nn->grade_1=f;
    printf("Enter the course code for course 2:");
    scanf("%s",b);
    strcpy(nn->course_code_2,b);
    printf("Enter the grade for the course %s:",nn->course_code_2);
    scanf(" %c",&g);
    nn->grade_2=g;
    printf("Enter the course code for course 3:");
    scanf("%s",c);
    strcpy(nn->course_code_3,c);
    printf("Enter the grade for the course %s:",nn->course_code_3);
    scanf(" %c",&h);
    nn->grade_3=h;
    printf("Enter the course code for course 4:");
    scanf("%s",d);
    strcpy(nn->course_code_4,d);
    printf("Enter the grade for the course %s:",nn->course_code_4);
    scanf(" %c",&i);
    nn->grade_4=i;
    printf("Enter the course code for course 5:");
    scanf("%s",e);
    strcpy(nn->course_code_5,e);
    printf("Enter the grade for the course %s:",nn->course_code_5);
    scanf(" %c",&j);
    nn->grade_5=j;
    printf("Student details added sucessfully!!");
    if(head==NULL)
    {
            head=nn;
            nn->next=NULL;
    }
    else
    {
        struct student_info *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->next=NULL;
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void search_a_student()
{
	if(head==NULL)
	{
		printf("No details present to search student");
	}
	else
	{
		char a[20];
    printf("Enter the name of the student to be searched:");
    scanf("%s",a);
    strlwr(a);
    struct student_info *temp=head;
    int s=0;
    while(temp!=NULL)
    {
      strlwr(temp->name);
      if(strcmp(temp->name,a)==0)
      {
            printf("\nSearched student details are as follows:");
                  printf("\nName->%s",strupr(temp->name));
                  printf("\nCourse code->%s",temp->course_code_1);
                  printf("\nGrade for course %s-> %c",temp->course_code_1,temp->grade_1);
                  printf("\nCourse code->%s",temp->course_code_2);
                  printf("\nGrade for course %s-> %c",temp->course_code_2,temp->grade_2);
                  printf("\nCourse code->%s",temp->course_code_3);
                  printf("\nGrade for course %s-> %c",temp->course_code_3,temp->grade_3);
                  printf("\nCourse code->%s",temp->course_code_4);
                  printf("\nGrade for course %s-> %c",temp->course_code_4,temp->grade_4);
                  printf("\nCourse code->%s",temp->course_code_5);
                  printf("\nGrade for course %s-> %c",temp->course_code_5,temp->grade_5);
                  s=1;
                  break;
            }
      temp=temp->next;
      }
      if(s==0)
      {
      	printf("Entered name not found in the list");
	  }
	}
      printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void update_student_details()
{
	if(head==NULL)
	{
		printf("No student details present to update");
	}
	else
	{
		struct student_info *temp=head;
		printf("Enter the name of the student whose details need to be updated:");
		char t[20];
		scanf("%s",t);
		strlwr(t);
		int w=0,count=0,in=0;
		int cnt=count_nodes();
		while(temp!=NULL)
		{
			strlwr(temp->name);
			if(strcmp(temp->name,t)==0)
			{
				w=1;
				break;
			}			
			count++;
			temp=temp->next;
	}
	in=count+1;
	if(in==1)
	{
		struct student_info *a=head;
		head=a->next;
		free(a);
	}
	else if(in==cnt)
	{
		struct student_info *b=head->next,*c=head;
		while(b->next!=NULL)
		{
			b=b->next;
			c=c->next;
		}
		c->next=NULL;
		free(b);
	}
	else
	{
		struct student_info *d=head->next,*e=head;
		int i=0;
		while(i!=in-2)
		{
			i++;
			d=d->next;
			e=e->next;
		}
		e->next=d->next;
		free(d);
	}
	if(w==0)
	{
		printf("Entered name not found in the list");
	}
	struct student_info *nn=(struct student_info*)malloc(sizeof(struct student_info));
    char name[20],a[20],b[20],c[20],d[20],e[20];
    char f,g,h,i,j;
    printf("Enter the name of the student:");
    scanf("%s",name);
    strcpy(nn->name,name);
    printf("Enter the course code for course 1:");
    scanf("%s",a);
    strcpy(nn->course_code_1,a);
    printf("Enter the grade for the course %s:",nn->course_code_1);
    scanf(" %c",&f);
    nn->grade_1=f;
    printf("Enter the course code for course 2:");
    scanf("%s",b);
    strcpy(nn->course_code_2,b);
    printf("Enter the grade for the course %s:",nn->course_code_2);
    scanf(" %c",&g);
    nn->grade_2=g;
    printf("Enter the course code for course 3:");
    scanf("%s",c);
    strcpy(nn->course_code_3,c);
    printf("Enter the grade for the course %s:",nn->course_code_3);
    scanf(" %c",&h);
    nn->grade_3=h;
    printf("Enter the course code for course 4:");
    scanf("%s",d);
    strcpy(nn->course_code_4,d);
    printf("Enter the grade for the course %s:",nn->course_code_4);
    scanf(" %c",&i);
    nn->grade_4=i;
    printf("Enter the course code for course 5:");
    scanf("%s",e);
    strcpy(nn->course_code_5,e);
    printf("Enter the grade for the course %s:",nn->course_code_5);
    scanf(" %c",&j);
    nn->grade_5=j;
    if(in==1)
    {
    	head=nn;
    	nn->next=NULL;
    	printf("Student details updated sucessfully");
	}
	else if(in==cnt)
	{
		struct student_info *temp1=head;
		while(temp1->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
		nn->next=NULL;
		printf("Student details updated sucessfully");
	}
	else
	{
		struct student_info *temp2=head,*temp3=head->next;
		int j=0;
		while(j!=in-2)
		{
			j++;
			temp3=temp3->next;
			temp2=temp2->next;
		}
		temp2->next=nn;
		nn->next=temp3;
		printf("Student details updated sucessfully");
	}
	
      printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
      }
void delete_a_student()
{
	if(head==NULL)
	{
		printf("No students present in te list to delete!!");
	}
else
{
	struct student_info *temp=head;
	printf("Enter the name to be deleted:");
	char t[20];
	scanf("%s",t);
	strlwr(t);
	int w=0,count=0,in=0;
	int cnt=count_nodes();
			while(temp!=NULL)
			{
				strlwr(temp->name);
				if(strcmp(temp->name,t)==0)
					{
						w=1;
						break;
					}			
					count++;
					temp=temp->next;
	}
	in=count+1;
	if(in==1)
	{
		struct student_info *a=head;
		head=a->next;
		free(a);
		printf("Details deleted sucessfully!!");
	}
	else if(in==cnt)
	{
		struct student_info *b=head->next,*c=head;
		while(b->next!=NULL)
		{
			b=b->next;
			c=c->next;
		}
		c->next=NULL;
		free(b);
		printf("Details deleted sucessfully!!");
	}
	else
	{
		struct student_info *d=head->next,*e=head;
		int i=0;
		while(i!=in-2)
		{
			i++;
			d=d->next;
			e=e->next;
		}
		e->next=d->next;
		free(d);
		printf("Details deleted sucessfully!!");
	}
	if(w==0)
	{
		printf("Entered name not found in the list");
	}

}
printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void display_students()
{
    struct student_info *temp=head;
    if(head==NULL)
    {
        printf("No students in the list!!");
    }
    else
    {
    	int i;
        while(temp!=NULL)
        {
            printf("Name:%s",strupr(temp->name));
            printf("\n");
            printf("Course 1:%s->Grade: %c",temp->course_code_1,temp->grade_1);
            printf("\n");
            printf("Course 2:%s->Grade: %c",temp->course_code_2,temp->grade_2);
            printf("\n");
            printf("Course 3:%s->Grade: %c",temp->course_code_3,temp->grade_3);
            printf("\n");
            printf("Course 4:%s->Grade: %c",temp->course_code_4,temp->grade_4);
            printf("\n");
            printf("Course 5:%s->Grade: %c",temp->course_code_5,temp->grade_5);
            printf("\n");
            temp=temp->next;
        }
    }
   printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
int count_nodes()
{
	int c=0;
	struct student_info *temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

