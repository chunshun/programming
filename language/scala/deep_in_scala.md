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
