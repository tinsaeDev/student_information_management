






// This code is tested on borland v5 on windows 7 and windows 10
// yet not tested on windows XP or lower and windows 8 and 8.1










/*

Some non c++ code is embended inside this programe to make it more easy to and productive.

1.HTML (including CSS) - we embended this language in our programe to create HTML report card ( Transcripts )

2.DOS - we embended this language to create folder, move files and delete files and other file management

3.javaScript - we added this code inside HTML to automate the printing procces

4. Visual Basic Script - using this scripting language we are able to add message box and text to speech feature to our programe

5. The core of programe is C++, The programme accepts data, calculate total,average and rank using c++

>>> The embeded codes are included only to increase UI feature
>>> Without the programe can function properly.

*/



#include <iostream.h> //
#include <stdlib.h> // to use system function
#include <fstream.h>  // to create files
#include <string.h> // to manipulate strings
#include <iomanip.h>  // to manipulate outputs
#include <conio.h>  // to use get function
#include <time.h>    // to use time




void splash();// program start up screen
void confirm_data(); // confirms user data
void display_result(); // Display result to user
void read_registrar_info(); // Read the information of registrar
void calculate_total(); // find the total mark value for each student
void calculate_rank(); // find a rank for all students
void calculate_average();// calculates average mark for all students
void read_student_data(int); // read student personal and academic info
void create_html(int,bool); //  creates HTML report for one student At one instance of call
void read_course_name();    // read a name for all courses
void num_couse_error();    // used to re accept the number of course and student if the user wants to modify
void set_screen(); /* used for


        1. clearing the screen
        2. set the console width
        3. put the header "Student information system"
        4. Change console title to "Student information system"


*/
void input_error_message(); // used to display an error box message if invalid input is given


char role_of_user[100]; // used to store the role of a person registering the mark of students
char faculty_name[100];//  used to store the faculty name
char users_name[100]; //   used  to store name of a person registering students mark
char department_name[100];// hold the name of department the students are enrolled in
char organization_name[100];// used to store a name of organization the system is for
int number_of_student; // hold the number of students
int number_of_course; // hold the number of course
char course_name[20][30]; //hold the name for all courses




struct students{ //Creating Structure

char name[80]; // student name
int age; // student age
char sex; // student sex
char id[15]; // student ID
float mark[20];// course mark for 20 courses
float total; // total mark of student
float average; // average mark of student
int rank; // student rank

}student[200];// Creating structure variable for 200 students;


