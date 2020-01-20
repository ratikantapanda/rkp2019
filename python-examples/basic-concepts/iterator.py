class Repeater:
    def __init__(self,value,max):
        self.value=value
        self.count=0
        self.max=max
    
    def __iter__(self):
        return self
    def __next__(self):
        if self.count > self.max :
            raise StopIteration
        self.count += 1
        return self.value
list1=Repeater("hello",10)
# print(type(list1))
for item in list1:
      print(item,end=' ')
print(list(list1))
# iter=iter(list1)
# print(next(iter))
# print(next(iter))
#print(list(list1))
#print(len(list(list1)))
