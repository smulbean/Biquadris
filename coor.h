#ifndef STRUCT_H
#define STRUCT_H

// Define your structure
struct Coor {
    int x;
    int y;

    public:
        Coor(int x, int y):x{x}, y{y}{};
        ~Coor() = default;
        Coor(const Coor& other) : x{other.x}, y{other.y} {
    };
        Coor& operator=(const Coor& other) {
        if (this == &other) {
            return *this; 
        }
        x = other.x;
        y = other.y;
        return *this;
    };
    Coor(Coor&& other) noexcept : x{other.x}, y{other.y} {
        other.x = 0;
        other.y = 0;
    };

    Coor& operator=(Coor&& other) noexcept {
        if (this == &other) {
            return *this; 
        }
        x = other.x;
        y = other.y;
        other.x = 0;
        other.y = 0;
        return *this;
    };
    void setX(int newx){
        x = newx;
    }

    void setY(int newy){
        y = newy;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }
};


#endif