int main(){// Program execution starts from here


                 splash();
                 set_screen();
                 read_registrar_info();
                 set_screen();


    num_student_error:// if a non valid input is give a program returns to this label

    cout<<"Number of Student:\t";
    ofstream sound; // creating a VB Script  file to use windows sound API
    sound.open("sound.vbs"); // creating file
    sound<<"dim sapi\n";     // A non c++ code  (VB script code)
    sound<<"set sapi=CreateObject(\"sapi.spvoice\")\n";// A non c++ code (VB script code)
    sound<<"sapi.Speak \"enter Number of Students\"";// A non c++ code (VB script code)
    sound.close(); // closing file
    system("call sound.vbs"); // opening created file (call is not a c++ code, it is a DOS Command)
    cin>>number_of_student;



 if(number_of_student<=0) { //executes if number of students is less than 1

    ofstream soundcd;
    soundcd.open("sound.vbs");
    soundcd<<"dim sapi\n";// A non c++ code (VB script code)
    soundcd<<"set sapi=CreateObject(\"sapi.spvoice\")\n";// A non c++ code (VB script code)
    soundcd<<"sapi.Speak \"Input error! enter only whole number\"";// A non c++ code (VB script code)
    soundcd.close();
    system("start/min sound.vbs");// opening created file with its default program (DOS code)
    input_error_message();
    goto num_student_error;

                         }


set_screen();


num_course_error: // the program will return here if number of course is less than 1

    cout<<"Number of Course:\t";
    ofstream sound1;
    sound1.open("sound.vbs");
    sound1<<"dim sapi\n";// A non c++ code (VB script code)
    sound1<<"set sapi=CreateObject(\"sapi.spvoice\")\n";// A non c++ code (VB script code)
    sound1<<"sapi.Speak \"enter Number of course\"";// A non c++ code (VB script code)
    sound1.close();
    system("call sound.vbs");
    cin>>number_of_course;




   if(number_of_course<1){// executes if number of course entered  is less than 1



    cout<<"Number of Course:\t";
    ofstream soundcc;
    soundcc.open("sound.vbs");
    soundcc<<"dim sapi\n";// A non c++ code (VB script code)
    soundcc<<"set sapi=CreateObject(\"sapi.spvoice\")\n";// A non c++ code (VB script code)
    soundcc<<"sapi.Speak \"Input error! please inter only a whole number\"";// A non c++ code (VB script code)
    soundcc.close();
    system("start/min sound.vbs");

    input_error_message();

goto num_course_error;

}


                set_screen();

                read_course_name();

                set_screen();


  for(int i=0;i<=number_of_student-1;i++){// iterate for number of student to accept data for all students


    ofstream sound2;
    sound2.open("sound.vbs");

    sound2<<"dim sapi\n"; // a VB Script code to pronounce a text
    sound2<<"set sapi=CreateObject(\"sapi.spvoice\")\n"; // a VB Script code to pronounce a text
    sound2<<"sapi.Speak \"Please enter data of student "<<(i+1)<<" \""; // a VB Script code to pronounce a text
    sound2.close();
    system("call sound.vbs"); //opening a created file
    read_student_data(i); // sending index of student to read data of student
    set_screen();
}
                 confirm_data();
                 calculate_total();
                 calculate_average();
                 calculate_rank();
                 set_screen();

   cout<<setw(80)<<setfill(' ')<<"All done! do you want an HTML report for all students\?(Y/N)\n\n";


    ofstream sound3;
    sound3.open("sound.vbs");

    sound3<<"dim sapi\n"; // a VB Script code to pronounce a text
    sound3<<"set sapi=CreateObject(\"sapi.spvoice\")\n"; // a VB Script code to pronounce a text
    sound3<<"sapi.Speak \"Do you need a programe to create an  HTML report for all students\""; // a VB Script code to pronounce a text
    sound3.close();
    system("call sound.vbs");// opening a created file with its its default program ( Windows Script Host   )


   char y='y';
   char Y='Y';
   char user_input;


cin>>user_input;






               set_screen();

 if(   y==user_input||Y==user_input ){// is user input is Y or y?

   cout<<setw(80)<<setfill(' ')<<"Please wait until we write report for all students....\n\n";






    for(int i=0;i<=(number_of_student-1);i++){ // for number of students


               create_html(i,true); // sending index of student, true indicates the user want the function to create report for all students

                                            }

    set_screen();
    cout<<setw(80)<<setfill(' ')<<"All reports is been saved in Documents folder \n\n";


     ofstream message;
     message.open("message.VBS");
     message<<" dim message\n";
     message<<" message=msgBox(\"Succesfull\",64,\"Succesfull\")    ";
     message.close();
     system("start message.VBS");


    ofstream sound;
    sound.open("sound.vbs");
    sound<<"dim sapi\n"; // a VB Script code to pronounce a text
    sound<<"set sapi=CreateObject(\"sapi.spvoice\")\n"; // a VB Script code to pronounce a text
    sound<<"sapi.Speak \"seccesful\"\n"; // a VB Script code to pronounce a text
    sound.close();
    system("Start/min sound.vbs");// open the file with its default program

    system("explorer %homedrive%%homepath%\\Documents\\\"Grade report\\\"   "); // not C++, open the path where  documents are saved in ( Explorer )
    system("pause"); // pause the system until a key is pressed



}


               set_screen();

               display_result();

return 100;
} // Main Function ends here




void input_error_message(){


     set_screen();

     ofstream error;
     error.open("error.vbs");// creating a file
     error<<"dim error\ndim box\nerror=\"Your input is not valid\"\nbox=msgbox(error,16,\"Error\")  ";// a VB Script code to pronounce a text
     error.close(); // closing a file
     system("call error.vbs"); // opening a file


}




void set_screen(){


         system("color 9f"); // change background console color to blue and text color to white | it is DOS Command
         system("mode con:cols=120 lines=50"); // set console width to 120 columns and 50 row | DOS Command
         system("title Student Information Management"); // change console title bar title to Student Information System | DOS Command


   cout<<setw(120)<<setfill('*')<<'*'<<endl;
   cout<<setw(75)<<setfill(' ')<<"Student Information Management\n\n";
   cout<<setw(120)<<setfill('*')<<'*'<<endl;


}





