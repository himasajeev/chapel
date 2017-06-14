// This test exercises inheriting from a generic class with a type field when
// the child class also has a type field.
class Parent {
  type t;
  var x: t;

  proc init(xVal) {
    t = xVal.type;
    x = xVal;
    super.init();
  }
}

class Child : Parent {
  type t2;
  var y: t2;

  proc init(yVal, xVal) {
    t2 = yVal.type;
    y = yVal;
    super.init(xVal);
  }
}

proc main() {
  var child = new Child(10, 11);
  writeln(child.type:string);
  writeln(child);
  delete child;
}
