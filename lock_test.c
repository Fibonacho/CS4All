int main() {
  // little program to demonstrate usage of locks
  int  i;

  lock();

  while(i < 10){
      getPID();
      i = i + 1;
  }

  unlock();    

}