void read_registrar_info(){//


    cout<<"Organization Name:\t";

    ofstream sounda;
    sounda.open("sound.vbs");
    sounda<<"dim sapi\n"; // a VB Script code to pronounce a text
    sounda<<"set sapi=CreateObject(\"sapi.spvoice\")\n"; // // a VB Script code to pronounce a text
    sounda<<"sapi.Speak \"Enter Organization Name\""; //  // a VB Script code to pronounce a text
    sounda.close();
    system("call sound.vbs"); // opening the created  file with its default program
    cin>>organization_name;


    cout<<"Faculty:         \t";
    ofstream soundb;
    soundb.open("sound.vbs"); // creating a file
    soundb<<"dim sapi\n"; // a VB Script code to pronounce a text
    soundb<<"set sapi=CreateObject(\"sapi.spvoice\")\n"; // a VB Script code to pronounce a text
    soundb<<"sapi.Speak \"enter faculty name\""; // a VB Script code to pronounce a text
    soundb.close();
    system("call sound.vbs");// opening the created  file with its default program
    cin>>faculty_name;

    cout<<"Department:       \t";
    ofstream soundc;
    soundc.open("sound.vbs");
    soundc<<"dim sapi\n";
    soundc<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundc<<"sapi.Speak \"enter department name\"";
    soundc.close();
    system("call sound.vbs");
    cin>>department_name;



    cout<<"Your Name:        \t";
    ofstream soundd;
    soundd.open("sound.vbs");
    soundd<<"dim sapi\n";
    soundd<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundd<<"sapi.Speak \"enter your name\"";
    soundd.close();
    system("call sound.vbs");
    cin>>users_name;


    cout<<"Your role:         \t";
    ofstream sounde;
    sounde.open("sound.vbs");
    sounde<<"dim sapi\n";
    sounde<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    sounde<<"sapi.Speak \"enteryour role at "<<faculty_name<<" Faculty\"";
    sounde.close();
    system("call sound.vbs");
    cin>>role_of_user;

}




void calculate_rank(){//



  for(int i=0;i<=(number_of_student-1);i++){// iterating for all student

     int occurence=0;

  for(int j=0;j<=(number_of_student-1);j++){

       if(student[i].total<student[j].total){// the total mark of current student will be checked if it is less total mark of other students
       occurence++; // will be increment

                                            }

    student[i].rank=(occurence+1); // rank of student will be how much it is  beaten plus 1.

                                       }
}}


void calculate_average(){

   for(int i=0;i<=number_of_student-1;i++){
    for(int j=0;j<=number_of_course-1;j++){
       student[i].average=student[i].total/(number_of_course);
                                          }
                                          }
}



void calculate_total(){

   for(int i=0;i<=(number_of_student-1);i++){
            student[i].total=0;

          for(int j=0;j<=(number_of_course-1);j++){

           student[i].total+=student[i].mark[j];// the total value of current student will be the sum of all course mark

                                     }
                                   }
}




void read_course_name(){


    cout<<setw(70)<<setfill(' ')<<"Enter a Name for each course\n";
    ofstream soundf;
    soundf.open("sound.vbs"); //creating file
    soundf<<"dim sapi\n";// VBS code
    soundf<<"set sapi=CreateObject(\"sapi.spvoice\")\n";// VBS code
    soundf<<"sapi.Speak \"Please provide a name for the following courses\"";// VBS code
    soundf.close(); // closing file
    system("start/min sound.vbs");//opening the created  file with its default program





  for(int i=0;i<=(number_of_course-1);i++){
     cout<<(i+1)<<".";
     cin>>course_name[i];
                                         }

}





