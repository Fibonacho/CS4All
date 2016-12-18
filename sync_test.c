int main() {

  int* variable;
  int  success;
  variable = malloc(4);
  variable = (int*) "1111";

  // print value of variable
  write(1, "val 1: ", 7); write(1, variable, 4); write(1, " | ", 3);

  threadStart();

  // try to get a read-lock
  success = readLock(variable);
  if (success) write(1, "got read-lock!! ", 16);
  else         write(1, "got NO read-lock ", 17);

  // try to get a write-lock (should not succeed - already read-locked)
  success = writeLock(variable);
  if (success) write(1, "got write-lock!! ", 17);
  else         write(1, "got NO write-lock ", 18);

  // try to change value (should not work)
  *(variable) = 2222;

  // print value of variable (should still be 1111)
  write(1, "val x: ", 7); write(1, variable, 4); write(1, " , ", 3);

  // release read-lock again
  readUnlock(variable);

  // try to get a write-lock (should succeed now)
  success = writeLock(variable);
  if (success) write(1, "got write-lock!! ", 17);
  else         write(1, "got NO write-lock ", 18);

  // try to change value (should work)
  *(variable) = 3333;

  // print (new) value of variable
  write(1, "val 2: ", 7); write(1, variable, 4); write(1, " ; ", 3);

  // release write-lock again
  writeUnlock(variable);
}
