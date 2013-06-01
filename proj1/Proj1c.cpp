//AUTHOR: CORY BEKKER
//CS215
//PROJECT 1
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

string check_proper_noun(string Array[],int x1);
string check_subject_pronoun(string Array1[], int x2);
string check_common_noun(string Array2[], int x3);
string check_adjective(string Array3[], int x4);
string check_articles(string Array4[], int x5);
string check_verb(string Array5[], int x6);
string check_object(string Array6[], int x7);
string check_preposition(string Array7[], int x8);
bool check_argument(int argc, char* argv[]);
bool check_spaces(char* argv[]);
bool check_PuncsCaps(char* argv[]);
int check_for_subject(string Array8[],string NOUN[], string SUBJECT_PRO[],
                      string ARTICLE[],string COMMONNOUN[], string ADJECTIVE[], int i, int n);
int check_for_object(string Array9[],string NOUN1[], string OBJECT1[], string ARTICLE1[],
		     string COMMONNOUN1[], string ADJECTIVE1[], int I, int N);


const int num = 1000;//size of all arrays

int main(int argc, char* argv[]) {

  ifstream file;
  char sentence;
  string sentence1;
  char arr1[num];
  int max=0;

  ////////////checks for argument/////////////////////////////////////////
  if(check_argument(argc,argv)== true){}
  else{
    return 0;
  }
  //////////////////////////////THE LOOP////////////////////////////////////

  ///////////checks for spaces///////////////////////////////////////////
  if(check_spaces(argv)==true){}
  else{
    return 0;
  }
  //////////////////////checks for capitalization and punctuation/////////
  if(check_PuncsCaps(argv)==true){}
  else{
    return 0;
  }
  /////////////////checks for subject///////////////////////////////////
  file.open(argv[1]);

  stringstream s;
  string words;// I can make this as a string or char for stringstream
  string array4[num];
  int w=0;
  string noun[num];//a
  string subject_pro[num];//b
  string commonnoun[num];//c
  string adjective[num];//d
  string article[num];//e
  string verb[num];//f
  string object[num];//g
  string preposition[num];//h
  int current_word=0;
  int a =0;
  int b =0;
  int c =0;
  int d =0;
  int e =0;
  int f =0;
  int g =0;
  int h =0;
  int n=0;//used in check object/subject calls
  
  while(getline(file,sentence1)){
    s.str(sentence1);
    while(s>>words){
      array4[w]=words;
      w++;
    }
    s.clear();
  }
  /////////////////////////////////////////////////////////
  for(int i=0; i<w; i++){
    
    if(check_proper_noun(array4,i)!="..."){
     noun[a]=check_proper_noun(array4,i);
     a++;
   }
   if(check_subject_pronoun(array4,i)!="..."){
     subject_pro[b]=check_subject_pronoun(array4,i);
     b++;
   }
   if(check_common_noun(array4,i)!="..."){
     commonnoun[c]=check_common_noun(array4,i);
     c++;
   }
   if(check_adjective(array4,i)!="..."){
     adjective[d]=check_adjective(array4,i);
     d++;
   }
   if(check_articles(array4,i)!="..."){
     article[e]=check_articles(array4,i);
     e++;
   }
   if(check_verb(array4,i)!="..."){
     verb[f]=check_verb(array4,i);
     f++;
   }
   if(check_object(array4,i)!="..."){
     object[g]=check_object(array4,i);
     g++;
   }
   if(check_preposition(array4,i)!="..."){
     preposition[h]=check_preposition(array4,i);
     h++;
   }
  }
  ////////////////////////////////////////////////////////
  int i=0;  

  if(check_for_subject(array4,noun,subject_pro,article,commonnoun,adjective,i,n) == -1){
   cout<<"missing subject, No0o0o0 :(!!!"<<endl;
  }
  
 else{
   current_word = check_for_subject(array4,noun,subject_pro,
 				    article,commonnoun,adjective,i,n)+1;
 }
  /////////////////////////////////////////////////////////////////////////
  
  i=current_word;
  
  if(check_verb(array4,i)!="..."){
    if(i==w-1){
      cout<<"end of the array"<<endl;
      return 0;
    }
    i++;
  }
  else{
    cout<<"missing verb"<<endl;
    return 0;
  }
  if(check_preposition(array4,i)!="..."){
    if(i==w-1){
      cout<<"missing prep"<<endl;
      return 0;
    }
    i++;
  }
  if(check_for_object(array4,noun,object,
		      article,commonnoun,adjective,i,n)!= -1){
    i= check_for_object(array4,noun,object,article,commonnoun,adjective,i,n);
    if(i==w-1){
      cout<<"end of array"<<endl;
      return 0;
    }
    i++;
  }
  else{
    cout<<"missing predicate"<<endl;
  }    
  if(check_preposition(array4,i)!="..."){
    if(i==w-1){
      cout<<"missing prep"<<endl;
      return 0;
    }
    i++;
  }
    if(check_for_object(array4,noun,object,
			article,commonnoun,adjective,i,n)!= -1){
      cout<<"correct sentence"<<endl;
    }
    else{
      cout<<"missing predicate"<<endl;
    }      
      
      
////////////////////////////////////////////////////////////////////////
  
 return 0;
 
}
////////////////////////FUNCTIONS///////////////////////////////////////////
int check_for_subject(string Array8[],string NOUN[], string SUBJECT_PRO[], string ARTICLE[],
                      string COMMONNOUN[], string ADJECTIVE[], int i, int n){

  if(Array8[i] == NOUN[n])
    return i;
  if(Array8[i] == SUBJECT_PRO[n])
    return i;
  if(Array8[i] == ARTICLE[n] and Array8[i+1] == COMMONNOUN[n])
    return i+1;
  if(Array8[i] == ARTICLE[n] and Array8[i+1] == ADJECTIVE[n] and Array8[i+2]== COMMONNOUN[n])
    return i+2;
  else
    return -1;
}
  ////////////////////////////////////////////////////////////////////////////////////////////
  int check_for_object(string Array9[],string NOUN1[], string OBJECT1[], string ARTICLE1[],
		       string COMMONNOUN1[], string ADJECTIVE1[], int I, int N){
    
    for(N = 0; N<2; N++){// just in case there is a word used more than once in a sentence 
      if(Array9[I] == NOUN1[N])
	return I;
      if(Array9[I] == OBJECT1[N])
	return I;
      if(Array9[I] == ARTICLE1[N] and Array9[I+1] == COMMONNOUN1[N])
	return I+1;
      if(Array9[I] == ARTICLE1[N] and Array9[I+1] == ADJECTIVE1[N] and Array9[I+2]== COMMONNOUN1[N])
	return I+2;
    }
    return -1;
  }