void create_html(int i,bool create_all_report=false){//speech ok




  cout<<"Creating a temporarly folder...\n";

          system("del a\\*.* /Q&del a\\* /Q&rd a"); //Deleting a folder "a" if it  already exist
          system("md a"); //Creating a temporary Folder 'a' to save ht-ml file in
          system("attrib +s +h a"); //making the temporary folder non visible


          ofstream out; // creating object of of-stream class for writing to file

cout<<"Writing to file...\n";
char temp_file_location[400]="a\\"; //will hold the directory whre reports will be saved
char file_extention[6]=".html";

            strcat(temp_file_location,student[i].id);
            strcat(temp_file_location,file_extention);


out.open(temp_file_location); //creating a file in a temporary folder

out<<" <html> \n"; // Starting Writing to HTML
out<<" <head> \n";
out<<" <title>"; out<<student[i].name; out<<" </title> \n";
out<<" </head> \n";// Writing html code to file
out<<" <body style=\"font-family:Calibri;width:1000\"> \n";



out<<" <div style=\"width:900px;height:1100px;padding:10px;border:4px double black;\">  ";


out<<"<h1 align=\"center\"> \n"; out<<organization_name; out<<"</h1> \n";
out<<"<h2 align=\"center\"> "; out<<"Faculty of "<<faculty_name; out<<" </h2 align=\"center\"> \n";

out<<"<h3 align=\"center\">"; out<<"Department of "<<department_name; out<<"</h3> \n";

out<<"<h4 align=\"center\">"; out<<"Grade Report"; out<<"</h4> \n";


out<<"<br> \n";

out<<"<hr width=100%> \n";

out<<"<p>";
out<<"<b>";
out<<"Name : ";
out<<student[i].name; out<<endl;
out<<"</b>";
out<<" <br>";

out<<" <b>";
out<<"Sex  : ";
out<<" </b>";

out<<student[i].sex;
out<<" \n";
out<<" <br>";
out<<" <b>";
out<<"ID  :";
out<<" </b>";
out<<student[i].id;
out<<" \n";
out<<" <br>";
out<<" \n";
out<<"</p>";
out<<" \n";

// Creating A table

out<<" <table border=1  style=\"width:100%\"> ";
out<<" \n";
out<<" <tr>";
out<<" <td>";
out<<" <b>";
out<<" \n";
out<<"Course Name";
out<<" </b>";
out<<" </td> ";
out<<" <td> ";
out<<" <b>";
out<<"Mark ";
out<<" </b>";
out<<" </td> ";
out<<" </tr> ";

// Writing A course name with score
for(int j=0;j<=(number_of_course-1);j++){

  out<<" \n";
  out<<" <tr>";
  out<<" <td>";
  out<<course_name[j];
  out<<" </td>";

  if(student[i].mark[j]<50){

  out<<" <td bgcolor=\"red\"> ";

  }
  else {
  out<<" <td>";

  }

  out<<student[i].mark[j];
  out<<" </td>";
  out<<" </tr> ";
  out<<" \n";

}


out<<" <tr>";
out<<" <td>";
out<<"Total ";
out<<" </td>";
out<<" <td>";
out<<student[i].total;
out<<" </td>";
out<<" </tr>";
out<<"\n";
out<<" <tr>  \n";
out<<" <td>  ";
out<<"  Average";
out<<" </td>";
out<<" <td> ";
out<<student[i].average;
out<<" </td> ";
out<<" <tr>";
out<<" <td>";
out<<"Rank ";
out<<" </td>";
out<<" <td>";
out<<student[i].rank;
out<<" </td>";
out<<" </tr>";
out<<"\n";






out<<"  </table> "; // Creating a Table ends here

out<<"<br>\n";
out<<" <p>";
out<<" <b>";
out<<" <small> This report is generated by: ";
out<<" </b>";
out<<" <u>";
out<<users_name;
out<<" </u>";

time_t sec; // creating a variable of type time_t (defined in header file "ctime"
sec = time(0); // Number of sec since January 1, 1970

char *date;
date=ctime(&sec); //converting sec to array of characters



out<<role_of_user<<" of "<<faculty_name<<" Faculty on "<<date;
out<<" <br>";
out<<" \n";

out<<" </small> ";
out<<" <br>";
out<<" \n";


out<<" </p>";

out<<"   </div>\n";









out<<"    <code>Developed at Bahr Dar University Institute of Technology by First Year Software Engineering Students In 2OO8 E.C (2016)</code> <br>" ;
out<<"    <br><br><br><br><br><br>";

out<<"  <script> window.print() </script> ";

out<<"  </body>\n";
out<<"  </html>\n";
out.close();


if(create_all_report){// if a true value is sent for this function beside student index it executes this code

char  destination[600]="%homedrive%%homepath%\\Documents\\\"Grade report\"\\"; /*

%homedrive% is a partition in which current OS is installed in Windows
%homepath% is the location of currently logged user

*/
char MOVE[600]="move a\\*.html "; // "MOVE" is used to move files and folders in DOS
char create_folder[500]="md "; // MD is used to create directories in DOS command

strcat(destination,faculty_name);
strcat(destination,"\\");
strcat(destination,department_name);
strcat(destination,"\\");
strcat(create_folder,destination);
system(create_folder);
strcat(MOVE,destination);
system(MOVE);
system("del a\\*.* /Q&del a\\* /Q&rd a"); // Deleting every file format from folder a (DEL a\*.*) deleting , deleting any file with no extension , removing directory (rd a)

}

else{ // if student index is sent


    ofstream soundm;
    soundm.open("sound.vbs");
    soundm<<"dim sapi\n";
    soundm<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundm<<"sapi.Speak \"Opening file via browser\"";
    soundm.close();
    system("call sound.vbs");

char report_file[300]="start/max ";
strcat(report_file,temp_file_location);



    system(report_file); // Opening created file so file will open with its default program, in our case web browsers

}

}




