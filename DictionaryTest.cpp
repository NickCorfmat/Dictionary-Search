// --------------------------------------------------------------
// Nicolas Corfmat
// CruzID: ncorfmat
// Assignment: pa7
// --------------------------------------------------------------

//-----------------------------------------------------------------------------
// DictionaryClient.cpp
// A test client for the Dictionary ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

using namespace std;

int main(){

   string s;
   int x;
   string S[] =   {
                     "strawberry",
                     "tiger",
                     "car",
                     "cradle",
                     "prisoner",
                     "driving",
                     "wheel",
                     "zebra",
                     "watermelon",
                     "sport",
                     "tree",
                     "exhaust",
                     "pill",
                     "dream",
                     "demonstrate",
                     "eat",
                     "consume",
                     "absent",
                     "caramelize",
                     "quickly",
                     "starve",
                     "target",
                     "sanitize",
                     "glorius",
                     "hologram",
                     "household",
		     "hedgehod",
		     "meter",
		     "microsecond",
		     "anagram",
		     "pie",
		     "pizza",
		     "hamburger"
                  };
   string T[] =   {
                     "fly",
                     "paperwork",
                     "wild",
                     "transport",
                     "vintage",
                     "terrace",
                     "jamboree",
                     "track",
                     "package",
                     "elephant",
                     "advocate",
                     "all",
                     "dreamworks",
                  };

   Dictionary A;
   Dictionary B;

   cout << endl;

   for(int i=0; i<33; i++){
      A.setValue(S[i], i+1);
   }

   B = A;

   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << "B.size() = " << B.size() << endl  << B << endl;

   cout << "A.contains('strawberry') = " << A.contains("strawberry") << endl;
   cout << "A.contains('vintage') = " << A.contains("vintage") << endl;
   
   B.setValue("monolithic", 143);
   B.setValue("chowder", 87);
   B.setValue("squid", 374);
   B.setValue("quarrel", 283);
   B.setValue("isolation", 572);

   Dictionary C = B;

   cout << "A==B is " << (A==B?"true":"false") << endl;
   cout << "B==C is " << (B==C?"true":"false") << endl;
   cout << "C==A is " << (C==A?"true":"false") << endl << endl;

   A = B;
   C = A;

   cout << "A==B is " << (A==B?"true":"false") << endl;
   cout << "B==C is " << (B==C?"true":"false") << endl;
   cout << "C==A is " << (C==A?"true":"false") << endl << endl;

   cout << A.getValue("car") << endl;
   A.getValue("car") += 57;
   cout << A.getValue("car") << endl << endl;

   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout << "C.size() = " << C.size() << endl  << C << endl;

   cout << A.pre_string() << endl << endl;
   cout << B.pre_string() << endl << endl;
   cout << C.pre_string() << endl << endl;

   for(int i=0; i<18; i++){
      A.remove(T[i]);
   }

   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << A.pre_string() << endl;

   for(int i=0; i<3; i++){
      B.remove(T[i]);
   }

   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout << B.pre_string() << endl;

   for(int i=0; i<14; i++){
      C.remove(T[i]);
   }

   cout << "C.size() = " << C.size() << endl  << C << endl;
   cout << C.pre_string() << endl;

   for(A.begin(); A.hasCurrent(); A.next()){
      s = A.currentKey();
      x = A.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;

   for(A.end(); A.hasCurrent(); A.prev()){
      s = A.currentKey();
      x = A.currentVal();
      cout << "("+s+", " << x << ") ";
   }

   cout << endl << endl;

   for(B.begin(); B.hasCurrent(); B.next()){
      s = B.currentKey();
      x = B.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;

   for(B.end(); B.hasCurrent(); B.prev()){
      s = B.currentKey();
      x = B.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;

   for(C.begin(); C.hasCurrent(); C.next()){
      s = C.currentKey();
      x = C.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;

   for(C.end(); C.hasCurrent(); C.prev()){
      s = C.currentKey();
      x = C.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;

   try{
      A.getValue("fantastic");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.remove("fantastic");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentKey();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentVal();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.next();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.prev();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      B.getValue("xylophone");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      B.remove("xylophone");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      B.currentKey();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      B.currentVal();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      B.next();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      B.prev();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      C.getValue("fantastic");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      C.remove("surprise");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentKey();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      C.currentVal();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      C.next();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      C.prev();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;

   return( EXIT_SUCCESS );
}
