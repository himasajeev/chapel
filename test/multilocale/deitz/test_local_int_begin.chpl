use Time;

def main {
  foo();
  sleep(5); // make sure program does not exit
}

def foo() {
  var x: int = 17;
  _debugWriteln(here.id, " x=", x);
  x += 1;
  on Locales(1) {
    begin {
      sleep(2);
      _debugWriteln(here.id, " x=", x);
      x += 1;
      _debugWriteln(here.id, " x=", x);
    }
  }
  _debugWriteln(here.id, " x=", x);
}