void read_student_data(int i){





    cout<<"Name      :\t\t";
    ofstream soundh;
    soundh.open("sound.vbs");
    soundh<<"dim sapi\n";
    soundh<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundh<<"sapi.Speak \"Name\"";
    soundh.close();
    system("call sound.vbs");
    cin>>student[i].name;

age_error_:

    cout<<"Age (7-99):\t\t";
    ofstream soundj;
    soundj.open("sound.vbs");
    soundj<<"dim sapi\n";
    soundj<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundj<<"sapi.Speak \"Age\"";
    soundj.close();
    system("call sound.vbs");



cin>>student[i].age;
  if(student[i].age<7||student[i].age>99){



    ofstream soundaa;
    soundaa.open("sound.vbs");
    soundaa<<"dim sapi\n";
    soundaa<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundaa<<"sapi.Speak \"Input Error! please enter between 7 and 99\"";
    soundaa.close();
    system("start/min sound.vbs");
    input_error_message();
    goto age_error_;
                                                  }

sex_error_:

    cout<<"Sex (M/F):\t\t";
    ofstream soundi;
    soundi.open("sound.vbs");
    soundi<<"dim sapi\n";
    soundi<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundi<<"sapi.Speak \"Sex\"";
    soundi.close();
    system("call sound.vbs");
    cin>>student[i].sex;


 if(!(int(student[i].sex)==int('M')  ||  int(student[i].sex)==int('F') ) ){

    ofstream soundab;
    soundab.open("sound.vbs");
    soundab<<"dim sapi\n";
    soundab<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundab<<"sapi.Speak \"Input Error ! enter only either capital M or F\"";
    soundab.close();
    system("start/min sound.vbs");
    input_error_message();
    goto sex_error_;
                                                                                    }
id_error:


    cout<<"ID:        \t\t";
    ofstream soundk;
    soundk.open("sound.vbs");
    soundk<<"dim sapi\n";
    soundk<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundk<<"sapi.Speak \"ID\"";
    soundk.close();
    system("call sound.vbs");
    cin>>student[i].id;





for(int z=0;z<i;z++){





if( 0==strcmp(student[i].id,student[z].id )){


    ofstream soundl;
    soundl.open("sound.vbs");
    soundl<<"dim sapi\n";
    soundl<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundl<<"sapi.Speak \"We are sorry, ID already used! please enter different one\"";
    soundl.close();
    system("start/min sound.vbs");
    input_error_message();
    goto id_error;

}






    ofstream soundm;
    soundm.open("sound.vbs");
    soundm<<"dim sapi\n";
    soundm<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundm<<"sapi.Speak \"Mark for following courses\"";
    soundm.close();
    system("call sound.vbs");

    cout<<"\n\n\n";}

    for(int j=0;j<=(number_of_course-1);j++){//Reading course mark


mark_error_:


    ofstream sound000;
    sound000.open("sound.vbs");
    sound000<<"dim sapi\n";
    sound000<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    sound000<<"sapi.Speak \"Mark of "<<course_name[j]<<" \"";
    sound000.close();
    system("call sound.vbs");




  cout<<"Mark of "<<course_name[j]<<":\t\t\t";
  cin>>student[i].mark[j];

if(student[i].mark[j]<0||student[i].mark[j]>100){// Check if entered mark value is valid

    ofstream sounddv;
    sounddv.open("error.vbs");
    sounddv<<"dim sapi\n";
    sounddv<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    sounddv<<"sapi.Speak \"Input Error! use only integers between 0 and 100\"";
    sounddv.close();
    system("start/min error.vbs");
    input_error_message();
    goto mark_error_;
                                                          }


}

}




