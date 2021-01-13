#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <numeric>
#include <random>

class Cargo
{
public:
    virtual double getSpeed() const = 0;
    virtual double getPrice() const = 0;
    virtual const std::string &getType() const = 0;
    virtual ~Cargo() = 0;
};

class Plane : public Cargo
{
public:
    virtual double getSpeed() const override;
    virtual double getPrice() const override;
    virtual const std::string &getType() const override;
    virtual ~Plane() override;

private:
    const double speed = 900.0;
    const double price = 0.22;
    const std::string type = "Plane";
};

class Train : public Cargo
{
public:
    virtual double getSpeed() const override;
    virtual double getPrice() const override;
    virtual const std::string &getType() const override;
    virtual ~Train() override;

private:
    const double speed = 75.0;
    const double price = 0.18;
    const std::string type = "Train";
};

class Truck : public Cargo
{
public:
    virtual double getSpeed() const override;
    virtual double getPrice() const override;
    virtual const std::string &getType() const override;
    virtual ~Truck() override;

private:
    const double speed = 45.0;
    const double price = 0.12;
    const std::string type = "Truck";
};

Cargo::~Cargo() {}

double Plane::getSpeed() const
{
    return this->speed;
}

double Plane::getPrice() const
{
    return this->price;
}

const std::string &Plane::getType() const
{
    return this->type;
}

Plane::~Plane() {}

double Train::getSpeed() const
{
    return this->speed;
}

double Train::getPrice() const
{
    return this->price;
}

const std::string &Train::getType() const
{
    return this->type;
}

Train::~Train() {}

double Truck::getSpeed() const
{
    return this->speed;
}

double Truck::getPrice() const
{
    return this->price;
}

const std::string &Truck::getType() const
{
    return this->type;
}

Truck::~Truck() {}

std::ostream &operator<<(std::ostream &out, const Cargo &c)
{
    out.precision(6);
    return out << c.getType() << "{speed=" << c.getSpeed() << ", price=" << c.getPrice() << "}";
}

void printTimeAndPrice(const std::string &source, const std::string &destination, const Cargo &cargo, double distance)
{
    std::cout.precision(4);
    std::cout << "From " << source << " to " << destination << ": " << distance << "km "
              << " in " << (distance / cargo.getSpeed()) << " hours for $" << cargo.getPrice() * distance << "." << std::endl;
}

int main()
{
    std::random_device randomDevice;
    std::mt19937 engine(randomDevice());
    std::uniform_int_distribution<int> distribution(100, 1000);

    const std::unique_ptr<Cargo> plane = std::unique_ptr<Cargo>(new Plane());
    const std::unique_ptr<Cargo> train = std::unique_ptr<Cargo>(new Train());
    const std::unique_ptr<Cargo> truck = std::unique_ptr<Cargo>(new Truck());

    const double distance = distribution(engine);

    printTimeAndPrice("Tomsk", "Cleatop", *plane, distance);
    printTimeAndPrice("Moscow", "Cleatop", *train, distance);
    printTimeAndPrice("Nappa", "Cleatop", *truck, distance);

    return 0;
}