///////////////////////////////CHECK ARGUMENT////////////////////////////////
bool check_argument(int argc, char* argv[]){

  ifstream file;

  if(argc > 2){
    cout<< "Too many command-line inputs given."<<endl;
    return false;
  }
  if(argc < 2){
    cout<<"No file name entered."<<endl;
    return false;
  }

  file.open(argv[1]);

  if(file.fail()){
    cout<<"Could not open file."<<endl;
    file.close();
    return false;
  }
  else{
    file.close();
    return true;
  }
}
///////////////////////////CHECK SPACES FUNCTION////////////////////////////////
bool check_spaces(char* argv[]){

  ifstream file;
  char arr1[num];
  string arr2[num];
  char next;
  int max1=0;
  int front_spot = 0;
  int rear_spot = 0;

   file.open(argv[1]);

  while((next = file.get()) != '\n'){
    arr2[max1]=next;//creates array
    max1++;//size of array
  }
  while(arr2[front_spot]== " "or arr2[front_spot]=="\n"or arr2[front_spot]=="\t"){
    front_spot++;// reads all white space before first char
    if(front_spot==max1){//if file is empty, closes program
      return false;
    }
  }
  for(int i= max1; i>front_spot; i--){

    if(arr2[i]==" " or arr2[i]=="\n" or arr2[i]=="\t" or arr2[i]=="\0"){
      rear_spot =i;// always looking at a empty spot i -1.
    }
    else{
      break;//exits loop if arr2[i] runs into a char
    }
  }
  cout<<"Report for sentence: ";
  for(int n=front_spot; n<=rear_spot; n++){//Prints out sentence
    cout<<arr2[n];
  }
  cout<<endl;
  for(int n=front_spot; n<rear_spot; n++){// starts where the first char is in thetxt
  if(arr2[n] == " " and arr2[n-1] ==" " or arr2[n]== "\t"){ // checks for...
    cout<<"ERROR: invalid spacing"<<endl;
    return false;                                          // extra spaces and tabs
  }
  }
  //  file.close();
  return true;
}
/////////////////////////////////////////////////////////////////////////////////\
//////
bool check_PuncsCaps(char* argv[]){

  ifstream file;
  char sentence;
  char arr1[num];
  int max=0;
  int i=0;

    file.open(argv[1]);

  while(file >> sentence){
    arr1[i]=sentence;
    max = i++;
  }
  if(arr1[0] >='a' && arr1[0] <='z'){
    cout<<"ERROR: invalid capitalization"<<endl;
    //return false;
  }
  if(arr1[max]== '.'){ }
  else {
    cout <<"ERROR: invalid punctuation"<<endl;
    // return false;
  }
  file.close();
  return true;
  }