void confirm_data(){// speech ok


set_screen();
registrar_data_view:

cout<<setw(75)<<setfill(' ')<<"Please confirm your data\n\n\n";
    ofstream soundn;
    soundn.open("sound.vbs");
    soundn<<"dim sapi\n";
    soundn<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundn<<"sapi.Speak \"comfirm if the following data is correct if you find an error press 1 and you can modify the data \"";
    soundn.close();
    system("call sound.vbs");

// Registrar info

cout<<"Your Organization name:"<<setw(80)<<setfill('.')<<organization_name<<endl<<endl;
cout<<"Faculty of students:   "<<setw(80)<<setfill('.')<<faculty_name<<endl<<endl;
cout<<"Department of students:"<<setw(80)<<setfill('.')<<department_name<<endl<<endl;
cout<<"Your Name:             "<<setw(80)<<setfill('.')<<users_name<<endl<<endl;
cout<<"Your role:             "<<setw(80)<<setfill('.')<<role_of_user<<endl<<endl;

cout<<endl<<endl<<endl;




cout<<setw(75)<<setfill(' ')<<"Enter 1 to correct data, enter any key to skip"<<endl;


char sure;
cin>>sure;



if(sure=='1'){
    set_screen();
    read_registrar_info(); // re take registrar info
    set_screen();
    goto registrar_data_view;
}



set_screen();
course_num_view:
cout<<setw(75)<<setfill(' ')<<"Please confirm your data\n\n\n";


// Student and Course number info

cout<<"Student number:"<<setw(30)<<setfill('.')<<number_of_student<<endl<<endl;
cout<<"Course Number :"<<setw(30)<<setfill('.')<<number_of_course<<endl<<endl;
cout<<endl<<endl<<endl;

cout<<setw(75)<<setfill(' ')<<"Enter 1 to correct data, enter any key to skip\n";
cin>>sure;



if(sure=='1'){


    num_couse_error();
    set_screen();
    goto course_num_view;

}


set_screen();

course_name_view:
cout<<setw(75)<<setfill(' ')<<"Please confirm your data\n\n\n";


// Course Name info

for(int i=0;(i<=number_of_course-1);i++){

cout<<"Name of course "<<(i+1)<<": "<<setw(30)<<setfill('.')<<course_name[i]<<endl<<endl;

                             }
cout<<endl<<endl<<endl;

cout<<setw(75)<<setfill(' ')<<"Enter 1 to correct data, enter any key to skip\n";
cin>>sure;



if(sure=='1'){


read_course_name();
set_screen();
goto course_name_view;

}


// Data error


for(int i=0;(i<=number_of_student-1);i++){

data_view:
set_screen();
cout<<setw(75)<<setfill(' ')<<"Please Confirm Your Data For "<<student[i].name<<" \n\n\n";



cout<<"Student Name:"<<setw(30)<<setfill('.')<<student[i].name<<endl<<endl;
cout<<"Age:         "<<setw(30)<<setfill('.')<<student[i].age<<endl<<endl;
cout<<"Sex:         "<<setw(30)<<setfill('.')<<student[i].sex<<endl<<endl;
cout<<"ID:          "<<setw(30)<<setfill('.')<<student[i].id<<endl<<endl;


for(int j=0;j<=(number_of_course-1);j++){


 cout<<"Mark of "<<course_name[j]<<setw(30)<<setfill('.')<<student[i].mark[j]<<endl<<endl;

}

cout<<setw(80)<<setfill(' ')<<"Enter 1 to correct data, enter any key to skip\n";

cin>>sure;

if(sure=='1'){


read_student_data(i);

set_screen();

goto data_view;

}




}


}




