#types
- variance
```scala
Array[T]
// invariant:used when elements in the container are immutable
// ex:Array[String]

Seq[+A]
// co-variant:used when elements in the containers ars immutable.This makes the container more flexible
// ex: we can pass a Seq[String] to a method expected Seq[Any]

Foo[-A] 
// co-invariant
 
```
- Bounds
```scala
A:<B
// upper bound,A must be a subtype of B

A>:B
// lower bound,A must be a supertype of B

A<:Upper>:Lower
// lower and upper bounds used together
// The type A has both an upper and lower bound

```
- Type constraints
```scala
A=:=B 
// A must be equal to B
A<:<B
// A must be subtype of B
A<%<B
// A must be viewable of B

```
- Scala standard symbols for generic type parameters
```scala

```

- Add new behavior to a closed module
```scala
def add[A](x:A,y:A)(implicit numeric:Numeric[A]):A=numeric.plus(x,y)
```
# pattern match
- Use pattern match in `try/catch`
```scala
def read_file(path:String):Optional[List[String]]={
    try{
        Some(Source.fromFile(path).getLines.toList)
    }catch{
        case e:Exception=>None
    }
}
```
- Use with `Option/Some/None`
```scala
def StringToInt(string: String): Option[Int] = {
    try {
      Some(string.toInt)
    }
    catch {
      case e: Exception => None
    }
}

val f=(s:String)=>StringToInt(s) match {
    case None=>println("error")
    case scala.Some(x)=>println(x)

}

```
- Eliminate null values from code
  There are serval common situations where you may be tempted to use *null* values
  - When a *var* field in a class or method doesn't have an initial default value,initialize it with *Option* instead of *null*
  - When a method doesn't produce the intended result,you may be tempted to return *null*.Use *Option* or *Try* instead
  - If you are working with a Java library that returns *null*,convert it to an *Option*,or something else
```scala
 class User(name: String, mail: String) {
    val firstName = None: Option[String]
    val lastName = None: Option[String]
  }
val user=new User()
println(user.firstName.getOrElse("not assigned"))


```
- Option 
      Option can be seen as a collection with zero or one element.
      - If the value is *None*, it has zero elements
      - If it is *Some*,it has one element-the value it contains
- Using the Option/Some/None pattern
    - Return an option from a method
      ```scala
      def toInt(string: String): Unit = {
          try {
            Some(Integer.parseInt(string.trim))
          }
          catch {
            case e:Exception=>None
          }
        }
      ```
    - Getting the value from an option
    ```scala
    //use *getOrElse*
    val x =toInt("ch").getOrElse(1)
    //Use forEach
    toInt("1").forEach{
        i=>println(f"got an number $i")
    }
    //Use a match expression
    toInt("1").match{
        case Some(i)=>println(i)
        case None=>println("that does not work")
    }
    ```
    - Combine the `flatMap` with `Option`
    ```scala
      List("1","2",2,"sa").flatMap(toInt).sum
      //equals to
      List("1","2",2,"sa").collect{case Some(i)=>i}
    ```
- Implicit methods to add your own methods to the **String** class
```scala
implicit class StringImprovements(s: String) {
    def increment: String = s.map(c => (c + 1).toChar)
  }
"HAL".increment
//IBM
```
- Option with RDD
```scala
val rdd:RDD[(String,Optional[Int])]
rdd.flatMapValues(l=>l):RDD[(String,Int)]
```
- Adding JAR Files and Classes to the REPL Classpath
```scala
$ scala -cp path_to_jar.jar
scala> import org.com.utils._
```
In Spark-shell,`./spark-shell --jars pathOfjarsWithCommaSeprated` or
```scala
scala> :require /path/to/file.jar
```
- None of object
```scala
val op=None:Option[Person]
//or 
val op=Option.empty[Person]

```
- Some of object
```scala
val Op=Option(1)
//Op:Option[Int]=Some(1)

case class Name(name:String)
val name=Option(Name("chunshun"))
//name:Option[Name]=Some(Name("chunshun"))
```
- Function tupled
```scala
val time="20190429"
val cut=Array(0,4,6,8)
val c=cut.dropRight(1).zip(cut.drop(1))
val Array(year,month,day)=c.map(l=>(time.slice(_,_)).tupled(l))
```
- Scala unpack Array params
```scala
def hello( names: String*) {
  println( "Hello " + names.mkString(" and " ) )
}
val names = List("john", "paul", "george", "ringo")
hello( names: _* )
// Hello john and paul and george and ringo    
```