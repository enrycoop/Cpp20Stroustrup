#include <iostream>
#include <vector>

class Point{};

class Shape {
public:
    virtual Point center() const =0;
    virtual void move(Point to) =0;

    virtual void draw() const =0;
    virtual void rotate(int angle) =0;


    virtual ~Shape() {}
};

class Triangle : public Shape {
public:
    Triangle(Point p1, Point p2, Point p3) :
    p1{p1}, p2{p2}, p3{p3}
    {}
    Point center() const override { return p1; }
    void move(Point to) override { p1 = to; }
    void draw() const override {}
    void rotate(int) override {}

private:
    Point p1;
    Point p2;
    Point p3;
};

class Circle : public Shape {
public:
    Circle(Point p, int rad) :x{p}, r{rad} {}

    Point center() const override { return x; }
    void move(Point to) override { x = to; }
    void draw() const override {}
    void rotate(int) override {}
private:
    Point x;
    int r;
};

class Smiley : public Circle {
public:
    Smiley(Point p, int rad) : Circle(p, rad), mouth{nullptr} { }
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }

    void move(Point to) override;
    void draw() const override;
    void rotate(int) override;

    void add_eye(Shape* s)
    {
        eyes.push_back(s);
    }

    void set_mouth(Shape* s);
    virtual void wink(int i);

    //...
private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};

void Smiley::draw() const {
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}


void rotate_all(std::vector<Shape*>& v, int angle) {
    for (auto p : v)
        p->rotate(angle);
}


enum class Kind { circle, triangle, smiley };

Shape* read_shape(std::istream& is) {
    int i;
    is >> i;
    Kind k = static_cast<Kind>(i);

    switch (k) {
        case Kind::circle: {
            Point p{};
            int r = 0;
            return new Circle{p, r};
        }
        case Kind::triangle: {
            Point p1{}, p2{}, p3{};
            return new Triangle{p1, p2, p3};
        }
        case Kind::smiley: {
            Point p1{};
            Circle* e1, *e2;
            int r = 0;
            auto *ps = new Smiley{p1, r};
            ps->add_eye(e1);
            ps->add_eye(e2);
            return ps;
        }
    }
}

int main() {
    Shape* ps {read_shape(std::cin)};
    /*
     * Usiamo dynamic_cast su un tipo puntatore quando un puntatore a un oggetto di una classe
     * derivata diversa e un argomento valido. Poi verifichiamo se il risultato è nullptr.
     */
    if (Smiley* p = dynamic_cast<Smiley*>(ps)) {
        std::cout << "Smiley";
        delete p;
    }else {
        std::cout << "Altro";
        delete p;
    }

    return 0;
}