void display_result(){ // used for displaying result by checking ID // Speech okay

    bool entered_id_correct=false;// If correct ID is Entered this will be changed to true value. if incorrect ID (ID that do not match any student) will never changed to true.
    int ID_match;  // used to hold the index of student whom ID is matched with the ID entered by the user to see result
    char inID[10]; // used to accept and store ID entered by user to see result . this will be used to find student whom's ID is Entered.

    cout<<setw(68)<<setfill(' ')<<"Enter student ID to see the result:\n";


    ofstream soundr;
    soundr.open("sound.vbs");

    soundr<<"dim sapi\n";
    soundr<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundr<<"sapi.Speak \"Please provide student I D to see the result \"";
    soundr.close();
    system("call sound.vbs");
    cin>>inID;

  for(int i=0;i<=(number_of_student-1);i++){// For all students
     if(0==strcmp(inID,student[i].id)){// check if ID Match
     entered_id_correct=true;
     ID_match=i; // used to call create_HTML function

     cout<<setw(20)<<setfill(' ')<<"Student basic info:"<<endl<<endl;

        cout<<"Name:\t"<<student[i].name<<endl;
        cout<<"Sex: \t"<<student[i].sex<<endl;
        cout<<"Age: \t"<<student[i].age<<endl;
        cout<<"ID:  \t"<<student[i].id<<endl<<endl<<endl;

        cout<<setw(20)<<setfill(' ')<<"Student score:\n\n";

    for(int j=0;j<=(number_of_course-1);j++){// this iterates for number of course and display course name and score

        cout<<course_name[j]<<":\t"; cout<<student[i].mark[j]<<endl;
                                          }
        cout<<"Total:  \t"; cout<<student[i].total<<endl;
        cout<<"Average:\t"; cout<<student[i].average<<endl;
        cout<<"Rank:   \t"; cout<<student[i].rank<<endl;









    ofstream result;
    result.open("result.vbs");
    result<<"dim sapi\n";
    result<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    result<<"sapi.Speak \"Name :"<<student[i].name<<" \"\n";
    result<<"sapi.Speak \"Sex: ";
    if(student[i].sex=='M'){
    result<<"  Male \"\n";
    }

    else {

    result<<" Female \"\n";
        }
     result<<"sapi.Speak \" Age: "<<student[i].age<<"\"\n";
     result<<"sapi.Speak \" ID :  "<<student[i].id<<" \"\n";
     result<<"sapi.Speak \"              student scores       \" \n";




int m=0;

while(m<=(number_of_course-1)){

   result<<"sapi.Speak \" "<<course_name[m]<<"   "<<student[i].mark[m]<<"\"\n";
   m++;

                             }

    result<<"sapi.Speak\"Total Mark: "<<student[i].total<<" \"\n";
    result<<"sapi.Speak\"Average: "<<student[i].average<<" \"\n";
    result<<"sapi.Speak\"Rank:  "<<student[i].rank<<" \"\n";
    result.close();
    system("call result.vbs");




        // Following codes are used to check wheather  the user HTML version of the report

        char YES='Y';
        char yes='y';
        char choice_html;

    cout<<"Print the result via browser\?(Y/N)\n";

    ofstream sounds;
    sounds.open("sound.vbs");
    sounds<<"dim sapi\n";
    sounds<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    sounds<<"sapi.Speak \"Do you want to open report via your internet browser \"";
    sounds.close();
    system("call sound.vbs");



    cin>>choice_html;
    if(yes==int(choice_html)||int(choice_html)==YES){// checking if user input is either Y or y
    create_html(ID_match);
    set_screen();
    display_result();
                                               }



} // if condition ends here

} // iteration ends here


if(!entered_id_correct){

    set_screen();

    cout<<"No student with this ID check caps lock! \n";
    ofstream soundt;
    soundt.open("error.vbs");
    soundt<<"dim sapi\n";
    soundt<<"sapi=msgBox(\"We are sorry! we could not found any student with that I D \",48,\"No such a student\")";
    soundt.close();
    system("error.vbs");


    getch();

}


set_screen();
display_result();

}// Function ends here





