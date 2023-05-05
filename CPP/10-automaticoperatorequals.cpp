class Cargo{
public:
    Cargo& operator=(const Cargo&){
        cout << "inside Cargo::operator=()" << endl;
        return this;
    }
};

class Truck{
    Cargo ;
}