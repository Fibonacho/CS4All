int main() {
  int* value;
  value = malloc(4);

  value = "1234";

  threadStart();

  while (writeLock(value) != 1) {
    sched_yield();
  }

  write(1, (int*) "##### ", 6);
  printInteger(getPID());
  write(1, (int*) " #####", 6);
}