void num_couse_error(){



    num_student_error:
    cout<<"Number of Student:\t";
    cin>>number_of_student;



if(number_of_student<=0) {




    input_error_message();
    goto num_student_error;
    }


    num_course_error:
    cout<<"Number of Course:\t";
    cin>>number_of_course;

set_screen();


if(number_of_course<1){

    ofstream soundsz;
    soundsz.open("sound.vbs");
    soundsz<<"dim sapi\n";
    soundsz<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundsz<<"sapi.Speak \"Not a valid input!!\"";
    soundsz.close();
    system("sound.vbs");
    set_screen();
    goto num_course_error;

}


}



void splash(){// Splash the logo of SIM on console


            system("color 9f"); // change color to WHITE ON BLUE SCREEN via windows command tool
            system("mode con:cols=120 lines=50"); //change console size via windows command tool
            system("title Student Information Managment"); // Change window title to Student Information System


//The following cout code displays SIM on screen


cout<<"\n\n\n\n";
cout<<"           **********************************************************************************************\n";
cout<<"           **********************************************************************************************\n";
cout<<"           ***                                                                                        ***\n";
cout<<"           ***                                                                                        ***\n";
cout<<"           ***                                                                                        ***\n";
cout<<"           ***          *************         ***           *******                    *******        ***"<<endl;
cout<<"           ***          *************         ***           ********                 *********        ***"<<endl;
cout<<"           ***          ***                   ***           ***    ***             ***     ***        ***"<<endl;
cout<<"           ***          ***                   ***           ***      ***         ***       ***        ***"<<endl;
cout<<"           ***          ***                   ***           ***        ***     ***         ***        ***"<<endl;
cout<<"           ***          *************         ***           ***          *** ***           ***        ***"<<endl;
cout<<"           ***          *************         ***           ***            ***             ***        ***"<<endl;
cout<<"           ***                    ***         ***           ***                            ***        ***"<<endl;
cout<<"           ***                    ***         ***           ***                            ***        ***"<<endl;
cout<<"           ***                    ***         ***           ***                            ***        ***"<<endl;
cout<<"           ***          *************         ***           ***                            ***        ***"<<endl;
cout<<"           ***          *************         ***           ***                            ***        ***"<<endl;
cout<<"           ***                                                                                        ***\n";
cout<<"           ***    |-------------------------------------------------------------------------------|   ***\n";
cout<<"           ***    |      Abenezar Abraham | Dawit Eshetie   | Elshadai Mokonin | Genet Aliyou     |   ***\n";
cout<<"           ***    |      Temesgen Kaffie  | Tarekegn Mengie | Tesfa Shibesh    | Tinsae Belay     |   ***\n";
cout<<"           ***    |-------------------------------------------------------------------------------|   ***\n";
cout<<"           ***                                                                                        ***\n";
cout<<"           **********************************************************************************************\n";
cout<<"           **********************************************************************************************\n";




    ofstream soundu;
    soundu.open("sound.vbs");

    soundu<<"dim sapi\n";
    soundu<<"set sapi=CreateObject(\"sapi.spvoice\")\n";
    soundu<<"sapi.Speak \"This is Student Information Managment System!\" \n";
    soundu<<"sapi.Speak \"created at university of Bahr Dahr in two thousand sixteen by first year Software Engineering Students  \" \n";
    soundu<<"sapi.Speak \"Abenezar Abraham \" \n";
    soundu<<"sapi.Speak \"Dawit Eshetie \" \n";
    soundu<<"sapi.Speak \"Elshadai Mokonin \" \n";
    soundu<<"sapi.Speak \"Ganet Aliyou \" \n";
    soundu<<"sapi.Speak \"Tamas Gun Caffe \" \n";
    soundu<<"sapi.Speak \"Tarakagn Man gay \" \n";
    soundu<<"sapi.Speak \"Tasfa Shibash \" \n";
    soundu<<"sapi.Speak \"and Tinsae Balay \" \n";
    soundu<<"sapi.Speak \"as first year programing project \" \n";
    soundu.close();
    system("start sound.vbs");

    cout<<"\n\n\n\n Loading"<<"    ";

          for(int j=0;j<=100;j++){ //

          for(double i=0;i<=45000000;i++){//making computer lag(wait for seconds)
                                         }

          cout<<char(434);// char(434) is unsupported character by c++ used to display cube
}

} // Splash function ends here