/////////////////////////////////////////////////////////////////////////////////

string check_preposition(string Array7[], int x8){
  
  int i = 0;
  i = x8;
  if(Array7[i] == "to" or
     Array7[i] == "for" or
     Array7[i] == "with" or
     Array7[i] == "to." or
     Array7[i] == "for." or
     Array7[i] == "with.")return Array7[i];  
  return "...";
}
///////////////////////////////////////////////////
string check_object(string Array6[], int x7){

  int i=0;
  i=x7;
    if(Array6[i] == "him" or
       Array6[i] == "her" or
       Array6[i] == "them" or
       Array6[i] == "me" or
       Array6[i] == "him." or
       Array6[i] == "her." or
       Array6[i] == "them." or
       Array6[i] == "me.")return Array6[i];
 
  return "...";
}
///////////////////////////////////////////////////
string check_verb(string Array5[], int x6){

  int i =0;
  i=x6;
    if(Array5[i] == "gave" or
       Array5[i] == "ate" or
       Array5[i] == "married" or
       Array5[i] == "gave." or
       Array5[i] == "ate." or
       Array5[i] == "married.")return Array5[i];
 
  return "...";
}
/////////////////////////////////////////////////////
string check_articles(string Array4[], int x5){

  int i =0;
  i=x5;
    if(Array4[i] == "a" or
       Array4[i] == "the" or
       Array4[i] == "a." or
       Array4[i] == "the.")return Array4[i];
 
  return "...";
}
//////////////////////////////////////////////////////
string check_adjective(string Array3[], int x4){

  int i=0;
  i=x4;
    if(Array3[i] == "cute" or
       Array3[i] == "big" or
       Array3[i] == "purple" or
       Array3[i] == "cute." or
       Array3[i] == "big." or
       Array3[i] == "purple.")return Array3[i];
  
  return "...";
}
////////////////////////////////////////////////////////
string check_common_noun(string Array2[], int x3){

  int i = 0;
  i = x3;
    if(Array2[i] == "time" or
       Array2[i] == "kneecap" or
       Array2[i] == "puppy" or
       Array2[i] == "refrigerator" or
       Array2[i] == "time." or
       Array2[i] == "kneecap." or
       Array2[i] == "puppy." or
       Array2[i] == "refrigerator.") return Array2[i];
  
  return "...";
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
string check_subject_pronoun(string Array1[], int x2){

  int i = 0;
  i = x2;

    if(Array1[i] == "I" or
       Array1[i] == "he" or
       Array1[i] == "her" or
       Array1[i] == "they"or
       Array1[i] == "I." or
       Array1[i] == "he." or
       Array1[i] == "her." or
       Array1[i] == "they.")return Array1[i];

  return "...";
}
//////////////////////////////////////////////////////
string check_proper_noun(string Array[],int x1){

  int i =0;
  i = x1;
    if(Array[i] == "godzilla" or
       Array[i] == "spiderman" or
       Array[i] == "zeus" or
       Array[i] == "godzilla." or
       Array[i] == "spiderman." or
       Array[i] == "zeus.") return Array[i];
 
  return "...";
}

