# `tupled` and `curried`
```scala
val f1=(x:Int)=>(y:Int)=>x+y
val f2=(x:Int,y:Int)=>x+y

//f1(19)(10) tupled



//f2(10,19) curried

```
# `implicit`
1. Something missing: implicit parameters
```scala
def multiply(x: Int)(implicit y: Int) = x * y

multiply(3)(10) // 30
multiply(4)(10) // 40

multiply(3)
// error: could not find implicit value for parameter factor: Int

implicit val z: Int = 10

multiply(3) // 30
multiply(4) // 40

implicit val z2: Int = 11

multiply(3)
// error: ambiguous implicit values:
// both value y of type => Int
// and value z of type => Int
// match expected type Int
```
2. Something mismatched: implicit conversions
```scala
def alert(msg: String): Unit = println(msg)

alert(7)
// error: type mismatch;
// found   : Int(7)
// required: String

implicit def intToString(i: Int): String = i.toString

alert(7)
// 7
//alert(intToString(7))
```
3. implicit class
```scala
 3.chat
// error: value chat is not a member of Int

class LoquaciousInt(x: Int) {
  def chat: Unit = for(i <- 1 to x) println("Hi!")
}

implicit def intToLoquaciousInt(x: Int) = new LoquaciousInt(x)

3.chat
// Hi!
// Hi!
// Hi!


//rewrite the code
//implicit class
implicit class LoquaciousInt(x: Int) {
  def chat: Unit = for(i <- 1 to x) println("Hi!")
}

3.chat
// Hi!
// Hi!
// Hi!

implicit class StringImprovements(s: String) {
     def increment = s.map(c => (c + 1).toChar)
}
```
4. Trait 
```scala
//compare:

//without trait:
final case class Person(firstName: String, lastName: String)

object PersonCanChat {
  def chat(x: Person) = s"Hi, I'm ${x.firstName}"
}

PersonCanChat.chat(Person("John", "Smith"))

final case class Dog(name: String)

object DogCanChat {
  def chat(x: Dog) = s"Woof, my name is ${x.name}"
}

DogCanChat.chat(Dog("Meg"))



//with trait
trait ConCat[A] {
  def chat(x: A): String
}

case class Animal(name: String, age: Int)
object Dog extends ConCat[Animal] {
  def chat(x: Animal): String = "It's a dog"
}


//merge here
final case class Person(firstName: String, lastName: String)

object PersonCanChat extends CanChat[Person] {
  def chat(x: Person) = s"Hi, I'm ${x.firstName}"
}

final case class Dog(name: String)

object DogCanChat extends CanChat[Dog] {
  def chat(x: Dog) = s"Woof, my name is ${x.name}"
}

object ChatUtil {
  def chat[A](x: A, chattyThing: CanChat[A]) = {
    chattyThing.chat(x)
  }
}

ChatUtil.chat(Dog("Meg"), DogCanChat)
ChatUtil.chat(Person("John", "Smith"), PersonCanChat)
```
4. implicit trait
```scala
object ChattyAddons {
  implicit object PersonCanChat extends CanChat[Person] {
    def chat(x: Person) = s"Hi, I'm ${x.firstName}"
  }
  implicit object DogCanChat extends CanChat[Dog] {
    def chat(x: Dog) = s"Woof, my name is ${x.name}"
  }
}

// ...in another package
import ChattyAddons._

ChatUtil.chat(Person("John", "Smith"))
ChatUtil.chat(Dog("Meg"))
```
5. plus implicit conversions (in the form of implicit classes)
```scala
object ChattyAddons {
  implicit object PersonCanChat extends CanChat[Person] {
    def chat(x: Person) = s"Hi, I'm ${x.firstName}"
  }
  implicit object DogCanChat extends CanChat[Dog] {
    def chat(x: Dog) = s"Woof, my name is ${x.name}"
  }
  implicit class ChatUtil[A](x: A) {
    def chat(implicit makesChatty: CanChat[A]) = {
      makesChatty.chat(x)
    }
  }
}

// in another package...

import ChattyAddons._

Person("John", "Smith").chat
Dog("Meg").chat

"Hello".chat // this will not work
```
6. with case class
```scala 
case class StringOps(str: String) {
  def yell = str.toUpperCase() + "!"
  def isQuestion = str.endsWith("?")
}

implicit def stringToStringOps(str: String): StringOps = StringOps(str)

"Hello world".yell // evaluates to "HELLO WORLD!"  string=>StfingOps
"How are you?".isQuestion // evaluates to 'true'


object Helpers {
  implicit class StringOps(str: String) {
    def yell = str.toUpperCase() + "!"
    def isQuestion = str.endsWith("?")
  }
}

"Hello world".yell // evaluates to "HELLO WORLD!"
"How are you?".isQuestion // evaluates to 'true'
```
7. Note, that there are requirements for the class to be implicit:
  1. It has to be inside another trait, class or object
  2. It has to have exactly one parameter (but it can have multiple implicit parameters on its own)
  3. There may not be any method, member or object in scope with the same name
