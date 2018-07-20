1. decorator:
```python
def paragraphize(inputFunction):
   def newFunction():
      return "<p>" + inputFunction() + "</p>"
   return newFunction

@paragraphize
def getText():
   return "Here is some text!"
```