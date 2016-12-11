int main() {
  int  i;
  int test;
	int* buf;


	buf = malloc(4);
	*(buf) = 0;

  test = 0;


	threadStart();

  while(lock() == 0) {
  	sched_yield();
  }

  while(i < 10){

      printInteger(getPID());

      test = test + 1;
			*(buf) = *(buf) + 1;

			printInteger(*(buf));
      printInteger(test);
      i = i + 1;
  }

  unlock();    

}
