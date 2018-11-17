- data types
    - byte
    - short
    - int
    - long
    - float
    - double
    - char
    - string
    - boolean
    - string 
    - unit
        - corresponds to no value 
    - nothing
    - any
    - anyref

- variable
    - variable declaration
        - synatx
        ```scala
        val myVar:String="foo"
        ``` 
    - variable type inference
        ```scala
        val variab=10
        val varian="abc"
        ```
    - multiple assignment
        ```scala
        val (val1:Int, val2:String)=Pair(10,"aa")
        ```
- collections
    - List
    ```scala
     // List of Strings
    val fruit: List[String] = List("apples", "oranges", "pears")
    val numbers:List[Int] =List(1,2,2,4)
    ```
    - basic operations on List
        - `head`
        - `tail`
        - `isEmpty`
        ```scala
        val x=List(1,23,4)
        x.head
        x.tail
        x.isEmpty
        ``` 
        - concatenating lists
            - `::` or `List.concat`
        - creating uniform lists
            - `List.fill(length)()`
        - tabulating a function()
            - `list.tabulate`
            ```scala
            val multi=List.tabulate(4,5)(_*_)
            multi: List(List(0, 0, 0, 0, 0), List(0, 1, 2, 3, 4), 
            List(0, 2, 4, 6, 8), List(0, 3, 6, 9, 12))
            ``` 
        - reverse list
        ```scala
        x=List()
        x.reverse
        ``` 
    - Set
        - create set
            ```scala
            val st=Set(1,2,3)

            ``` 
        - Concatenating Sets
            - `++` or `Set.++`
            ```scala
            set1.++(set2)
            set1++set(2)
            ```

    - Maps
        - create maps 
            ```scala
            val colors = Map("red" -> "#FF0000", "azure" -> "#F0FFFF")
            ``` 
        - keys,values
        ```scala
        colors.keys.foreach{
            i=>print("key"+i)
        }
        ``` 
        - check the key
        ```scala
        colors.contains("red")
        ```
    - Tuples
        - init 
        ```scala
        val tup=(1,3,"a")
        ```
        - `swap`
        ```scala
        tup.swap
        ```
    - Options
    - Iterators
        - `next` or `hasnext`
    - Array
        - init 
        ```scala
        val arr=new Array[String](3)
        z(0)

        ``` 
        - processing the array
        ```scala
        def main(args: Array[String]) {
        var myList = Array(1.9, 2.9, 3.4, 3.5)
        
        // Print all the array elements
        for ( x <- myList ) {
            println( x )
        }

        // Summing all elements
        var total = 0.0;
        
        for ( i <- 0 to (myList.length - 1)) {
            total += myList(i);
        }
        println("Total is " + total);

        // Finding the largest element
        var max = myList(0);
        
        for ( i <- 1 to (myList.length - 1) ) {
            if (myList(i) > max) max = myList(i);
        }
        
        println("Max is " + max);
        }
        ``` 
    - Pattern matching
    ```scala
        object Demo {
        def main(args: Array[String]) {
            println(matchTest("two"))
            println(matchTest("test"))
            println(matchTest(1))
        }
        
        def matchTest(x: Any): Any = x match {
            case 1 => "one"
            case "two" => 2
            case y: Int => "scala.Int"
            case _ => "many"
        }
        }

    ```
    - functions
        - declare
        ```scala
        def functionName ([list of parameters]) : [return type]

        def functionName ([list of parameters]) : [return type] = {
        function body
        return [expr]
        }


        object Hello{
            def printMe( ) : Unit = {
            println("Hello, Scala!")
            }
        }
        ```
        The **Unit** in scala is equal to **void**
    - I/O
        - input
        ```scala
        val writer=new PrintWriter(newFile("test.txt"))
        writer.write("hello scala")
        writer.close()

        ``` 
        - read from the line 
        ```scala
        object Demo {
            def main(args: Array[String]) {
                print("Please enter your input : " )
                val line = Console.readLine
                
                println("Thanks, you just typed: " + line)
            }
            }
        ``` 
        - reading file content
        ```scala
        
        import scala.io.Source

        object Demo {
            def main(args: Array[String]) {
                println("Following is the content read:" )

                Source.fromFile("Demo.txt" ).foreach { 
                    print 
                }
            }
        }
        ``` 
- if the result is boolean,then the result will be predicate


```scala
val x:HashMap[Int,String]=new HashMap[Int,String]()
//equals to
val x =new HashMap[Int,String]()
//or

val x:HashMap[Int,String ]=new HashMap()

```

- scala is an oo language, which means that everything is an object,including numbers or functions.It differs from Java,
since Java distinguishes primitive types(such as boolean and int) from reference types,and does not enable one to manipulate functions as values
```scala
// numbers are objects
(1).+(2)
//functions are objects
object Timer{
    def once(callbcack:()=>Unit){
        callbcak()
    }
    def timeFlies(){
        while (true){

        println("time flies like arrows")
        Thread sleep(1000)
        }
    }
    def main(args:Array[String]){
        once(timeFlies)
    }
}

```
- anonymous functions
```scala
object Timer{
    def once(callback:()=>Unit){
        while (true){
            callback();
            Thread sleep(2000)
        }
    }
    // def timeFlies(){
        // println("time flies like arrow")
    // }
    def main(args:Array[String]){
        once(timeFlies:()=>{
            println("time flies like an arrow")
        })
    }
}


val inc=(x:Int)=>x+1
```
- classes
```scala
class Complex(real:Int,image:Int){
    def real()=real
    def img()+image
}
```
- `override `
