class Subject
{
  public:
    virtual void execute() = 0;
};

class RealSubject: public Subject
{
    string str;
  public:
    RealSubject(string s)
    {
        str = s;
    }
    void execute()
    {
        cout << str << '\n';
    }
};

class ProxySubject: public Subject
{
    string first, second, third;
    RealSubject *ptr;
  public:
    ProxySubject(string s)
    {
        int num = s.find_first_of(' ');
        first = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_first_of(' ');
        second = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_first_of(' ');
        third = s.substr(0, num);
        s = s.substr(num + 1);
        ptr = new RealSubject(s);
    }
    ~ProxySubject()
    {
        delete ptr;
    }
    RealSubject *operator->()
    {
        cout << first << ' ' << second << ' ';
        return ptr;
    }
    void execute()
    {
        cout << first << ' ' << third << ' ';
        ptr->execute();
    }
};

int main()
{
  ProxySubject obj(string("the quick brown fox jumped over the dog"));
  obj->execute();
  obj.execute();
}
--------------------------------------------
interface ICar
{
    void MoveCar();
}


//the real object
class Car : ICar
{
    void ICar.MoveCar()
    {
        Console.WriteLine("Car has been driven");
    }
}

class Driver
{
    private int age;

    public int Age
    {
        get { return age; }
        set { age = value; }
    }

    public Driver(int age)
    {
        this.age = age;
    }
}
//the proxy
class ProxyCar : ICar
{
private:
    Driver* driver;
    ICar* realCar;
public:
    ProxyCar(Driver* driver)
    {
        this->driver = driver;
        realCar = new Car();
    }

    void ICar.MoveCar()
    {
        if (driver.Age <= 16)
            Console.WriteLine("Sorry the driver is too young to drive");
        else
            realCar.MoveCar();
    }
}

int main()
{
  ICar car = new ProxyCar(new Driver(16));
  car.MoveCar();

  car = new ProxyCar(new Driver(25));
  car.MoveCar();
}
