Polymorphism    
1. Polymorphism is probably the most important feature in high level languages. It allows us to build programs according to interfaces, operate on abstractions and choose the right implementation based on types. Different languages implement it differently. Most OOP languages usually use inheritance and some kind of **run time type dispatch** or **table lookup** to get the right implementation. There is another way, which originally comes from Haskell which involves **“type classes”**.
2. Polymorphism via inheritance
```scala
// Our generic inteface
trait Shape {
  def area: Double
}

// Implementation 1
class Circle(radius: Double) extends Shape {
  override def area: Double = math.Pi * math.pow(radius, 2)
}

// Implementation 2
class Rectangle(width: Double, length: Double) extends Shape {
  override def area: Double = width * length
}

// Generic function
def areaOf(shape: Shape): Double = shape.area

// Usage
areaOf(new Circle(10))
areaOf(new Rectangle(5, 5))
```
3. Polymorphism via type classes
```scala
trait Shape[A] {
  def area(a: A): Double
}

case class Circle(radius: Double)
case class Rectangle(width: Double, length: Double)

// Here >
implicit object CircleShape extends Shape[Circle] {
  override def area(circle: Circle) : Double = math.Pi * math.pow(circle.radius, 2)
}

// And here >
implicit object RectangleShape extends Shape[Rectangle] {
  override def area(rectangle: Rectangle): Double = rectangle.width * rectangle.length
}

def areaOf[A](shape: A)(implicit shapeImpl: Shape[A]): Double = shapeImpl.area(shape)

areaOf(Circle(10))
areaOf(Rectangle(5,5))
view raw
```
