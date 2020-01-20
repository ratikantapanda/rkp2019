def fun_hello():
    return 'hello'
# Generator always return an iterable list
def gen_hello():
    yield 'hello'
# def gen_hello():
#     while True:
#         yield 'hello'
def list_square(my_list):
    squares_list=[]
    for item in my_list:
        squares_list.append(item * item)
    return squares_list

def list_sqaure_generator(my_list):
    for item in my_list:
        yield item * item

if __name__ == '__main__':
    # hello_list=gen_hello()
    # print(next(hello_list))
    # print(next(hello_list))
    print(list(gen_hello()))
    list1=[1,2,3,4,5]
    # squares_list1=list_square(list1)
    # print(list1)
    # print(squares_list1)
    # square_list=list_sqaure_generator(list1)
    # print(next(square_list))
    # print(next(square_list))
    # for item in list_sqaure_generator(list1):
    #     print(item)
    # List comprehension
    list1_squares=[item * item for item in list1]
    print(list1_squares)
    # Generator expression
    list1_sqr_gen=(item * item for item in list1)
    print(list1_sqr_gen)
    # for item in list1_sqr_gen:
    #     print(item, end=' ')
    print(list(list1_sqr_gen))
    