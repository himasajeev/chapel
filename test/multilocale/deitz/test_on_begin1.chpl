use Time;

var i$: sync int;

def foo() {
  var x: int = 2;
  on Locales(1) {
    begin {
      _debugWriteln(here.id, " x=", x);
      i$ = 1;
    }
  }
  _debugWriteln(i$);
  _debugWriteln(here.id, " x=", x);
}

foo();