8. Type classes
```scala
// Our interface
trait Monoid[A] {
  def zero: A
  def plus(a: A, b: A): A
}

// Implementation for integers
implicit object IntegerMonoid extends Monoid[Int] {
  override def zero: Int = 0
  override def plus(a: Int, b: Int): Int = a + b
}

// Implementation for strings
implicit object StringMonoid extends Monoid[String] {
  override def zero: String = ""
  override def plus(a: String, b: String): String = a.concat(b)
}

// Could be implementation for custom classes, etc..

// Our generic function that knows which implementation to use based on type parameter 'A'
def sum[A](values: Seq[A])(implicit ev: Monoid[A]): A = values.foldLeft(ev.zero)(ev.plus)
```
# `kind`
1. kind of type
The kind of ordinary types like `Int` or `String`,whose instances are values is `*`.The kind of unary type constructors like `Maybe` is `*->*`;binary type constructors like `Either` have(curried) kind `*->*->*`.A function is higher-order if it has an order greater than 1, where the order is (informally) the nesting depth, to the left, of function arrows:
```scala
Order0: 1::Int
Order1: Char:Int->Char
Order2: fix::(a->a)->a,map::(a->b)->[a]->[b]
Order3: ((A->B)->C)->D
Order4: (((A->B)->C)->D)->E
```
**a higher-kinded type is just a type-level higher-order function which abstracts over type constructors:**
```scala
Order0: Int::*
Order1: Maybe::*->*
Order2: Funtor::(*->*)->Constraint
//higher-kinded:converts unary type constraints to typeclass constraints.
```
#Types
The bottom type - a type which is a subtype of all others, and has no citizen - in Scala is `Nothing`.
The sealed keyword makes sure that no new subtype of said class can be created outside the current file, and so compiler will always know all types that directly inherit the trait (and form a disjoint union). This allows pattern matching to be exhaustive: compiler can tell us that we didn’t matched all components of the union.
```scala
sealed trait Either[+A, +B] {}
case class Left[+A, +B](a: A) extends Either[A, B]
case class Right[+A, +B](b: B) extends Either[A, B]

sealed trait Option[+A] {}
case class Some[A](value: A) extends Option[A]
case object None extends Option[Nothing]


def f(intOrString: Int | String) = intOrString {
  case i: Int    => ...
  case s: String => ...
}
```
# algebraic data types

# trait linearization
```scala

trait Str { def str: String }
trait Count { def count: Int }

def repeat(cd: Str with Count): String =
  Iterator.fill(cd.count)(cd.str).mkString

repeat(new Str with Count {
  val str = "test"
  val count = 3
})
val sc: Str with Count
val ca: Count with Str
def repeat(sc) // works as expected
def repeat(ca) // also works!



trait A { def value = 10 }
trait B extends A { override def value = super.value * 2 }
trait C extends A { override def value = super.value + 2 }
(new B with C {}).value // (10*2)+2
(new C with B {}).value // (10+2)*2
```
# Type constructors and parameter types
We can think of type as a set. But we can also think of function as a set, a set of parameters-returned value pairs. 
Such interesting function which takes a type and builds another type is called a ***type constructor***. In Scala, we could denote *List* type constructor as `List[_]`.You can have a higher order function: a function which takes and/or returns another function. Same with type constructors: you can have a type constructor, which takes and/or returns another type constructor. Many type class definitions take a type constructor as a parameter:
```scala
trait Functor[F[_]] { // <- F is a type constructor
    def map[A, B](fa: F[A])(f: A => B): F[B]
}
```
# Kinds and higher-kinded-types
These types of types (a type, a type constructor, etc) are known as kinds."Kind" is a word used to classify types and type constructors
according to their level of abstractness.
